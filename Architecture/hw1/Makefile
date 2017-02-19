default: bcd2bin

bcd2bin: bcd2bin.v bcd2bin_test.v full_adder_8bit.v full_adder.v half_adder.v
	iverilog -o $@ $^

.PHONY: clean
clean:
	rm -f bcd2bin
