// 좌표 압축
#include <iostream>
#include <map>
#include <queue>

using namespace std;

int n, a;
int temp = 1000000000;
multimap<int, int> m;
// min pq
priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;

int main() {
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> a;
        m.insert({a, i});
    }

    // test
    // for (auto m1: m){
    // cout << m1.first << ' ' << m1.second << '\n';
    // }

    int i = -1;
    int temp;
    for (auto mi: m){
        if (temp == mi.first){
            pq.push({mi.second, i});
        }
        else {
            pq.push({mi.second, ++i});
        }
        temp = mi.first;
    }

    while (!pq.empty()){
        cout << get<1>(pq.top()) << " ";
        pq.pop();
    }

}