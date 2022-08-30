// 접미사 배열

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string a;
vector<string> v;


int main() {
    cin >> a;
    n = a.size();
    for (int i=0; i<n; i++) {
        v.push_back(a);
        a.erase(a.begin());
    }
    sort(v.begin(), v.end());
    for (const auto &vec: v) {
        cout << vec << '\n';
    }
}