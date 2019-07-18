# MIPS-Decoder
Read in and decode a file of MIPS machine code instructions. Output the instruction opcode, registers, immediate value, etc.


# Problem Statement
The basic instructions of MIPS (the Core Instruction Set) can be converted to machine
code. For example, the MIPS instruction add $s3, $s3, $s0 can be interpreted as
0x0040006c. The goal of this project is to read a file of MIPS commands written in
machine code, and then to extract from the machine code:
  1) the opcode,
  2) func (if there is one),
  3) MIPS inst (eg lw),
  4) the instruction format (R or I instructions only; J format need not be considered),
  5) the corresponding values of rd, rs, rt, and shamt, and finally,
  6) the signed Immediate value (for I format instructions)

## Input/Output
The input will be a file (hexInstructions.txt) with lines of MIPS instructions. Each instruction will be placed
on its own line. Sample file input:
  24020004
  3c011001
  34240000
  0040a020
  00408820

Output is saved to a csv file (hexOutput.csv) for formatting purposes.
