#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_
#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define pin pair<int, Node*>

const int MAXN = 512;


class Node{
public:
	int freq, code;
	Node *l, *r;

	Node(): code(-1), l(NULL), r(NULL), freq(0) {}
	Node(int code): code(code), l(NULL), r(NULL), freq(0) {}
	Node(int code, int f): code(code), l(NULL), r(NULL), freq(f) {}
	Node(int f, Node* l, Node* r): code(-1), l(l), r(r), freq(f) {}
};

class BitEncoder{
private:
	vector<int> codes[MAXN];
public:

	BitEncoder(const vector<int> codess[MAXN]){
		forn(i, MAXN) codes[i] = codess[i];
	}
	vector<int> getBits(char c);
};

class BitDecoder{
private:
	Node *nd, *head;
public:
	BitDecoder(Node* nod): nd(nod), head(nod) {}
	int readExtra(ifstream& fin);
	vector<unsigned char> getChar(char c);

};

class BitReader{
private:
	ifstream& fin;
public:
	BitReader(ifstream& fin): fin(fin) {}

	bool HasChar();
	char readChar();
};

class BitWriter{
private:
	ofstream& fout;
	int sz, code;
public:
	BitWriter(ofstream& fout): fout(fout) {
		sz = 0; code = 0;
	}

	void writeBit(bool bit);
	bool writeBit();
	void writeChar(unsigned char);
};


class Encode{
private:
	const char *inf, *outf;

	int dfs(Node* nd, vector<int> codes[MAXN], vector<int>& cd, vector<unsigned char>& tree);
	int getFreq(int* freq);
	int sortFreq(int* freq, int* symb, priority_queue<pin>& nodeFr);
	void uniteFreq(priority_queue<pin>& nodeFr);
	int buildCode(int n, vector<int> codes[MAXN], Node* nd, int finsz);
	int encodeProcess(const vector<int> codes[MAXN]);

public:
	Encode() = default;
	Encode(const char* inf, const char* outf): inf(inf), outf(outf) {}
	pair<int, pair<int, int> > Encoding();
};


class Decode{
private:
	const char *inf, *outf;

	int dfs(Node* nd, vector<unsigned char> tree, int i);
	int buildCode(Node* nd);
	int decodeProcess(Node* nd);
public:
	Decode() = default;
	Decode(const char* inf, const char* outf): inf(inf), outf(outf) {}
	pair<int, pair<int, int> > Decoding();
};

#endif