// 스택

#include <iostream>
#include <stack>

using namespace std;

stack<int> mystack;
int n, a;
string s;

int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> s;
        if (s == "push"){
            cin >> a;
            mystack.push(a);
        }
        else if (s == "top"){
            if (!mystack.empty()){
                cout << mystack.top() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (s == "size"){
            cout << mystack.size() << '\n';
        }
        else if (s == "empty"){
            cout << mystack.empty() << '\n';
        }
        else if(s == "pop"){
            if(!mystack.empty()){
                cout << mystack.top() << '\n';
                mystack.pop();
            }
            else {
                cout << -1 << '\n';
            }

        }
    }
    return 0;
}