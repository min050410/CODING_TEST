// 입체기동장치 생상 공장

#include <iostream>
#include <tuple>
#include <queue>

using namespace std;
int n;
int num, gas;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> num >> gas;
        pq.push(make_pair(num, gas));
    }
    for (int i=0; i<n; i++){
        pair<int, int> temp = pq.top();
        cout << temp.first << " " << temp.second << '\n';
        pq.pop();
    }
    return 0;
}