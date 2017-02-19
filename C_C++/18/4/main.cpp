#include <iostream>
#include <algorithm>

using namespace std;

template <typename Predicate, typename T>
struct NotPredicate{
    const Predicate& pr;

    NotPredicate(const Predicate& pr) : pr(pr) {}

    bool operator()(const T& x) const{
        return !pr(x);
    }
};

template <typename Iterator, typename Predicate>
pair<Iterator, Iterator> gather(Iterator it1, Iterator it2, Iterator target, const Predicate &pr) {
    Iterator ret1 = stable_partition(it1, target, NotPredicate<Predicate, typename std::iterator_traits<Iterator>::value_type>(pr));
    Iterator ret2 = stable_partition(target, it2, pr);
    return make_pair(ret1, ret2);
}

struct Filter{
    bool operator()(int x) const {
        return (x & 1);
    }
};

int main(){
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);

    gather(v.begin(), v.end(), v.begin() + 4, Filter());

    for(auto x : v)
        cout << x << '\n';

    return 0;
}
