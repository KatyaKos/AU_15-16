module shift(clk, enable, pin, sin, sout);
  input clk, enable, sin;
  input [7:0] pin;
  output sout;
  reg [7:0] holder;

  always @(posedge clk)
  begin
    if (enable)
      holder = pin;
    else begin
      holder[7:1] = holder[6:0];
      holder[0] = sin;
    end
  end
  assign sout = holder[7];
endmodule
