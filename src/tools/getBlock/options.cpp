/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *
 * The LICENSE at the root of this repo details your rights (if any)
 *------------------------------------------------------------------------*/
#include "options.h"

//---------------------------------------------------------------------------------------------------
CParams params[] = {
    CParams("~num",              "which block (or blocks if more than one) to retreive (or use [start-stop) for range)"),
    CParams("-chec(k)",          "pull block(s) using both cache and raw, compare results, report differences (should be none)"),
    CParams("-source:[c|r]",     "either :(c)ache or :(r)aw, source for data retrival. (shortcuts -c = qblocks, -r = node)"),
    CParams("-fields:[a|m|c|r]", "either :(a)ll, (m)ini, (c)ache or :(r)aw; which fields to include in output (all is default)"),
    CParams("-parity",           "mimic parity output using quickBlocks (i.e. quoted hexidecimal for numbers)"),
    CParams("-terse",            "if source is raw, retreive transaction hashes instead of full transactions"),
    CParams("-quiet",            "do not print results to screen, used for speed testing and data checking"),
    CParams("@re(c)iept",        "include receipt (hidden)"),
    CParams("@f(o)rce",          "force re-write of binary data"),
    CParams("@normalize",        "normalize (remove un-common fields and sort) for comparison with other results (testing)"),
    CParams("@silent",           "no output - useful for performance testing"),
    CParams("",                  "Returns block(s) from local cache (the default) or directly from a running node.\n"),
};
uint32_t nParams = sizeof(params) / sizeof(CParams);

