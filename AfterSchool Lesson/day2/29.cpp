#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int cnt;

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        int temp = i;
        while(temp) {
            if (temp % 10 == 3) cnt++;
            temp = temp/10;
        }
    }
    cout << cnt;
}