// 균형잡힌 세상

#include <iostream>
#include <stack>
#include <map>
using namespace std;

int flag;
map<char, char> m;

int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    m[')'] = '(';
    m[']'] = '[';

    while (true) {
        stack<char> stack1;
        stack<int> stack2;
        string s;

        getline(cin, s, '.');
        cin.ignore();

        if (s.empty()) {
            break;
        }


        for (char i : s){
            if (i == '(' || i == '['){
                stack1.push(i);
            }
            else if (i == ')' || i == ']'){
                if (stack1.empty()) {
                    cout << "no" << '\n';
                    flag = 1;
                    break;
                }
                else {
                    int temp = stack1.top();
                    if (m[i] != temp){
                        cout << "no" << '\n';
                        flag = 1;
                        break;
                    }
                    stack1.pop();
                }
            }
        }
        if (flag){
            flag = 0;
            continue;
        }
        if (stack1.empty()){
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }
}