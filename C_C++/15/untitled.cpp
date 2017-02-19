#include <iostream>
#include <vector>
using namespace std;

template <typename T1, int Arity>
class ParentSecondStep{
public:
	T1& arg1;
	ParentSecondStep(T1& arg1): arg1(arg1){}
};

template <typename T1, int Arity>
class SecondStep: public ParentSecondStep<T1, Arity>{

	SecondStep(T1& aarg1): ParentSecondStep<T1, Arity>(aarg1){
		this->arg1 = aarg1;
	}
};

int main() {

}
