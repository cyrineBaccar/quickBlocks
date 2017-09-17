#pragma once
/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *
 * The LICENSE at the root of this repo details your rights (if any)
 *------------------------------------------------------------------------*/

//-------------------------------------------------------------------------
#include <ctype.h>
#include <curl/curl.h>
#include <glob.h>
#include <inttypes.h>
#include <libgen.h>
#include <limits.h>
#include <math.h>
#include <pwd.h>
#include <signal.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <utime.h>
#include <string.h>
#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

//-------------------------------------------------------------------------
using namespace std;  // NOLINT

//-------------------------------------------------------------------------
using SFUint32 = uint64_t;

//-------------------------------------------------------------------------
#ifdef _DEBUG
#define ASSERT(a) { if (!(a)) { cout << "error at " << __FILE__ << "(" << __LINE__ << ")\n"; } }
#else
#define ASSERT(a)
#endif

//-------------------------------------------------------------------------
#include "sfstring.h"
#include "list.h"
#include "testing.h"
