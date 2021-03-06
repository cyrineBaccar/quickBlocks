/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *
 * The LICENSE at the root of this repo details your rights (if any)
 *------------------------------------------------------------------------*/
/*
 * This file was generated with makeClass. Edit only those parts of the code inside
 * of 'EXISTING_CODE' tags.
 */
#include "newblock.h"
#include "etherlib.h"

//---------------------------------------------------------------------------
IMPLEMENT_NODE(CNewBlock, CBaseNode);

//---------------------------------------------------------------------------
extern SFString nextNewblockChunk(const SFString& fieldIn, const void *dataPtr);
static SFString nextNewblockChunk_custom(const SFString& fieldIn, const void *dataPtr);

//---------------------------------------------------------------------------
void CNewBlock::Format(CExportContext& ctx, const SFString& fmtIn, void *dataPtr) const {
    if (!m_showing)
        return;

    if (fmtIn.empty()) {
        ctx << toJson();
        return;
    }

    SFString fmt = fmtIn;
    if (handleCustomFormat(ctx, fmt, dataPtr))
        return;

    while (!fmt.empty())
        ctx << getNextChunk(fmt, nextNewblockChunk, this);
}

//---------------------------------------------------------------------------
SFString nextNewblockChunk(const SFString& fieldIn, const void *dataPtr) {
    if (dataPtr)
        return ((const CNewBlock *)dataPtr)->getValueByName(fieldIn);

    // EXISTING_CODE
    // EXISTING_CODE

    return fldNotFound(fieldIn);
}

//---------------------------------------------------------------------------------------------------
bool CNewBlock::setValueByName(const SFString& fieldName, const SFString& fieldValue) {
    // EXISTING_CODE
    if (fieldName % "number") {
        *(SFString*)&fieldName = "blockNumber";

    } else if (fieldName % "transactions") {
        // Transactions come to us either as a JSON objects or lists
        // of hashes (i.e. a string array). JSON objects have 'from'
        // We handle those as normal below
        if (!fieldValue.Contains("from")) {
            SFString str = fieldValue;
            while (!str.empty()) {
                CTransaction trans;
                trans.hash = toAddress(nextTokenClear(str, ','));
                transactions[transactions.getCount()] = trans;
            }
            return true;
        }
    }
    // EXISTING_CODE

    switch (tolower(fieldName[0])) {
        case 'b':
            if ( fieldName % "blockNumber" ) { blockNumber = toUnsigned(fieldValue); return true; }
            break;
        case 'g':
            if ( fieldName % "gasLimit" ) { gasLimit = toGas(fieldValue); return true; }
            if ( fieldName % "gasUsed" ) { gasUsed = toGas(fieldValue); return true; }
            break;
        case 'h':
            if ( fieldName % "hash" ) { hash = toHash(fieldValue); return true; }
            break;
        case 'l':
            if ( fieldName % "logsBloom" ) { logsBloom = toBloom(fieldValue); return true; }
            break;
        case 'm':
            if ( fieldName % "miner" ) { miner = toAddress(fieldValue); return true; }
            break;
        case 'p':
            if ( fieldName % "parentHash" ) { parentHash = toHash(fieldValue); return true; }
            break;
        case 's':
            if ( fieldName % "size" ) { size = toUnsigned(fieldValue); return true; }
            break;
        case 't':
            if ( fieldName % "timestamp" ) { timestamp = toUnsigned(fieldValue); return true; }
            if ( fieldName % "transactions" ) {
                char *p = (char *)fieldValue.c_str();
                while (p && *p) {
                    CTransaction item;
                    uint32_t nFields = 0;
                    p = item.parseJson(p, nFields);
                    if (nFields)
                        transactions[transactions.getCount()] = item;
                }
                return true;
            }
            break;
        default:
            break;
    }
    return false;
}

//---------------------------------------------------------------------------------------------------
void CNewBlock::finishParse() {
    // EXISTING_CODE
    for (uint32_t i=0;i<transactions.getCount();i++)
        transactions[i].pBlock = (CBlock*)this;
    // EXISTING_CODE
}

