/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *
 * The LICENSE at the root of this repo details your rights (if any)
 *------------------------------------------------------------------------*/
#include "etherlib.h"
#include "options.h"

//--------------------------------------------------------------
int main(int argc, const char *argv[]) {

    etherlib_init("");

    COptions opt;
    opt.parseArguments(argc, argv);

    forEveryBlock ( displayBloom, &opt, opt.start, opt.nBlocks, opt.skip );

    return 0;
}

//-------------------------------------------------------------
bool displayBloom(CBlock& block, void *data)
{
    COptions *opt = (COptions *)data;

    cout << block.blockNumber;
    if (opt->display) {
        SFString s = fromBloom(block.logsBloom);
        s.ReplaceAny(     "0", " ");
        s.ReplaceAny(  "1248", ".");
        s.ReplaceAny("3569ac", "+");
        s.ReplaceAny(  "7bde", yBox);
        s.ReplaceAny(  "7bde", rBox);
        cout << ": " << s;
    }
    cout << (opt->display ? "\n" : "\r");
    cout.flush();

    return true;
}
