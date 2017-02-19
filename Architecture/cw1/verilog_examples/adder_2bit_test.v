module adder_2bit_test;
    reg a0, a1, b0, b1;
    wire o0, o1, c;

    integer i;

    adder_2bit a(o0, o1, c, a0, a1, b0, b1);

/*
    initial begin
        a0 = 0;
        a1 = 0;
        b0 = 0;
        b1 = 0;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 0;
        a1 = 0;
        b0 = 0;
        b1 = 1;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 0;
        a1 = 0;
        b0 = 1;
        b1 = 0;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 0;
        a1 = 0;
        b0 = 1;
        b1 = 1;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 0;
        a1 = 1;
        b0 = 0;
        b1 = 0;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 0;
        a1 = 1;
        b0 = 0;
        b1 = 1;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 0;
        a1 = 1;
        b0 = 1;
        b1 = 0;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 0;
        a1 = 1;
        b0 = 1;
        b1 = 1;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 1;
        a1 = 0;
        b0 = 0;
        b1 = 0;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 1;
        a1 = 0;
        b0 = 0;
        b1 = 1;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 1;
        a1 = 0;
        b0 = 1;
        b1 = 0;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 1;
        a1 = 0;
        b0 = 1;
        b1 = 1;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 1;
        a1 = 1;
        b0 = 0;
        b1 = 0;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 1;
        a1 = 1;
        b0 = 0;
        b1 = 1;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 1;
        a1 = 1;
        b0 = 1;
        b1 = 0;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        a0 = 1;
        a1 = 1;
        b0 = 1;
        b1 = 1;
        #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
    end
*/

    initial begin
        for (i = 0; i != 16; i = i + 1) begin
            a0 = i & 1;
            a1 = (i >> 1) & 1;
            b0 = (i >> 2) & 1;
            b1 = (i >> 3) & 1;
            #1 $display("%b%b + %b%b = %b%b (%b)", a1, a0, b1, b0, o1, o0, c);
        end
    end
endmodule