//---------------------------------------------------------------------------------------------------
bool CNewBlock::Serialize(SFArchive& archive) {

    if (archive.isWriting())
        return ((const CNewBlock*)this)->SerializeC(archive);

    // If we're reading a back level, read the whole thing and we're done.
    if (readBackLevel(archive))
        return true;

    archive >> gasLimit;
    archive >> gasUsed;
    archive >> hash;
    archive >> logsBloom;
    archive >> blockNumber;
    archive >> parentHash;
    archive >> timestamp;
    archive >> transactions;
    archive >> miner;
    archive >> size;
    finishParse();
    return true;
}

//---------------------------------------------------------------------------------------------------
bool CNewBlock::SerializeC(SFArchive& archive) const {

    // Writing always write the latest version of the data
    CBaseNode::SerializeC(archive);
    archive << gasLimit;
    archive << gasUsed;
    archive << hash;
    archive << logsBloom;
    archive << blockNumber;
    archive << parentHash;
    archive << timestamp;
    archive << transactions;
    archive << miner;
    archive << size;

    return true;
}

//---------------------------------------------------------------------------
void CNewBlock::registerClass(void) {
    static bool been_here = false;
    if (been_here) return;
    been_here = true;

    uint32_t fieldNum = 1000;
    ADD_FIELD(CNewBlock, "schema",  T_NUMBER, ++fieldNum);
    ADD_FIELD(CNewBlock, "deleted", T_BOOL,  ++fieldNum);
    ADD_FIELD(CNewBlock, "showing", T_BOOL,  ++fieldNum);
    ADD_FIELD(CNewBlock, "gasLimit", T_GAS, ++fieldNum);
    ADD_FIELD(CNewBlock, "gasUsed", T_GAS, ++fieldNum);
    ADD_FIELD(CNewBlock, "hash", T_HASH, ++fieldNum);
    ADD_FIELD(CNewBlock, "logsBloom", T_BLOOM, ++fieldNum);
    ADD_FIELD(CNewBlock, "blockNumber", T_NUMBER, ++fieldNum);
    ADD_FIELD(CNewBlock, "parentHash", T_HASH, ++fieldNum);
    ADD_FIELD(CNewBlock, "timestamp", T_NUMBER, ++fieldNum);
    ADD_FIELD(CNewBlock, "transactions", T_OBJECT|TS_ARRAY, ++fieldNum);
    ADD_FIELD(CNewBlock, "miner", T_ADDRESS, ++fieldNum);
    ADD_FIELD(CNewBlock, "size", T_NUMBER, ++fieldNum);

    // Hide our internal fields, user can turn them on if they like
    HIDE_FIELD(CNewBlock, "schema");
    HIDE_FIELD(CNewBlock, "deleted");
    HIDE_FIELD(CNewBlock, "showing");

    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------
SFString nextNewblockChunk_custom(const SFString& fieldIn, const void *dataPtr) {
    const CNewBlock *newp = (const CNewBlock *)dataPtr;
    if (newp) {
        switch (tolower(fieldIn[0])) {
            // EXISTING_CODE
            case 'n':
                if ( fieldIn % "number" ) return asStringU(newp->blockNumber);
                break;
            case 't':
                if ( expContext().hashesOnly && fieldIn % "transactions" ) {
                    uint32_t cnt = newp->transactions.getCount();
                    if (!cnt) return EMPTY;
                    SFString ret;
                    for (uint32_t i = 0 ; i < cnt ; i++) {
                        ret += newp->transactions[i].hash;
                        ret += ((i < cnt-1) ? ",\n" : "\n");
                    }
                    return ret;
                }
                break;
            // EXISTING_CODE
            case 'p':
                // Display only the fields of this node, not it's parent type
                if ( fieldIn % "parsed" )
                    return nextBasenodeChunk(fieldIn, newp);
                break;

            default:
                break;
        }
    }

    return "";
}

//---------------------------------------------------------------------------
bool CNewBlock::handleCustomFormat(CExportContext& ctx, const SFString& fmtIn, void *dataPtr) const {
    // EXISTING_CODE
    // EXISTING_CODE
    return false;
}

//---------------------------------------------------------------------------
bool CNewBlock::readBackLevel(SFArchive& archive) {

    CBaseNode::readBackLevel(archive);
    bool done = false;
    // EXISTING_CODE
    if (m_schema == 501) {
        archive >> gasLimit;
        archive >> gasUsed;
        archive >> hash;
        archive >> logsBloom;
        archive >> blockNumber;
        archive >> parentHash;
        archive >> timestamp;
        archive >> transactions;
        miner = "0x0";
        size = 0x0;
        finishParse();
        done = true;
    }
    // EXISTING_CODE
    return done;
}

//---------------------------------------------------------------------------
SFArchive& operator<<(SFArchive& archive, const CNewBlock& newp) {
    newp.SerializeC(archive);
    return archive;
}

//---------------------------------------------------------------------------
SFArchive& operator>>(SFArchive& archive, CNewBlock& newp) {
    newp.Serialize(archive);
    return archive;
}

//---------------------------------------------------------------------------
SFString CNewBlock::getValueByName(const SFString& fieldName) const {

    // Give customized code a chance to override first
    SFString ret = nextNewblockChunk_custom(fieldName, this);
    if (!ret.empty())
        return ret;

    // If the class has any fields, return them
    switch (tolower(fieldName[0])) {
        case 'b':
            if ( fieldName % "blockNumber" ) return asStringU(blockNumber);
            break;
        case 'g':
            if ( fieldName % "gasLimit" ) return fromGas(gasLimit);
            if ( fieldName % "gasUsed" ) return fromGas(gasUsed);
            break;
        case 'h':
            if ( fieldName % "hash" ) return fromHash(hash);
            break;
        case 'l':
            if ( fieldName % "logsBloom" ) return fromBloom(logsBloom);
            break;
        case 'm':
            if ( fieldName % "miner" ) return fromAddress(miner);
            break;
        case 'p':
            if ( fieldName % "parentHash" ) return fromHash(parentHash);
            break;
        case 's':
            if ( fieldName % "size" ) return asStringU(size);
            break;
        case 't':
            if ( fieldName % "timestamp" ) return asStringU(timestamp);
            if ( fieldName % "transactions" ) {
                uint32_t cnt = transactions.getCount();
                if (!cnt) return "";
                SFString retS;
                for (uint32_t i = 0 ; i < cnt ; i++) {
                    retS += transactions[i].Format();
                    retS += ((i < cnt - 1) ? ",\n" : "\n");
                }
                return retS;
            }
            break;
    }

    // EXISTING_CODE
    // EXISTING_CODE

    // Finally, give the parent class a chance
    return CBaseNode::getValueByName(fieldName);
}

//-------------------------------------------------------------------------
ostream& operator<<(ostream& os, const CNewBlock& item) {
    // EXISTING_CODE
    // EXISTING_CODE

    os << item.Format() << "\n";
    return os;
}

//---------------------------------------------------------------------------
// EXISTING_CODE
CNewBlock::CNewBlock(const CBlock& block) {
    gasLimit = block.gasLimit;
    gasUsed = block.gasUsed;
    hash = block.hash;
    logsBloom = block.logsBloom;
    blockNumber = block.blockNumber;
    parentHash = block.parentHash;
    timestamp = (SFUint32)block.timestamp;
    transactions = block.transactions;
    miner = "0x0";
    size = 0;
}

//-----------------------------------------------------------------------
bool readOneNewBlock_fromBinary(CNewBlock& block, const SFString& fileName) {
    block = CNewBlock(); // reset
    SFArchive archive(READING_ARCHIVE);
    if (archive.Lock(fileName, binaryReadOnly, LOCK_NOWAIT))
    {
        block.Serialize(archive);
        archive.Close();
        return block.blockNumber;
    }
    return false;
}

//-----------------------------------------------------------------------
bool readOneNewBlock_fromJson(CNewBlock& block, const SFString& fileName) {
    block = CNewBlock(); // reset
    SFString contents = asciiFileToString(fileName);
    if (contents.Contains("null")) {
        contents.ReplaceAll("null", "\"0x\"");
        stringToAsciiFile(fileName, contents);
    }

    if (!contents.endsWith('\n')) {
        stringToAsciiFile(fileName, contents+"\n");
    }

    char *p = cleanUpJson((char *)(const char*)contents);
    uint32_t nFields=0;
    block.parseJson(p,nFields);
    return nFields;
}
// EXISTING_CODE

