#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
string a;
int main() {
    cin>>a;
    int flag = 1;
    for (int i=0;i<a.size();i++){
        if (a[i] == '(') {
            s.push(a[i]);
        }
        else {
            if (s.empty()) {
                flag = 0;
                break;
            }
            s.pop();
        }
    }

    if (!flag || !s.empty()) cout<<"NO";
    else cout<<"YES";
}