#ifndef _BMP_H_
#define _BMP_H_

#include <stdint.h>

typedef struct{
	int16_t bmpID;
	int32_t bmpSize;
	int16_t bmpApSp1;
	int16_t bmpApSp2;
	int32_t bmpOffset;
	int32_t dibSize;
	int32_t bmpW;
	int32_t bmpH;
	int16_t bmpPlanes;
	int16_t bmpBitPix;
	int32_t bmpComp;
	int32_t bmpSizePad;
	int32_t bmpPrint1;
	int32_t bmpPrint2;
	int32_t bmpCol;
	int32_t bmpImpCol;
	char* name;
}Bmp;

void load_bmp(Bmp* file, unsigned char** pixs);
void crop_rotate(Bmp* file, unsigned char** pixs, int x, int y, int xx, int yy);
void save_bmp(Bmp file, Bmp filout, unsigned char* pixs);


#endif