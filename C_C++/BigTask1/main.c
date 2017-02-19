#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdint.h>

int x, y, xx, yy;

int main (int argc, char* argv[])
{
	if (argc != 1+6){
		printf("%s", "Wrong number of argumets\n");
		return 0;
	}
	char* inf = argv[1];
	char* outf = argv[2];
	int x = atoi(argv[3]);
	int y = atoi(argv[4]);
	int xx = atoi(argv[5]);
	int yy = atoi(argv[6]);

	if (x > xx || y > yy || x < 0 || y < 0){
		printf("%s", "ERROR! Bad coordinates!\n");
		return 1;
	}

	Bmp file;
	Bmp filout;
	unsigned char* pixels;
	file.name = inf;
	filout.name = outf;
	FILE* fout = fopen(outf, "w");

	load_bmp(&file, &pixels);
	if (file.bmpW <= x || file.bmpH <= y || file.bmpW <= xx || file.bmpH <= yy){
		printf("%s", "ERROR! Bad coordinates!\n");
		return 1;
	}
	crop_rotate(&file, &pixels, x, y, xx, yy);
	save_bmp(file, filout, pixels);

	return 0;
}