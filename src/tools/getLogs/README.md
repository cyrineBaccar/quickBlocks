## getLogs

`getLogs` returns a transaction's logs (also called generated events).

#### Usage

`Usage:`    getLogs [-f|-a|-v|-h] < hash | bn.transID | bh.transID | address >
            -- note: This tool is incomplete.
  
`Purpose:`  Retrieve logs from an Ethereum transaction using either QuickBlocks or a running node.
            --note: 'hash' and 'blockHash' must start with '0x'.  
`Where:`  

| Option | Full Command | Description |
| -------: | :------- | :------- |
|  | hash | one or more hashes of Ethereum transactions, or |
|  | bn.transID | blockNumber.transactionID of one or more Ethereum transactions, or |
|  | bh.transID | blockHash.transactionID of one or more Ethereum transactions, or |
|  | address | if --address, then an Ethereum address |
| -f | --fromNode | retrieve the transaction from the running node (from QuickBlocks otherwise) |
| -a | --address | retrieve all logs (from node) given a list of one or more Ethereum addresses |
| -v | --verbose | set verbose level. Either -v, --verbose or -v:n where 'n' is level |
| -h | --help | display this help screen |

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


