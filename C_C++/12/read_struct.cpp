#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <new>
#include <map>
#include <vector>

using namespace std;

class StructField{
public:
	string name;
	virtual void rewrite(FILE* fin, FILE* fout) = 0;
};

class StructInt: public StructField{
public:
	StructInt(string nam){
		name = nam;
	} 
	void rewrite(FILE* fin, FILE* fout){
		int val;
		fscanf(fin, "%i ", &val);
		fprintf(fout, "%s%s%s%i\n", "    int ", name.c_str(), " = ", val);
	}
};

class StructDouble: public StructField{
public:
	StructDouble(string nam){
		name = nam;
	} 
	void rewrite(FILE* fin, FILE* fout){
		double val;
		fscanf(fin, "%lf ", &val);
		fprintf(fout, "%s%s%s%lf\n", "    doule ", name.c_str(), " = ", val);
	}
};

class StructChar: public StructField{
public:
	StructChar(string nam){
		name = nam;
	} 
	void rewrite(FILE* fin, FILE* fout){
		char val;
		fscanf(fin, "%s", &val);
		fprintf(fout, "%s%s%s%c\n", "    char ", name.c_str(), " = ", val);
	}
};


class StructString: public StructField{
public:
	StructString(string nam){
		name = nam;
	} 
	void rewrite(FILE* fin, FILE* fout){
		char val[256];
		fscanf(fin, "%s ", val);
		fprintf(fout, "%s%s%s%s\n", "    string ", name.c_str(), " = ", val);
	}
};

int main(){
	FILE* data = fopen("data_b", "r");
	FILE* scheme = fopen("scheme_b", "r");
	FILE* fout = fopen("out.txt", "w");

	int n; fscanf(scheme, "%i", &n);
	vector < vector<StructField*> > sch; sch.resize(n);
	char s1[256], s2[256]; int m, k;

	for (int i = 0; i < n; i++){
		fscanf(scheme, "%i %i", &m, &k);
		for (int j = 0; j < k; j++){
			fscanf(scheme, "%s%s\n", s1, s2);
			if (strcmp(s1, "int") == 0){
				StructInt* tmp = new StructInt(s2);
				sch[m].push_back(tmp);
			} else if(strcmp(s1, "string") == 0){
				StructString* tmp = new StructString(s2);
				sch[m].push_back(tmp);
			} else if(strcmp(s1, "double") == 0){
				StructDouble* tmp = new StructDouble(s2);
				sch[m].push_back(tmp);
			} else {
				StructChar* tmp = new StructChar(s2);
				sch[m].push_back(tmp);
			}
		}
	}
	
	while (!feof(data)){
		fscanf(data, "%i", &m);
		fprintf(fout, "%s%i%s\n", "S", m, " {");
		for (int i = 0; i < sch[m].size(); i++){
			sch[m][i]->rewrite(data, fout);
		}
		fprintf(fout, "%s\n", "}");
	}

	return 0;
}
