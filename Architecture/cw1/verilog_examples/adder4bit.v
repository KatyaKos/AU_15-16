module adder2bit(o0, o1, c, a0, a1, b0, b1);
    input a0, a1, b0, b1;
    output o0, o1, c;

    supply0 gnd;
    wire c0;

    full_adder fa1(o0, c0, a0, b0, gnd);
    full_adder fa2(o1, c, a1, b1, c0);
endmodule
