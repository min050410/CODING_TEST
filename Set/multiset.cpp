#include <iostream>
#include <set>

using namespace std;


int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    multiset<int> ms;

    ms.insert(9);
    ms.insert(13);
    ms.insert(5);
    ms.insert(11);
    ms.insert(7);
    ms.insert(11);
    ms.insert(3);
    ms.insert(1);
    ms.insert(11);
    ms.insert(15);

    multiset<int>::iterator iter;
    for (iter = ms.begin(); iter != ms.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;

    multiset<int>::iterator start , end;

    start = ms.lower_bound(11);
    cout << "lower_bound(11):" << *start << endl;

    end = ms.upper_bound(11);
    cout << "upper_bound(11):" << *end << endl;

    for (start; start!=end; start++){
        cout << *start << " ";
    }
    cout << endl;

    return 0;
}