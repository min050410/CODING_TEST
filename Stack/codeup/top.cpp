// 코드업 탑

#include <iostream>
#include <stack>
#include <string>

#define INF 0x7fffffff

using namespace std;

int n, a;
stack<pair<int, int>> s;
int cnt, res;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    s.push({INF, 0});

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a;
        if (s.top().first > a){
            cout << s.top().second << ' ';
            s.push({a, i});
        }
        else {
            while (s.top().first < a) {
                s.pop();
            }
            cout << s.top().second << ' ';
            s.push({a, i});
        }
    }
}
