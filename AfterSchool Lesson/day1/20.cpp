#include <iostream>
#include <vector>
#define ll long long
#define inf 0x7fffffff

using namespace std;

int n;
int k;
vector<int> a;
vector<int> b;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> k;
        a.push_back(k);
    }
    for (int i=0; i<n; i++) {
        cin >> k;
        b.push_back(k);
    }
    for (int i=0; i<n; i++) {
        if (a[i] == b[i]) {
            cout << 'D' << '\n';
            continue;
        }
        else if (a[i] == 1) {
            if (b[i] == 2) {
                cout << 'B' << '\n';
            }
            if (b[i] == 3) {
                cout << 'A' << '\n';
            }
        }
        else if (a[i] == 2) {
            if (b[i] == 1) {
                cout << 'A' << '\n';

            }
            else if (b[i] == 3) {
                cout << 'B' << '\n';
            }
        }
        else if (a[i] == 3) {
            if (b[i] == 1) {
                cout << 'B' << '\n';
            }
            if (b[i] == 2) {
                cout << 'A' << '\n';
            }
        }
    }
}
