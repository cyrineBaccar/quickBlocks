## bigIntTest

Testing only

#### Usage

`Usage:`    bigIntTest [-v|-h]  
`Where:`  

| Option | Full Command | Description |
| -------: | :------- | :------- |
| -v | --verbose | set verbose level. Either -v, --verbose or -v:n where 'n' is level |
| -h | --help | display this help screen |

Test 0: 0 expected: 0 ✓
Test 1: 535 expected: 535 ✓
Test 2: 3141592653589793238462643383279 expected: 3141592653589793238462643383279 ✓
Test 3: 19900000000000000000 expected: 19900000000000000000 ✓
Test 4: 314424 expected: 314424 ✓
Test 5: 313894 expected: 313894 ✓
Test 6: 83252135 expected: 83252135 ✓
Test 7: 1185 expected: 1185 ✓
Test 8: 134 expected: 134 ✓
Test 9: 255 expected: 255 ✓
Test 10: 4278255615 expected: 4278255615 ✓
Test 11: 4278255360 expected: 4278255360 ✓
Test 12: 137436856320 expected: 137436856320 ✓
Test 13: 63 expected: 63 ✓
Test 14: 1 expected: 1 ✓
Test 15: 314 expected: 314 ✓
Test 16: 98596 expected: 98596 ✓
Test 17: 30959144 expected: 30959144 ✓
Test 18: 9721171216 expected: 9721171216 ✓
Test 19: 3052447761824 expected: 3052447761824 ✓
Test 20: 958468597212736 expected: 958468597212736 ✓
Test 21: 300959139524799104 expected: 300959139524799104 ✓
Test 22: 94501169810786918656 expected: 94501169810786918656 ✓
Test 23: 29673367320587092457984 expected: 29673367320587092457984 ✓
Test 24: 9317437338664347031806976 expected: 9317437338664347031806976 ✓
Test 25: 12 expected: 12 ✓
Test 26: 8 expected: 8 ✓
Test 27: 1931 expected: 1931 ✓
Test 28: 0 expected: 0 ✓
Test 29: 1 expected: 1 ✓
Test 30: 10 expected: 10 ✓
Test 31: 0 expected: 0 ✓
Test 32: 0 expected: 0 ✓
Test 33: 73786976294838206467 expected: 17179869187 X
Test 34: 73786976294838206467 expected: -7179869187 X
Test 35: 73786976294838206467 expected: error X
Test 36: 73786976294838206467 expected: 17179869187 X
Test 37: -73786976294838206467 expected: -17179869187 X
Test 38: errorSFIntBN::SFIntBN(const uint64_t *, unsigned int, int): Cannot use a sign of zero with a nonzero magnitude expected: error ✓
Test 39: 73786976294838206467 expected: 17179869187 X
Test 40: -73786976294838206467 expected: -17179869187 X
Test 41: errorSFIntBN::SFIntBN(const SFUintBN &, int): Cannot use a sign of zero with a nonzero magnitude expected: error ✓
Test 42: 0 expected: 0 ✓
Test 43: 0 expected: 0 ✓
Test 44: 0 expected: 0 ✓
Test 45: 0 expected: 0 ✓
Test 46: 4294967295 expected: 4294967295 ✓
Test 47: 4294967296 expected: error X
Test 48: 0 expected: 0 ✓
Test 49: 2147483647 expected: 2147483647 ✓
Test 50: 2147483648 expected: error X
Test 51: 0 expected: 0 ✓
Test 52: 4294967295 expected: 4294967295 ✓
Test 53: errorSFUintBN::to<Primitive>: Value is too big to fit in the requested type expected: error ✓
Test 54: 0 expected: 0 ✓
Test 55: 2147483647 expected: 2147483647 ✓
Test 56: errorSFUintBN::to<Primitive>: Value is too big to fit in the requested type expected: error ✓
Test 57: 0 expected: 0 ✓
Test 58: 65535 expected: 65535 ✓
Test 59: errorSFUintBN::to<Primitive>: Value is too big to fit in the requested type expected: error ✓
Test 60: 0 expected: 0 ✓
Test 61: 32767 expected: 32767 ✓
Test 62: errorSFUintBN::to<Primitive>: Value is too big to fit in the requested type expected: error ✓
Test 63: errorSFIntBN::to<Primitive>: Cannot convert a negative integer to an unsigned type expected: error ✓
Test 64: 0 expected: 0 ✓
Test 65: 4294967295 expected: 4294967295 ✓
Test 66: 4294967296 expected: error X
Test 67: -2147483649 expected: error X
Test 68: -2147483648 expected: -2147483648 ✓
Test 69: -2147483647 expected: -2147483647 ✓
Test 70: 0 expected: 0 ✓
Test 71: 2147483647 expected: 2147483647 ✓
Test 72: 2147483648 expected: error X
Test 73: errorSFIntBN::to<Primitive>: Cannot convert a negative integer to an unsigned type expected: error ✓
Test 74: 0 expected: 0 ✓
Test 75: 4294967295 expected: 4294967295 ✓
Test 76: errorSFUintBN::to<Primitive>: Value is too big to fit in the requested type expected: error ✓
Test 77: errorSFIntBN::to<Primitive>: Value is too big to fit in the requested type expected: error ✓
Test 78: errorSFIntBN::to<Primitive>: Value is too big to fit in the requested type expected: -2147483648 X
Test 79: -2147483647 expected: -2147483647 ✓
Test 80: 0 expected: 0 ✓
Test 81: 2147483647 expected: 2147483647 ✓
Test 82: errorSFIntBN::to<Primitive>: Value is too big to fit in the requested type expected: error ✓
Test 83: errorSFIntBN::to<Primitive>: Cannot convert a negative integer to an unsigned type expected: error ✓
Test 84: 0 expected: 0 ✓
Test 85: 65535 expected: 65535 ✓
Test 86: errorSFUintBN::to<Primitive>: Value is too big to fit in the requested type expected: error ✓
Test 87: errorSFIntBN::to<Primitive>: Value is too big to fit in the requested type expected: error ✓
Test 88: -32768 expected: -32768 ✓
Test 89: -32767 expected: -32767 ✓
Test 90: 0 expected: 0 ✓
Test 91: 32767 expected: 32767 ✓
Test 92: errorSFIntBN::to<Primitive>: Value is too big to fit in the requested type expected: error ✓
Test 93: errorCannot convert from negative number. expected: error ✓
Test 94: errorCannot convert from negative number. expected: error ✓
Test 95: errorCannot convert from negative number. expected: error ✓
Test 96: errorCannot convert from negative number. expected: error ✓
Test 97: errorCannot convert from negative number. expected: error ✓
Test 98: errorCannot convert from negative number. expected: error ✓
Test 99: errorSFUintBN::subtract: Negative result in unsigned calculation expected: error ✓
Test 100: errorSFUintBN::subtract: Negative result in unsigned calculation expected: error ✓
Test 101: 0 expected: 0 ✓
Test 102: errorSFUintBN::subtract: Negative result in unsigned calculation expected: 0 X
Test 103: 4294967295 expected: 4294967295 ✓
Test 104: 0 expected: 0 ✓
Test 105: 1 expected: 1 ✓
Test 106: 12884901889 expected: 12884901889 ✓
Test 107: 4294967296 expected: 4294967296 ✓
Test 108: 1 expected: 1 ✓
Test 109: 0 expected: 0 ✓
Test 110: 1 expected: 1 ✓
Test 111: 8589934591 expected: 8589934591 ✓
Test 112: 4294967295 expected: 4294967295 ✓
Test 113: 112776680263877595 expected: 112776680263877595 ✓
Test 114: 916883579381118 expected: 916883579381118 ✓
Test 115: 81 expected: 81 ✓
Test 116: errorSFUintBN::operator /: division by zero expected: error ✓
Test 117: 0 expected: 0 ✓
Test 118: 0 expected: 0 ✓
Test 119: 5792277639144799207424 expected: 1348619730944 X
Test 120: 2 expected: 2 ✓
Test 121: 0 expected: 0 ✓
Test 122: 314 expected: 314 ✓
Test 123: 0 expected: 0 ✓
Test 124: 314 expected: 314 ✓
Test 125: 159 expected: 159 ✓
Test 126: 3 expected: 3 ✓
Test 127: 0 expected: 0 ✓
Test 128: 0 expected: 0 ✓
Test 129: 0 expected: 0 ✓
Test 130: 0 expected: 0 ✓
Test 131: 1 expected: 1 ✓
Test 132: 12 expected: 12 ✓
Test 133: 13 expected: 13 ✓
Test 134: 33 expected: 33 ✓
Test 135: 1 expected: 1 ✓
Test 136: 1 expected: 1 ✓
Test 137: 0 expected: 0 ✓
Test 138: 0 expected: 0 ✓
Test 139: 1 expected: 1 ✓
Test 140: 5 expected: 5 ✓
Test 141: 4294967321 expected: 4294967321 ✓
Test 142: 4294967321 expected: 2147483673 X
Test 143: 15 expected: 15 ✓
Test 144: -15 expected: -15 ✓
Test 145: 0 expected: 2 X
Test 146: 1 expected: 0 X
Test 147: -1 expected: -1 ✓
Test 148: 12 expected: 12 ✓
Test 149: 3 expected: 3 ✓
Test 150: 25 expected: 25 ✓
Test 151: 15 expected: 15 ✓
Test 152: 4 expected: 4 ✓
Test 153: 1 expected: 1 ✓
Test 154: 57896044618658097711785492504343953926634992332820282019728792003956564819968 expected: 57896044618658097711785492504343953926634992332820282019728792003956564819968 ✓
Test 155: 4 expected: 4 ✓
Test 156: 8 expected: 8 ✓
Test 157: 16 expected: 16 ✓
Test 158: 12 expected: 12 ✓
Test 159: 23 expected: 23 ✓
Test 160: 0 expected: 0 ✓
Test 161: -12 expected: -12 ✓
Test 162: 4 expected: 4 ✓
Test 163: 7 expected: 7 ✓
Test 164: 1000000000000000000 expected: 1000000000000000000 ✓
Test 165: 1000000000000000000 expected: 1000000000000000000 ✓
#### Other Options

All **quickBlocks** command-line tools support the following commands (although in some case, they have no meaning):

    Command     |     Description
    -----------------------------------------------------------------------------
    --version   |   display the current version of the tool
    --nocolors  |   turn off colored display
    --wei       |   specify value in wei (the default)
    --ether     |   specify value in ether
    --dollars   |   specify value in US dollars
    --file:fn   |   specify multiple sets of command line options in a file.

<small>*For the `--file:fn` option, place a series of valid command lines in a file and use the above options. In some cases, this option may significantly improve performance. A semi-colon at the start of a line makes that line a comment.*</small>

**Powered by QuickBlocks<sup>&reg;</sup>**


