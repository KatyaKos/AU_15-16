default: mynand mynand2 half_adder full_adder adder_2bit full_adder_8bit shift

shift: shift.v shift_test.v
	iverilog -o $@ $^

mynand: mynand.v mynand_test.v
	iverilog -o $@ $^

mynand2: mynand2.v mynand2_test.v
	iverilog -o $@ $^

half_adder: half_adder.v half_adder_test.v
	iverilog -o $@ $^

full_adder: half_adder.v full_adder.v full_adder_test.v
	iverilog -o $@ $^

adder_2bit: half_adder.v full_adder.v adder_2bit.v adder_2bit_test.v
	iverilog -o $@ $^

full_adder_8bit: half_adder.v full_adder.v full_adder_8bit.v full_adder_8bit_test.v
	iverilog -o $@ $^

.PHONY: clean
clean:
	rm mynand mynand2 half_adder full_adder adder_2bit full_adder_8bit shift
