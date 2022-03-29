#include <iostream>
#include <tuple>
#include <queue>

using namespace std;
int n;
string name;
int y, m, d;
// max heap
//priority_queue<tuple<int, int, int, string>> pq;
// min heap
priority_queue<tuple<int,int,int,string>,vector<tuple<int,int,int,string>>,greater<>> pq;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> name >> y >> m >> d;
        pq.push(make_tuple(y, m, d, name));
    }
    for (int i=0; i<n; i++){
        tuple<int, int, int, string> temp = pq.top();
        cout << get<3>(temp) << '\n';
        pq.pop();
    }
    return 0;
}
