// 스택 수열

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, a;
int nowNum = 0;
stack<int> s;
vector<char> res;
int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> a;
        if (nowNum <= a){
            for (int j=nowNum + 1; j<=a; j++){
                s.push(j);
                nowNum = j;
                res.push_back('+');
            }
            s.pop();
            res.push_back('-');
        }
        else {
            if (s.top() != a){
                cout << "NO" << '\n';
                return 0;
            }
            s.pop();
            res.push_back('-');
        }
    }

    for (const auto &r: res){
        cout << r << '\n';
    }

    return 0;

}