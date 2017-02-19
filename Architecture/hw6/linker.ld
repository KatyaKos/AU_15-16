OUTPUT_FORMAT(binary)
OUTPUT_ARCH(i8086)
ENTRY(start)

SECTIONS {
	. = 0x7C00;
	.text : { *(.text) }
	. = 0x7DFE;
	.signature : { SHORT(0xAA55) }
}
