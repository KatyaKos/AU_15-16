#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <new>
#include "template.h"

using namespace std;

int main(){
	Array <bool, 5> a;
	a[0] = true;
	cout << "Array size: " << a.size() << " First el: ";
	cout << a[1] << '\n';

	Stack <int, Array<int, 7>, 7> st;
	cout << "Stack size (not capacity): " << st.size() << " Empty? " << st.empty() << '\n';
	st.push(4);
	st.push(5);
	st.push(9);
	st.pop();
	cout << "Top el: " << st.top() << " Stack size: " << st.size() << " Empty? " << st.empty() << '\n';


	return 0;
}