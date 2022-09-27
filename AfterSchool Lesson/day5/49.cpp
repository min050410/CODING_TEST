#include <iostream>
using namespace std;
int f[100];
int r[100];
int n;
int main() {
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>f[i];
    }
    for (int i=0;i<n;i++){
        cin>>r[i];
    }
    int cnt = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (r[j] <= f[i]) {
                cnt += r[j];
            }
            else cnt += f[i];
        }
    }
    cout << cnt;
}