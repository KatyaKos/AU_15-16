module loop(clk, reset, ready, out, a, b);
	input clk, reset;
	input [7:0] a;
	input [7:0] b;
	output [15:0] out;
	output ready;

	reg [15:0] ans;
	reg [15:0] tmpa = 0;
	reg [7:0] tmpb = 0;
	reg tmpready = 0;
	reg tmpreset = 0;

	assign out = ans;
	assign ready = tmpready;

	always @(posedge clk)
	begin
		if (tmpa && tmpb) begin

			if (tmpb[0]) begin
				ans <= ans + tmpa;
			end
			tmpa <= tmpa << 1;
			tmpb <= tmpb >> 1;

		end else if (reset) begin

			tmpreset <= 1;
			tmpready <= 0;
			ans <= 0;
			tmpa <= a;
			tmpb <= b;

		end else if (tmpreset && !tmpready) begin
			tmpready <= 1;
		end
	end
	
endmodule
