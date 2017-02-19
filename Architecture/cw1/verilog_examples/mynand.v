module mynand(y, a, b);
    output y;
    input a, b;
    wire d;

    and myand(d, a, b);
    not n(y, d);
endmodule
