module loop_test;
  wire [15:0] out;
  wire ready;
  reg [15:0] in;
  reg clk, reset;
  wire [15:0] res;

  loop mul(clk, reset, ready, out, in[7:0], in[15:8]);
  assign res = !ready ? in[7:0] * in[15:8] : out;

  always
    #1 clk <= !clk;

  always @(negedge clk) begin
    reset = 0;
    if (ready) begin
      in = in + 1;
      reset = 1;
    end
  end

  initial begin
    clk = 0;
    in = {8'd0, 8'd0};
    reset = 0;
    #1 reset = 1;
  end

  initial
    $monitor("%b %d", ready, res);

  initial
    #2000 $finish;
endmodule
