#include "str_func.h"
#include <iostream>


int main(){
	
	char str1[] = "Hail Fassbender!";
	char str2[40];
	strcpy(str1, str2);
	std::cout << str2 << '\n';

	strcpy(" Macbeth.", str1);
	strcat(str1, str2);
	std::cout << str2 << '\n';

	char str3[] = "Hail Hidra!";
	char str4[] = "Hail Fassbender!";
	std::cout << strcmp(str3, str4) << '\n';

	std::cout << strlen(str2) << '\n';
}
