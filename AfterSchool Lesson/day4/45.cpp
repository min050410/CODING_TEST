#include <iostream>
#include <queue>
using namespace std;
int n,k;
vector<int> v;
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        v.push_back(i);
    }
    int i = k-1;
    while (v.size() != 1) {
        i = i%v.size();
//        cout << v[i] << ' ';
        v.erase(v.begin()+i);
        i += (k-1);
    }
    cout << v[0];
}