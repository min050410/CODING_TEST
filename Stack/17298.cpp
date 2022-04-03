// 오큰수

#include <iostream>
#include <stack>
using namespace std;

int n, a;
stack<int> s;
int arr[1000001];
int ans[1000001];

int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> a;
        arr[i] = a;
    }

    for (int i=n; i>0; i--){
        while (!s.empty() && s.top() <= arr[i]){
            s.pop();
        }

        if (s.empty()){
            ans[i] = -1;
        }

        else {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    for (int i=1; i<=n; i++){
        cout << ans[i] << ' ';
    }

    return 0;
}