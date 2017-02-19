default: loop

loop: loop.v loop_test.v
	iverilog -o $@ $^

.PHONY: clean
clean:
	rm loop
