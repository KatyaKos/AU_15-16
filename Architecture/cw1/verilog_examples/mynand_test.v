module mynand_test;
    reg A, B;
    wire C0, C1;

    mynand nand1(C0, A, B);
    nand nand2(C1, A, B);

    initial begin
        A = 0;
        B = 0;
        #1 $display("%d %d", C0, C1);
        A = 0;
        B = 1;
        #1 $display("%d %d", C0, C1);
        A = 1;
        B = 0;
        #1 $display("%d %d", C0, C1);
        A = 1;
        B = 1;
        #1 $display("%d %d", C0, C1);
    end
endmodule
