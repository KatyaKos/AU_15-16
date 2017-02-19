module half_adder_test;
    reg a, b;
    wire s, c;

    half_adder ha(s, c, a, b);
    initial begin
        a = 0;
        b = 0;
        #1 $display("%b + %b = %b (%b)", a, b, s, c);
        a = 0;
        b = 1;
        #1 $display("%b + %b = %b (%b)", a, b, s, c);
        a = 1;
        b = 0;
        #1 $display("%b + %b = %b (%b)", a, b, s, c);
        a = 1;
        b = 1;
        #1 $display("%b + %b = %b (%b)", a, b, s, c);
    end
endmodule
