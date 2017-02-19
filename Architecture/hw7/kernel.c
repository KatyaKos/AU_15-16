#include <stdint.h>

const int LINE = 80;
const int COLUMN = 80;

static volatile char* VIDEO = (char*)0xB8000;
static volatile unsigned char *video;
static volatile int xpos = 0;

char alph[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

void cls(void){
	int i;
	video = (unsigned char*) VIDEO;

	for (i = 0; i < COLUMN * LINE * 2; i++)
		*(video + i) = 0;
}

void putChar(char c) {
	*VIDEO = c;
	*(VIDEO + 1) = (char)0x0B;
	VIDEO += 2;
	xpos += 2;
}

void printf(char *str) {
	while(*str) 
		putChar(*str++);
}

void printEndl() {
	VIDEO += (2 * LINE - xpos);
	xpos = 0;
}

void printAddr(uint64_t addr) {
	int bytex[16];
	putChar('0');
	putChar('x');
	for (int byte = 0; byte < 16; byte++) {
		bytex[15 - byte] = addr % 16;
		addr >>= 4;
	}
	for (int byte = 0; byte < 16; byte++) {
		putChar(alph[bytex[byte]]);
	}
}

struct mem {
	uint32_t size;
	uint64_t base_addr;
	uint64_t length;
	uint32_t type;
}__attribute__((packed));

void print_info(uint64_t beg, uint64_t end, uint32_t type) {
	printf((char*)("memory range: "));
	printAddr(beg);
	putChar('-');
	printAddr(end);
	printf((char*)(", type="));
	putChar(type == 1 ? '1' : '2');
	printEndl();
}

void main(uint32_t *eax, uint32_t *ebx) {
	cls();
	if (!(((*ebx) >> 6) & 1)) {
		printf((char*)("Fail, mmap field is invalid\n"));
		return;
	}
	uint32_t mmap_length = *(ebx + 11);
	uint32_t *mmap_addr = (uint32_t*)*(ebx + 12);
	struct mem* cur_mem = (struct mem*)mmap_addr;
	while ((char*)cur_mem - (char*)mmap_addr < mmap_length) {
		print_info(cur_mem->base_addr, cur_mem->base_addr + cur_mem->length - 1, cur_mem->type);
		cur_mem = (struct mem*)((char*)cur_mem + 4 + cur_mem->size);
	}
	return;
}
