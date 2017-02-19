#include <bits/stdc++.h>
#include <thread>

using namespace std;
using sec = chrono::seconds;

const size_t SZ = 5;
const size_t EAT = 3;
const size_t THINK = 2;

mutex forks[SZ];

void eat(int i){

	int f = i;
	int ff = (i + 1) % SZ;

	while(1){

		bool f1 = forks[f].try_lock(), f2 = forks[ff].try_lock();
		if (f1 && f2){
			cout << "Sokrat" << i << " is eating now" << endl;
			this_thread::sleep_for(sec(EAT));
			cout << "Sokrat" << i << " has finished eating" << endl;
		}else{
			cout << "Sokrat" << i << " is thinking now" << endl;
			if (f1) forks[f].unlock();
			if (f2) forks[ff].unlock();
			this_thread::sleep_for(sec(THINK));
			cout << "Sokrat" << i << " has finished thinking" << endl;
		}

	}

}
int main(){

	vector<thread> threads;

	for (int i = 0; i < SZ; i++){
		threads.push_back(thread(eat, i));
	}

	for (auto& t: threads){
		t.join();
	}

}
