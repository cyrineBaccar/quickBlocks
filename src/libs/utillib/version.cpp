/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *
 * The LICENSE at the root of this repo details your rights (if any)
 *------------------------------------------------------------------------*/
#include "basetypes.h"
#include "version.h"

namespace qblocks {

#define MAJOR 0
#define MINOR 2
#define BUILD 0
#define SUBVERS "alpha"
    //--------------------------------------------------------------------------------
    uint32_t getVersionNum(void) {
#if 0
        return ((MAJOR * 1000000) + (MINOR * 1000) + (BUILD));
#else
        return 0x00000201;
#endif
    }

    //--------------------------------------------------------------------------------
    SFString getVersionStr(const SFString& sep1, const SFString& sep2) {
        return asStringU(MAJOR) + sep1 + asStringU(MINOR) + sep1 + asStringU(BUILD) + sep2 + SUBVERS;
    }

}  // namespace qblocks