//---------------------------------------------------------------------------------------------------
bool COptions::parseArguments(SFString& command) {

    if (!standardOptions(command))
        return false;

    Init();
    while (!command.empty()) {

        SFString arg = nextTokenClear(command, ' ');

        // shortcuts
        if (arg == "-r") { arg = "--source:raw";   }
        if (arg == "-c") { arg = "--source:cache"; }

        // do not collapse
        if (arg == "-k" || arg == "--check") {
            setenv("TEST_MODE", "true", true);
            isCheck = true;
            quiet++; // if both --check and --quiet are present, be very quiet...
            expContext().spcs = 4;
            expContext().hexNums = true;
            expContext().quoteNums = true;
            CRuntimeClass *pClass = GETRUNTIME_CLASS(CBlock);
            if (pClass) {
                CFieldData *pField = pClass->FindField("blockNumber");
                if (pField)
                    pField->setName("number");
            }
            pClass = GETRUNTIME_CLASS(CBlock);
            if (pClass) {
                CFieldData *pField = pClass->FindField("hash");
                if (pField)
                    pField->setName("blockHash");
            }
            GETRUNTIME_CLASS(CBlock)->sortFieldList();
            GETRUNTIME_CLASS(CTransaction)->sortFieldList();
            GETRUNTIME_CLASS(CReceipt)->sortFieldList();

        } else if (arg == "-o" || arg == "--force") {
            etherlib_init("binary");
            force = true;

        } else if (arg == "--normalize") {
            normalize = true;

        } else if (arg == "--silent") {
            silent = true;

        } else if (arg.startsWith("-s:") || arg.startsWith("--source:")) {
            SFString mode = arg.Substitute("-s:","").Substitute("--source:","");
            if (mode == "r" || mode == "raw") {
                isRaw = true;

            } else if (mode == "c" || mode == "cache") {
                etherlib_init("binaryOnly");
                asks4Cache = true;

            } else {
                return usage("Invalide source. Must be either '(r)aw' or '(c)ache'. Quitting...");
            }

        } else if (arg == "-t" || arg == "--terse") {
            terse = true;

        } else if (arg == "-q" || arg == "--quiet") {
            quiet++; // if both --check and --quiet are present, be very quiet...

        } else if (arg.startsWith("-f:") || arg.startsWith("--fields:")) {
            SFString mode = arg.Substitute("-f:","").Substitute("--fields:","");

            if (mode == "a" || mode == "all") {
                SHOW_ALL_FIELDS(CBlock);
                SHOW_ALL_FIELDS(CTransaction);
                SHOW_ALL_FIELDS(CReceipt);

            } else if (mode == "m" || mode == "mini") {
                HIDE_ALL_FIELDS(CBlock);
                HIDE_ALL_FIELDS(CTransaction);
                HIDE_ALL_FIELDS(CReceipt);
                UNHIDE_FIELD(CBlock, "blockNumber");
                UNHIDE_FIELD(CBlock, "timestamp");
                UNHIDE_FIELD(CBlock, "transactions");
                UNHIDE_FIELD(CTransaction, "receipt");
                UNHIDE_FIELD(CTransaction, "transactionIndex");
                UNHIDE_FIELD(CTransaction, "gasPrice");
                UNHIDE_FIELD(CTransaction, "gas");
                UNHIDE_FIELD(CTransaction, "isError");
                UNHIDE_FIELD(CTransaction, "from");
                UNHIDE_FIELD(CTransaction, "to");
                UNHIDE_FIELD(CTransaction, "value");
                UNHIDE_FIELD(CReceipt, "gasUsed");

            } else if (mode == "r" || mode == "raw") {
            } else if (mode == "c" || mode == "cache") {
                SHOW_ALL_FIELDS(CBlock);
                SHOW_ALL_FIELDS(CTransaction);
                SHOW_ALL_FIELDS(CReceipt);
                UNHIDE_FIELD(CBlock, "blockNumber");
                UNHIDE_FIELD(CBlock, "timestamp");
                UNHIDE_FIELD(CBlock, "transactions");
                UNHIDE_FIELD(CTransaction, "receipt");
                UNHIDE_FIELD(CTransaction, "transactionIndex");
                UNHIDE_FIELD(CTransaction, "gasPrice");
                UNHIDE_FIELD(CTransaction, "gas");
                UNHIDE_FIELD(CTransaction, "isError");
                UNHIDE_FIELD(CTransaction, "from");
                UNHIDE_FIELD(CTransaction, "to");
                UNHIDE_FIELD(CTransaction, "value");
                UNHIDE_FIELD(CReceipt, "gasUsed");
            }

        } else if (arg == "-p" || arg == "--parity") {
            expContext().spcs = 4;
            expContext().hexNums = true;
            expContext().quoteNums = true;
            GETRUNTIME_CLASS(CBlock)->sortFieldList();
            GETRUNTIME_CLASS(CTransaction)->sortFieldList();
            GETRUNTIME_CLASS(CReceipt)->sortFieldList();

        } else if (arg.startsWith('-')) {  // do not collapse

            if (!builtInCmd(arg)) {
                return usage("Invalid option: " + arg);
            }

        } else {

            if (arg == "latest") {
                SFUint32 cache, client;
                getLatestBlocks(cache, client);
                cout << "\n\tFrom client: " << asYellow(client)
                        << " inCache: " << asYellow(cache)
                        << " Behind (maybe empty): " << asYellow(client-cache) << "\n\n";
                exit(0);

            } else if (arg.Contains("-")) {

                SFString arg1 = nextTokenClear(arg, '-');
                if (arg1 == "latest")
                    return usage("Cannot start range with 'latest'");

                start = toUnsigned(arg1);
                stop  = toUnsigned(arg);
                if (arg == "latest")
                    stop = getLatestBlockFromClient();
                if (stop <= start)
                    return usage("'stop' must be strictly larger than 'start'");
                isRange = true;

            } else {
                SFUint32 num = toUnsigned(arg);
                if (arg == "latest")
                    num = getLatestBlockFromClient();
                if (nNums < MAX_NUMS)
                    nums[nNums++] = num;
                else
                    return usage("Too many blocks in list. Max is " + asString(MAX_NUMS));
            }
        }
    }

    if (isRange) nNums = 0;  // if range is supplied, use the range
    else if (nNums == 0) nNums = 1;  // otherwise, if not list, use 'latest'

    if (terse && !isRaw)
        return usage("--terse options work only with --source:raw. Quitting...");

    return true;
}

//---------------------------------------------------------------------------------------------------
void COptions::Init(void) {
    paramsPtr  = params;
    nParamsRef = nParams;

    // Mimics python -m json.tool indenting.
    expContext().spcs = 4;
    expContext().hexNums = false;
    expContext().quoteNums = false;

    isCheck    = false;
    isRaw      = false;
    isRange    = false;
    terse      = false;
    force      = false;
    normalize  = false;
    silent     = false;
    asks4Cache = false;
    quiet      = 0; // quiet has levels
    nums[0]    = NOPOS;
    nNums      = 0;  // we will set this to '1' later if user supplies no values
    start = stop = 0;
}

//---------------------------------------------------------------------------------------------------
COptions::COptions(void) {
    useVerbose = true;
    Init();
}

//--------------------------------------------------------------------------------
COptions::~COptions(void) {
}

//--------------------------------------------------------------------------------
bool COptions::isMulti(void) const {
    if (isRange)
        return (stop - start) > 1;
    return nNums > 1;
}
