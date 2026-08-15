# M8, the new custom architecture
M8 is a custom 8-bit architecture, and this program is an assembler designed for generating a different binary format.
# Built in emulator
This project contains the compiler and the tool to execute the code. Right now, this emulator i'm talking about doesn't currently exist, because this project is made by only one developer.
# MASM example (M8 Assembler)
```
.data
label: db 8

.text
MOV AR, 8
MOV BR, 1
NOP
ADD AR, BR
```
*NOTE*: this assembly language is also case insensitive.
# Compilation
To **compile** a file, you can do this;
```
masm in.m8 out.mout
# Emulation
To **emulate** a binary file, you have to use the flag `-e`, like this:
```
masm -e binary.mout
```