#include "str_func.h"

void strcpy(const char *src, char *dest){
	
	while (*src != '\0'){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
}

void strcat(const char *src, char *dest){

	while (*dest != '\0'){
		dest++;
	}

	while (*src != '\0'){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
}

int strcmp(const char *s1, const char *s2){

	while (*s1 == *s2){
		s1++;
		s2++;
	}
	if (*s1 == *s2){
		return 0;
	} else if(*s1 > *s2){
		return 1;
	} else{
		return -1;
	}

}

int strlen(const char *s){

	const char *p = s;
	while (*p != '\0'){
		p++;
	}
	return p - s;
}





