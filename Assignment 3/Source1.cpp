/*
                                            // mandatory:
  l.d   f2,4(r1)                            // test program to be
  l.d   f4,8(r3)                            // simulated;
  mul.d f6,f2,f4                            // straight-line code;
  add.d f8,f4,f6                            // no pipelining
  s.d   f6,8(r3)
  s.d   f8,4(r5)

*/

#include <iostream>  // for std::cout

int main() {
    // all submissions _must_ contain this prelude or equivalent

    int Reg[10];                              // register file
    Reg[1] = 100; Reg[3] = 200; Reg[5] = 300; // r-register values

    int  Mem[400];                            // main memory
    char XMem[] = "llmass";                   // six opcodes in XMem
    Mem[0] = 124; Mem[1] = 348; Mem[2] = 246; // six argument lists
    Mem[3] = 468; Mem[4] = 368; Mem[5] = 584; // in main memory
    Mem[104] = 17; Mem[208] = 41;             // memory data values

    // loop over instructions
    for (int PC = 0; PC < 6; PC++) {         // fetch-execute cycle

      // f-box
        char head = XMem[PC];
        int  tail = Mem[PC];
        std::cout << "f: Fetched " << head << "#" << tail << ".\n";

        // d-box
        char opc = head;                        // decompose instruction
        std::cout << "d: Set opc to '" << opc << "'.\n";
        int arg3 = tail % 10;                   // into its opcode and
        tail = tail / 10;                       // its three arguments
        int arg2 = tail % 10;                   // inst = {opc,arg1,...}
        tail = tail / 10;
        int arg1 = tail;

        // all code or equivalent above this line is mandatory

        int D_Out1 = Reg[arg1];                 // You may imitate this style.
        std::cout << "d: Set D_Out1 to " << D_Out1 << ".\n";
        int D_Out2, dest, value_to_store;
        switch (opc) {
        case 'a':
        case 'm':
            D_Out2 = Reg[arg2];
            std::cout << "d: Set D_Out2 to " << D_Out2 << ".\n";
            dest = arg3;
            std::cout << "d: Set dest to f" << dest << ".\n";
            break;
            ...
        }

        // x-box
        int X_Out;
        switch (opc) {
            ...
        }

        // m-box
        int M_Out;
        switch (opc) {
            ...
        }

        // w-box
        switch (opc) {
            ...
        }

        std::cout << "\n";
    }                                         // end 'for' loop
}
/*

f: Fetched l#124.
d: Set opc to 'l'.
d: Set D_Out1 to 100.
d: Set D_Out2 to 4.
d: Set dest to f2.
x: Set X_Out to 104.
m: Set M_Out to 17.
w: Set f2 to 17.

...

*/
