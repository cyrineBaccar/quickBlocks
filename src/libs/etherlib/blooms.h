#pragma once
/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *
 * The LICENSE at the root of this repo details your rights (if any)
 *------------------------------------------------------------------------*/

#include "etherlib.h"
#include "node.h"

namespace qblocks {

    //-------------------------------------------------------------------------
    // Helps debug a bloom filter
#define dbgBloom(a) fromBloom(a).Substitute("0"," ")

    //-------------------------------------------------------------------------
    inline SFUintBN makeBloom(const SFString& hexIn) {
extern SFString getSha3(const SFString& hexIn);
        SFString sha = getSha3(hexIn);
        SFUintBN bloom;
        for (uint32_t i=0;i<3;i++)
            bloom |= (SFUintBN(1) << (strtoul((const char*)"0x"+sha.substr(2+(i*4),4),NULL,16))%2048);
        return bloom;
    }

    //-------------------------------------------------------------------------
    inline SFBloom joinBloom(const SFBloom& b1, const SFBloom& b2) {
        return (b1 | b2);
    }

    //-------------------------------------------------------------------------
    inline bool isBloomHit(const SFUintBN& test, const SFUintBN filter)
    {
        return ((test & filter) == test);
    }

    //-------------------------------------------------------------------------
    inline bool isBloomHit(const SFString& hexIn, const SFUintBN filter)
    {
        return isBloomHit(makeBloom(hexIn),filter);
    }

    //----------------------------------------------------------------------------------
    extern SFBloom readOneBloom(blknum_t bn);
    extern void    writeOneBloom(const SFString& fileName, const SFBloom& bloom);
    
}  // namespace qblocks
