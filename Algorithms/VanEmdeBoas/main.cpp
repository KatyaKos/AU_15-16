#include "boas.h"
#include "binary.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <time.h>

using namespace std;

typedef VAB_Heap* pVAB_Heap;

const int M = 100005;

int main(){

//Van Emde Boas Heap tests
	ifstream tin("boas_test.in");
	ofstream tout("Boas_results.txt");

	int ntests, n;
	tin >> ntests;
	char c; int x;

	for (int y = 0; y < ntests; y++){
		tin >> n;
		VAB_Heap v;
		tout << "Test " << y + 1 << '\n';
		for (int i = 0; i < n; i++){
			tin >> c >> x;
			//cout << c << ' ' << x << '\n';
			if (c == 'A'){
				v.Add(x, M);
			}else if (c == 'D'){
				v.Delete(x, M);
			}else{
				tout << "Correct answer: " << x << ";   My answer: " << v.ExtractMin() << '\n';
			}
		}
		tout << '\n';
	}

	tin.close();
	tout.close();

//Compare
	ifstream in("pq_bin_boas.in");
	ofstream out("Compare_results.txt");
	clock_t qtime, vtime, btime;
	in >> ntests;

	for (int y = 0; y < ntests; y++){
		in >> n;
		vector <pair<char, int> > act;
		act.resize(n);
		for (int i = 0; i < n; i++){
			in >> c;
			x = 0;
			if (c == 'A') in >> x;
			act[i] = make_pair(c, x);
			//cout << c << ' ' << x << '\n';
		}

		VAB_Heap v;
		Bin_Heap b;
		priority_queue<int> q;
		//VAB
		vtime = clock();
		for (int i = 0; i < n; i++){
			c = act[i].first; x = act[i].second;
			if (c == 'A'){
				v.Add(x, M);
			}else{
				v.ExtractMin();
			}
		}
		vtime = clock() - vtime;

		//Binary
		btime = clock();
		for (int i = 0; i < n; i++){
			c = act[i].first; x = act[i].second;
			if (c == 'A'){
				b.Add(x);
			}else{
				b.ExtractMin();
			}
		}
		btime = clock() - btime;

		//priority_queue
		qtime = clock();
		for (int i = 0; i < n; i++){
			c = act[i].first; x = act[i].second;
			if (c == 'A'){
				q.push(x);
			}else{
				q.pop();
			}
		}
		qtime = clock() - qtime;

		out << "Test " << y + 1 << '\n';
		out << "Van Emde Boas: " << vtime << "\nBinary Heap: " << btime << "\nPriority Queue: " << qtime << "\n\n";
	}
	

	in.close();
	out.close();

	return 0;
}