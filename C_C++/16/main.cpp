#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>

using namespace std;

class Matrix{
private:
	size_t n;
	vector <vector<double> > mtx;
public:
	Matrix(){}
	Matrix(size_t nn): n(nn){
		mtx.resize(n);
		for (size_t i = 0; i < n; i++){
			mtx[i].resize(n);
		}
	}
	~Matrix(){}


	vector<double>& operator[](size_t i){
		return mtx[i];
	}

	size_t size(){
		return n;
	}
};

const int WIDTH = 11;
const int PREC = 4;

int num_len(double x){
	int ans = 0;
	while (x >= 1){
		x /= 10;
		ans++;
	}
	return ans;
}

ostream& operator <<(ostream& fout, Matrix& m){
	ios::fmtflags f(fout.flags());
	int n = m.size();
	int len;
	for (int i = 0; i < n; i++){
		fout << ' ';
		for (int u = 0; u < n * WIDTH + 3 * n; u++) fout << '=';
		fout << endl;
		for (int j = 0; j < n; j++){
			fout << " | ";			fout.width(WIDTH);
			fout.fill(' ');
			fout.precision(PREC);
			fout.flags(ios::right | ios::fixed);

			len = num_len(m[i][j]);
			if (len + PREC + 1 > WIDTH){
				fout << scientific;
				fout.precision(WIDTH - 6);
			}
			fout << m[i][j];
		}
		fout << "|" << endl;
	}
	fout << ' ';
	for (int u = 0; u < n * WIDTH + 3 * n; u++) fout << '=';
	fout << endl;
	fout.flags(f);
	return fout;
}

int main(){
	ifstream fin("matrix.in");

	int n = 0, k = 10;
	double d;
	vector<double> vd;
	while (fin.peek() != '\n'){
		fin >> d;
		n++;
		vd.push_back(d);	
	}

	Matrix m(n);
	for (int i = 0; i < n; i++){
		m[0][i] = vd[i];
	}

	for (int i = 1; i < n; i++){
		for (int j = 0; j < n; j++){
			fin >> m[i][j];
		}
	}

	cout << " Matrix:\n" << m;

	return 0;
}