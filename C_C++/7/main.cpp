#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include "hashmap.h"

using namespace std;

int main(){
	char key_str1[] = "Hail";
	char val_str1[] = "Fassbender";
	char key_str2[] = "Fly";
	char val_str2[] = "Peter";
	HashMap hmp(10007);
	hmp.Add(key_str1, val_str1);
	hmp.Add(key_str2, val_str2);
	hmp.Remove(key_str2);
	char* s = hmp.Get(key_str1);
	cout << s << '\n';
	bool f = hmp.Contains(key_str2);
	cout << f << '\n';
	return 0;
}