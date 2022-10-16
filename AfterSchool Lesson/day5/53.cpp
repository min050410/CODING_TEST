// 스택을 이용해 진수 구하기

#include <iostream>
#include <stack>
using namespace std;
int n, k;
stack<int> s;
int main() {
    cin>>n>>k;
    while (n!=0) {
        s.push(n%k);
        n = n/k;
    }
    while (!s.empty()) {
        switch (s.top()) {
            case 10:
                cout<<'A';
                break;
            case 11:
                cout<<'B';
                break;
            case 12:
                cout<<'C';
                break;
            case 13:
                cout<<'D';
                break;
            case 14:
                cout<<'E';
                break;
            case 15:
                cout<<'F';
                break;
            default:
                cout<<s.top();
        }
        s.pop();
    }
}