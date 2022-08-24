#include <iostream>
#include <algorithm>
#define ll long long
#define inf 0x7fffffff

using namespace std;

string a;
int num;
int cnt;

int main() {
    cin >> a;
    for (int i=0; i<a.size(); i++) {
        if (a[i]-'0'>=0 && a[i]-'0' < 10) {
            num = num*10 + (a[i]-'0');
        }
    }
    for (int i=1; i<=num; i++) {
        if (num%i==0) {
            cnt++;
        }
    }
    cout << num << '\n' << cnt;
}
