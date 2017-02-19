#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <new>
#include <string.h>


using namespace std;

struct CallBack{
	typedef void (*TagStartT)(char*, void* );
	typedef void (*TagTextT)(char*, void* );
	typedef void (*TagEndT)(char*, void* );

	TagStartT TagStart;
	TagTextT TagText;
	TagEndT TagEnd;
};

struct MyMap{
	vector <char*> tags;
	vector <int> count;
};

void StartTag(char* str, void* data){

	MyMap* tmpmap = (MyMap*)data;
	vector <char*> tags = tmpmap->tags;
	vector <int> count = tmpmap->count;

	int u = -1;
	for (int j = 0; j < tmpmap->tags.size(); j++){
		if (strcmp(tmpmap->tags[j], str) == 0){
			u = j;
		}
	}
	if (u == -1){
		char* tmp = new char[256];
		copy(str, str+256, tmp);
		tmpmap->tags.push_back(tmp);
		tmpmap->count.push_back(1);
	}else{
		tmpmap->count[u] += 1;
	}

}
void TextTag(char* str, void* data){
	int o;
}
void EndTag(char* str, void* data){
	int o;
}

void parser(const char* file_name, CallBack CB, void* data){
	FILE* fin = fopen(file_name, "r");
	char str[256];

	while (!feof(fin)){
		fscanf(fin, "%s", str);
		if (str[0] == '<' && str[1] != '/'){
			CB.TagStart(str, data);
		}else if (str[0] == '<' && str[1] == '/'){
			CB.TagEnd(str, data);
		}else{
			CB.TagText(str, data);
		}
	}
}

int main(){
	CallBack CB;
	CB.TagStart = &StartTag;
	CB.TagText = &TextTag;
	CB.TagEnd = &EndTag;
	void* data;
	MyMap mappy;
	data = (void*)(&mappy);
	parser("text.xml", CB, data);

	cout << "Counted tags:" << '\n';
	for (int j = 0; j < mappy.tags.size(); j++){
		cout << mappy.tags[j] << ' ' << mappy.count[j] << '\n';
	}

	return 0;
}