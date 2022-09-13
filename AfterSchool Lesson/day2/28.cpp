#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int cnt2;
int cnt5;

int main() {
    cin >> n;
    for (int i=n; i>0; i--) {
        if (i%2 == 0) {
            int temp = i;
            int cnt = 0;
            while (temp%2 == 0) {
                temp = temp/2;
                cnt++;
            }
            cnt2 += cnt;
        }
        if (i%5 == 0) {
            int temp = i;
            int cnt = 0;
            while (temp%5 == 0) {
                temp = temp/5;
                cnt++;
            }
            cnt5 += cnt;
        }
    }
    cout << min(cnt2, cnt5);
}