// 국영수

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n;
int b, c, d;
string a;
vector<tuple<int, int, int, string>> v;

bool comp (tuple<int, int, int, string> a, tuple<int, int, int, string> b) {
    if (get<0>(a) == get<0>(b)) {
        if (get<1>(a) == get<1>(b)) {
            if (get<2>(a) == get<2>(b)) {
                return get<3>(a) < get<3>(b);
            }
            return get<2>(a) > get<2>(b);
        }
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) > get<0>(b);
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b >> c >> d;
        v.push_back({b, c, d, a});
    }
    sort(v.begin(), v.end(), comp);
    for (const auto &vec: v) {
        cout << get<3>(vec) << '\n';
    }
}