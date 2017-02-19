#include "huffman.h"

using namespace std;

void help(){
	cerr << "ERROR!" << endl;
    cerr << "Usage: ./huffman -c/-u -f input_file -o output_file" << endl;
    cerr << "-c for encoding, -u for decoding" << endl;
}

void check_args_num(int argc){
	if (argc != 1+5) throw "There must be three keys.";
}

void check_args(int flag){
	if (flag) throw "There must be keys -f, -o, -c/-u.";
}

void check_file(const char* name){
	if (ifstream(name, ios::in) == NULL) throw "File problem";
}

int main(int argc, char* argv[]){

	try{
		check_args_num(argc);
	} catch (const char* s){
		help();
		return 1;
	}

	const char *inf, *outf;
	int flag = 1;

	for (int i = 1; i < 5; i++)
		if (!strcmp(argv[i], "-f") || !strcmp(argv[i], "--file"))
			inf = argv[i + 1], flag = 0;
		
	try{
		check_args(flag);
	} catch (const char* s){
		help();
		return 1;
	}
	flag = 1;

	for (int i = 1; i < 5; i++)
		if (!strcmp(argv[i], "-o") || !strcmp(argv[i], "--output"))
			outf = argv[i + 1], flag = 0;
		
	try{
		check_args(flag);
	} catch (const char* s){
		help();
		return 1;
	}
	flag = 1;

	try{
		check_file(inf);
	} catch (const char* s) {
		cerr << "ERROR!\nI/O error" << endl;
		return 1;
	}

	pair<int, pair<int, int> > sizes;

	if (!strcmp(argv[1], "-c") || !strcmp(argv[3], "-c") || !strcmp(argv[5], "-c")){
		
		flag = 0;
		Encode hf(inf, outf);
		sizes = hf.Encoding();

	}else if (!strcmp(argv[1], "-u") || !strcmp(argv[3], "-u") || !strcmp(argv[5], "-u")){
		flag = 0;
		Decode dhf(inf, outf);
		sizes = dhf.Decoding();
	}
	try{
		check_args(flag);
	} catch (const char* s){
		help();
		return 1;
	}

	cout << sizes.first << endl << sizes.second.first << endl << sizes.second.second << endl;

	return 0;
}