// 괄호

#include <iostream>
#include <stack>

using namespace std;

int n;
int flag;

int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++){
        stack<int> mystack;
        char c[100] = {};
        cin >> c;
        for (int j=0; c[j]!='\0'; j++){
            if(c[j] == '('){
                mystack.push(1);
            }
            else {
                if (mystack.empty()){
                    cout << "NO" << '\n';
                    flag = 1;
                    break;
                }
                mystack.pop();
            }
        }

        if (flag){
            flag = 0;
            continue;
        }

        if(mystack.empty()){
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}