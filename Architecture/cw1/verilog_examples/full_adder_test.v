module full_adder_test;
    reg a, b, c;
    wire sum, carry;

    full_adder ad(sum, carry, a, b, c);

    initial begin
        a = 0;
        b = 0;
        c = 0;
        #1 $display("%b + %b + %b = %b (%b)", a, b, c, sum, carry);
        a = 0;
        b = 0;
        c = 1;
        #1 $display("%b + %b + %b = %b (%b)", a, b, c, sum, carry);
        a = 0;
        b = 1;
        c = 0;
        #1 $display("%b + %b + %b = %b (%b)", a, b, c, sum, carry);
        a = 0;
        b = 1;
        c = 1;
        #1 $display("%b + %b + %b = %b (%b)", a, b, c, sum, carry);
        a = 1;
        b = 0;
        c = 0;
        #1 $display("%b + %b + %b = %b (%b)", a, b, c, sum, carry);
        a = 1;
        b = 0;
        c = 1;
        #1 $display("%b + %b + %b = %b (%b)", a, b, c, sum, carry);
        a = 1;
        b = 1;
        c = 0;
        #1 $display("%b + %b + %b = %b (%b)", a, b, c, sum, carry);
        a = 1;
        b = 1;
        c = 1;
        #1 $display("%b + %b + %b = %b (%b)", a, b, c, sum, carry);
    end
endmodule
