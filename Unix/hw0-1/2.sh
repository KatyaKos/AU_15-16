SRC = $(wildcard *.jpg)
DST = $(addprefix out/, $(SRC))

.PHONY: all
all: $(DST)

out/%.jpg: %.jpg
	convert -colorspace GRAY "$<" "$@"

.PHONY: clean
clean:
	rm -f out/*
