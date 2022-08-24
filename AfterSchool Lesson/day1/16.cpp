#include <iostream>
#define ll long long
#define inf 0x7fffffff

using namespace std;

string s1, s2;
int arr[1000];
int arr2[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    for (int i=0; i<s1.size(); i++) {
        arr[s1[i]]++;
        arr2[s2[i]]++;
    }
    for (int i=0; i<1000; i++) {
        if (arr[i] != arr2[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
