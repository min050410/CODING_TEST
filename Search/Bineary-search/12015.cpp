// 가장 긴 증가하는 부분 수열

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll n;
ll a;
vector<int> v;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;
        if (!v.size()) v.push_back(a);
        else {
            ll low = lower_bound(v.begin(), v.end(), a) - v.begin();
            if (low == v.size()) v.push_back(a);
            else v[low] = a;
        }
    }
//    for (const auto &LIS: v) {
//        cout << LIS << ' ';
//    }
//    cout << '\n';
    cout << v.size();
}