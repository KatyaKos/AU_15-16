#include "huffman.h"

using namespace std;

bool BitReader::HasChar(){
	return !fin.eof();
}

char BitReader::readChar(){
	char c;
	fin.read(&c, 1);
	return c;
}

vector<int> BitEncoder::getBits(char c){
	return codes[(unsigned char)c];
}

int BitDecoder::readExtra(ifstream& fin){
	char c; int tsz = 0, n = 0;

	forn(i, 4){
		fin.read(&c, 1);
		tsz = tsz * 10 + c - '0';
	}
	forn(i, tsz) fin.read(&c, 1);

	forn(i, 7){
		fin.read(&c, 1);
		n = n * 10 + c - '0';
	}
	return n;
}

vector<unsigned char> BitDecoder::getChar(char c){
	bitset<8> bt(c);
	vector<unsigned char> chans;
		
	for (int i = 7; i >= 0; i--){
		if (bt[i]) nd = nd->l;
		else nd = nd->r;
		if (nd->r == NULL){
			chans.push_back((unsigned char)nd->code);
			nd = head;
		}
	}
	return chans;
}

void BitWriter::writeBit(bool bit){
	sz++;
	code *= 2;
	if (bit) code++;

	if (sz == 8){
		char ch = (unsigned char)code;
		fout.write(&ch, 1);
		sz = 0; code = 0;
	}
}

void BitWriter::writeChar(unsigned char c){
	char ch = c;
	fout.write(&ch, 1);
}

bool BitWriter::writeBit(){
	if (!sz) return 0;
	while (sz != 8){
		code *= 2;
		sz++;
	}
	
	char ch = (unsigned char)code;
	fout.write(&ch, 1);
	return 1;
}

int Encode::getFreq(int* freq){
	int sz = 0;
	ifstream f(inf, ios::in);

	char c;
	while (!f.eof()){
		f.read(&c, 1);
		sz++;
		freq[(unsigned char)c]++;
	}
	freq[(unsigned char)c]--;

	f.close();
	return sz - 1;
}

int Encode::sortFreq(int* freq, int* symb, priority_queue<pin>& nodeFr){
	int n = 0;
	forn(i, MAXN) 
		if (freq[i]){
			symb[n++] = i;
			Node* nd = new Node(i, freq[i]);
			nodeFr.push(make_pair(-freq[i], nd));
		}

	return n;
}

void Encode::uniteFreq(priority_queue<pin>& nodeFr){
	if (!nodeFr.size()) return;

	while (nodeFr.size() != 1){
		pair<int, Node*> p, q;
		p = nodeFr.top();
		nodeFr.pop();
		q = nodeFr.top();
		nodeFr.pop();

		Node* nd = new Node(p.second->freq + q.second->freq, p.second, q.second);
		nodeFr.push(make_pair(p.first+q.first, nd));
	}
}

int Encode::dfs(Node* nd, vector<int> codes[MAXN], vector<int>& cd, vector<unsigned char>& tree){
	if (nd->code != -1){
		codes[nd->code] = cd;
		tree.push_back('0'); tree.push_back((unsigned char)nd->code);
	}else{
		cd.push_back(1);
		tree.push_back('1');
		dfs(nd->l, codes, cd, tree);
		cd[cd.size() - 1] = 0;
		dfs(nd->r, codes, cd, tree);
		cd.pop_back();
	}
}


int Encode::buildCode(int n, vector<int> codes[MAXN], Node* nd, int finsz){
	ofstream fout(outf, ios::out | ios::binary);
	int extsz = 0;
	char c;
	if (!n){
		fout << "0000";
		extsz = 4;
	}else if (n == 1){
		codes[nd->code].push_back(1);
		fout << "00020" << (unsigned char)nd->code;
		extsz = 6;
	}else{
		vector<int> tmp;
		vector<unsigned char> tree;
		dfs(nd, codes, tmp, tree);
		extsz = tree.size();
		if (extsz < 10) fout << "000";
		else if (extsz < 100) fout << "00";
		else if (extsz < 1000) fout << "0";

		fout << extsz;
		forn(i, extsz) fout << tree[i];
		extsz += 4;
	}

	if (finsz == 0) fout << "0000000";
	else{
		int f = finsz, j = 0;
		while (f) f /= 10, j++;
		forn(i, 7 - j) fout << '0';
		fout << finsz;
	}

	extsz += 7;
	fout.close();
	return extsz;
}


int Encode::encodeProcess(const vector<int> codes[MAXN]){

	ifstream fin(inf, ios::in | ios::binary);
	ofstream fout(outf, ios_base::app | ios::binary);

	BitReader r(fin); BitWriter w(fout);
	BitEncoder e(codes);
	int fsz = 0;

	while (r.HasChar()){
		char c = r.readChar();
		for (bool bit : e.getBits(c)){
			w.writeBit(bit);
			fsz++;
		}
	}
	if (w.writeBit()) fsz = (fsz / 8 + 1) * 8;

	return fsz / 8;
}

pair<int, pair<int, int> > Encode::Encoding(){
	int freq[MAXN], symb[MAXN];
	priority_queue<pin> nodeFr;

	int finlen = getFreq(freq);
	int usedSymb = sortFreq(freq, symb, nodeFr);
	uniteFreq(nodeFr);
	if (!nodeFr.size()){
		Node* nd = new Node;
		nodeFr.push(make_pair(0, nd));
	}

	vector<int> codes[MAXN];
	int extralen = buildCode(usedSymb, codes, nodeFr.top().second, finlen);

	int foutlen = encodeProcess(codes);
	return make_pair(finlen, make_pair(foutlen, extralen));
}

int Decode::dfs(Node* nd, vector<unsigned char> tree, int i){
	if (tree[i] == '0'){
		nd->code = (int)tree[i + 1];
		return i + 2;
	}else{
		i++;
		nd->l = new Node; nd->r = new Node;
		i = dfs(nd->l, tree, i);
		i = dfs(nd->r, tree, i);
		return i;
	}
}

int Decode::buildCode(Node* nd){
	ifstream fin(inf, ios::in | ios::binary);
	char c; int tsz = 0;
	forn(i, 4){
		fin.read(&c, 1);
		tsz = tsz * 10 + c - '0';
	}

	if (tsz == 0){

	}else if (tsz == 2){
		fin.read(&c, 1); fin.read(&c, 1);
		nd->l = new Node((int)(unsigned char)c);
		nd->r = new Node;
	}else{
		vector<unsigned char> tree;
		forn(i, tsz){
			fin.read(&c, 1);
			tree.push_back((unsigned char)c);
		}
		dfs(nd, tree, 0);
	}

	while (!fin.eof()){
		fin.read(&c, 1); tsz++;
	}
	fin.close();
	return tsz + 4 - 1;
}

int Decode::decodeProcess(Node* nd){
	int fsz = 0;
	ifstream fin(inf, ios::in | ios::binary);
	ofstream fout(outf, ios_base::out | ios::binary);

	BitReader r(fin); BitWriter w(fout);
	BitDecoder d(nd);

	char c;
	int n = d.readExtra(fin);

	while (fsz < n){
		c = r.readChar();
		for (unsigned char ch : d.getChar(c)){
			w.writeChar(ch);
			fsz++;
			if (fsz == n) break;
		}
	}

	fin.close();
	fout.close();
	return fsz;
}

pair<int, pair<int, int> > Decode::Decoding(){
	Node* nd = new Node;
	int foutsz, finsz;
	finsz = buildCode(nd);
	foutsz = decodeProcess(nd);
	return make_pair(finsz, make_pair(foutsz, 0));
}

