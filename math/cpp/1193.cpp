// 분수찾기

#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt;
int sum;

int main() {
    cin >> n;
    for (int i = 1; sum < n; i++) {
        sum += i;
        cnt++;
    }
    if(cnt%2==0){
        cout << cnt-(sum%n) << '/' << (sum%n)+1;
    }
    else{
        cout << (sum%n)+1 << '/' << cnt-(sum%n);
    }
}