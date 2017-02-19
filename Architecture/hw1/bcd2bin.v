module bcd2bin(out, in);
	input [7:0] in;
	output [7:0] out;
	wire [7:0] c, mul, add;
	wire carry;
	supply0 gnd;

	assign c[2:0] = 0;
	assign mul[0] = 0;
	assign mul[1] = in[4];
	assign mul[2] = in[5];

	full_adder f0(mul[3], c[3], in[6], in[4], gnd);
	full_adder f1(mul[4], c[4], in[7], in[5], c[3]);
	full_adder f2(mul[5], c[5], in[6], gnd, c[4]);
	full_adder f3(mul[6], c[6], in[7], gnd, c[5]);

	assign mul[7] = c[6];
	assign c[7] = 0;

	assign add[7:4] = 0;
	assign add[3:0] = in[3:0];

	full_adder_8bit f4(out, carry, mul, add, gnd);

endmodule
