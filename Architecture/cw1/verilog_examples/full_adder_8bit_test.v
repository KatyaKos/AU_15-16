module full_adder_8bit_test;
    reg [7:0] a;
    reg [7:0] b;

    wire [7:0] sum;
    wire carry;

    supply0 gnd;

    integer i;

    full_adder_8bit fa(sum, carry, a, b, gnd);

    initial begin
        for (i = 0; i != (1 << 16); i = i + 1) begin
            a = i & 255;
            b = (i >> 8);
            #1 $display("%d + %d = %d (%b)", a, b, sum, carry);
        end
    end
endmodule
