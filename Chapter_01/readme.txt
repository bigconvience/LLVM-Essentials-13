Converting c code to LLVM IR

testcode is in add.c:
$ cat add.c


Use the clang frontend with the following options to convert it to LLVM IR:

$ clang -emit-llvm -c -S add.c


*************************************************************************

Using LLVM tools
LLVM assembler

$ llvm-as add.ll –o add.bc

To view the content of this bit code file a tool like hexdump can be used.

$ hexdump –c add.bc

LLVM disassembler:
$ llvm-dis add.bc –o add.ll


LLVM linker:

Convert the C source code to LLVM IR using the following command.
$ clang -emit-llvm -c main.c

Now link main.bc and add.bc to generate output.bc

$ llvm-link main.bc add.bc -o output.bc

LLVM interpreter:

$ lli output.bc


LLVM static compiler:

$ llc output.bc –o output.s

View assembly:

$ cat output.s
