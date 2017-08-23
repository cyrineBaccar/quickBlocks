getBlock argc: 2 [1:-th] 
getBlock -th 
#### Usage

`Usage:`    getBlock [-s|-f|-p|-r|-t|-q|-v|-h] num  
`Purpose:`  Returns block(s) from local cache (the default) or directly from a running node.
             
`Where:`  

| Option | Full Command | Description |
| -------: | :------- | :------- |
|  | num | which block (or blocks if more than one) to retreive (or use [start-stop) for range) |
| -s | --source val | either :(c)ache or :(r)aw, source for data retrival. (shortcuts -c = qblocks, -r = node) |
| -f | --fields val | either :(a)ll, (m)ini, (c)ache or :(r)aw; which fields to include in output (all is default) |
| -p | --parity | mimic parity output using quickBlocks (i.e. quoted hexidecimal for numbers) |
| -r | --reciept |  |
| -t | --terse | retreive transaction hashes instead of full transactions |
| -q | --quiet | do not print results to screen, used for speed testing |
| -v | --verbose | set verbose level. Either -v, --verbose or -v:n where 'n' is level |
| -h | --help | display this help screen |
