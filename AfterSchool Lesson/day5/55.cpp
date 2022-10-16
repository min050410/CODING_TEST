#include <iostream>
#include <stack>
#include <vector>
using namespace std;
stack<int> s;
int n;
int a;
int cnt;
vector<char> ans;
int main() {
    cin>>n;
    int j = 1;
    for (int i=0;i<n;i++) {
        cin>>a;
        s.push(a);
        ans.push_back('P');
        cnt++;
        while (!s.empty() && s.top() == j) {
            j++;
            s.pop();
            ans.push_back('O');
            cnt--;
        }
    }
    if (cnt) { cout << "impossible"; return 0; }
    for (char i: ans) {
        cout<<i;
    }
}