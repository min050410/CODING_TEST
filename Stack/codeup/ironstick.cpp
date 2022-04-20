// 쇠 막대기

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string a;
stack<char> s;
int cnt, res;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> a;

    bool isSeq = false;
    for (const auto&item: a){
        if (item == '('){
            isSeq = true;
            s.push(item);
        }
        if (item == ')'){
            if (isSeq){
                s.pop();
                // cout << s.size()+cnt << ' ';
                res += s.size()+cnt;
                cnt = 0;
            }
            else {
                cnt++;
                s.pop();
            }
            isSeq = false;
        }

    }
    res+=cnt;
    cout << res;
}