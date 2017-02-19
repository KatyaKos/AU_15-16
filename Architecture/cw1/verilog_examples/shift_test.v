module shift_test;
  wire sout;
  reg clk, enable;
  reg [7:0] pin;
  supply0 gnd;

  shift s(clk, enable, pin, gnd, sout);

  always begin
    #1 clk = !clk;
  end

  initial begin
    clk = 0;
    enable = 1;
    pin = 8'b10101010;
    #2 enable = 0;
  end

  initial
    $monitor("at %d sout=%b", $time, sout);

  initial
    #20 $finish;
endmodule
