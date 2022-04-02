// 제로

#include <iostream>
#include <stack>

using namespace std;

stack<int> mystack;
int n, a;
int cnt;

int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a;
        if (a == 0){
            mystack.pop();
        }
        else {
            mystack.push(a);
        }
    }

    while(!mystack.empty()){
        cnt += mystack.top();
        mystack.pop();
    }

    cout << cnt;
    return 0;
}