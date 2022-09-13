#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string a;
int Ctime;
int Htime;
int C, H;

int main() {
    cin >> a;
    for (int i=0; i<a.size(); i++) {
        if (a[i] == 'C') {
            Ctime = 1;
        }
        else if (a[i] == 'H') {
            Htime = 1;
            Ctime = 0;
        }
        else {
            if (Ctime) {
                C = C*10 + (a[i]-'0');
            }
            if (Htime) {
                H = H*10 + (a[i]-'0');
            }
        }
    }
		if (C==0) C = 1;
		if (H==0) H = 1;
    cout << 12*C+H;
}