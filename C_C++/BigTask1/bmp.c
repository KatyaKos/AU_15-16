#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdint.h>

void load_bmp(Bmp* file, unsigned char** pixs){
	FILE* fin = fopen((*file).name, "r");
	/*Header*/
	fread(&(*file).bmpID, sizeof(int16_t), 1, fin);
	fread(&(*file).bmpSize, sizeof(int32_t), 1, fin);
	fread(&(*file).bmpApSp1, sizeof(int16_t), 1, fin);
	fread(&(*file).bmpApSp2, sizeof(int16_t), 1, fin);
	fread(&(*file).bmpOffset, sizeof(int32_t), 1, fin);
	fread(&(*file).dibSize, sizeof(int32_t), 1, fin);
	fread(&(*file).bmpW, sizeof(int32_t), 1, fin);
	fread(&(*file).bmpH, sizeof(int32_t), 1, fin);
	fread(&(*file).bmpPlanes, sizeof(int16_t), 1, fin);
	fread(&(*file).bmpBitPix, sizeof(int16_t), 1, fin);
	fread(&(*file).bmpComp, sizeof(int32_t), 1, fin);
	fread(&(*file).bmpSizePad, sizeof(int32_t), 1, fin);
	fread(&(*file).bmpPrint1, sizeof(int32_t), 1, fin);
	fread(&(*file).bmpPrint2, sizeof(int32_t), 1, fin);
	fread(&(*file).bmpCol, sizeof(int32_t), 1, fin);
	fread(&(*file).bmpImpCol, sizeof(int32_t), 1, fin);
	/*Going to start of pixel array*/
	int pos = 54; unsigned char tmp;
	while (pos != (*file).bmpOffset){
		fread(&tmp, sizeof(unsigned char), 1, fin);
		pos++;
	}

	/*Start of pixel array!*/
	int n = (*file).bmpSizePad; int i;
	*pixs = malloc(n * sizeof(unsigned char));
	for (i = 0; i < n; i++){
		fread(&tmp, sizeof(unsigned char), 1, fin);
		(*pixs)[i] = tmp;
	}
}

void crop_rotate(Bmp* file, unsigned char** pixs, int x, int y, int xx, int yy){
	int i;
	int n; n = (*file).bmpSizePad; int j; int u;
	int delta; delta = (4 - (*file).bmpW % 4) % 4;
	int pos; pos = 0;

	(*file).bmpW = (*file).bmpW * (*file).bmpBitPix / 8;

	unsigned char*** tmp = malloc((yy - y + 1) * sizeof(unsigned char**));
	for (i = 0; i < yy - y + 1; i++){
		tmp[i] = malloc((xx - x + 1) * sizeof(unsigned char*));
		for (j = 0; j < xx - x + 1; j++){
			tmp[i][j] = malloc((*file).bmpBitPix / 8 * sizeof(unsigned char));
		}
	}

	int st;
	if ((*file).bmpH < 0){
		st = y * ((*file).bmpW + delta);
	}else{
		st = (*file).bmpSizePad - (yy + 1) * ((*file).bmpW + delta);
	}
	for (i = 0; i < yy - y + 1; i++){
		pos = st + x * (*file).bmpBitPix / 8 + ((*file).bmpW + delta) * i;
		for (j = 0; j < xx - x + 1; j++){
			for (u = 0; u < (*file).bmpBitPix / 8; u++){
				tmp[i][j][u] = (*pixs)[pos];
				pos += 1;
			}
		}
	}

	delta = (4 - ((yy - y + 1) * (*file).bmpBitPix / 8 % 4)) % 4;
	n = (yy - y + 1) * (xx - x + 1) * (*file).bmpBitPix / 8 + delta * (xx - x + 1);
	*pixs = realloc (*pixs, n * sizeof(unsigned char*));
	pos = 0;
	for (i = xx - x; i >= 0; i--){
		for (j = 0; j < yy - y + 1; j++){
			for (u = 0; u < (*file).bmpBitPix / 8; u++){
				(*pixs)[pos] = tmp[j][i][u];
				pos += 1;
			}
		}
		for (j = 0; j < delta; j++){
			(*pixs)[pos] = '\0';
			pos += 1;
		}
	}

	for (i = 0; i < yy - y + 1; i++){
		for (j = 0; j < xx - x + 1; j++){
			free(tmp[i][j]);
		}
		free(tmp[i]);
	}
	free(tmp);
	(*file).bmpH = xx - x + 1;
	(*file).bmpW = yy - y + 1;
	(*file).bmpSizePad = n;

}


void save_bmp(Bmp file, Bmp filout, unsigned char* pixs){
	FILE* fout = fopen(filout.name, "w");
	int i;
	file.bmpSize = file.bmpSizePad + 14 + file.dibSize;
	fwrite(&file.bmpID, sizeof(int16_t), 1, fout);
	fwrite(&file.bmpSize, sizeof(int32_t), 1, fout);
	fwrite(&file.bmpApSp1, sizeof(int16_t), 1, fout);
	fwrite(&file.bmpApSp2, sizeof(int16_t), 1, fout);
	fwrite(&file.bmpOffset, sizeof(int32_t), 1, fout);
	fwrite(&file.dibSize, sizeof(int32_t), 1, fout);
	fwrite(&file.bmpW, sizeof(int32_t), 1, fout);
	fwrite(&file.bmpH, sizeof(int32_t), 1, fout);
	fwrite(&file.bmpPlanes, sizeof(int16_t), 1, fout);
	fwrite(&file.bmpBitPix, sizeof(int16_t), 1, fout);
	fwrite(&file.bmpComp, sizeof(int32_t), 1, fout);
	fwrite(&file.bmpSizePad, sizeof(int32_t), 1, fout);
	fwrite(&file.bmpPrint1, sizeof(int32_t), 1, fout);
	fwrite(&file.bmpPrint2, sizeof(int32_t), 1, fout);
	fwrite(&file.bmpCol, sizeof(int32_t), 1, fout);
	fwrite(&file.bmpImpCol, sizeof(int32_t), 1, fout);

	unsigned char trash = 0;
	for (i = 0; i < file.bmpOffset - 54; i++){
		fwrite(&trash, sizeof(unsigned char), 2, fout);
	}

	for (i = 0; i < file.bmpSizePad; i++){
		fwrite(&pixs[i], sizeof(unsigned char), 1, fout);
	}

	free(pixs);
}
