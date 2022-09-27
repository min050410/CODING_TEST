#include <iostream>
#include <cmath>
using namespace std;
double arr[10];
double s;
double M = 101;
int main () {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cin>>arr[j];
            s+=arr[j];
        }
        float res = 0;
        cout<<round(s/9)<<' ';
        for (int j=0; j<9; j++) {
            if (abs(arr[j] - round(s/9)) < M) {
                M = abs(arr[j] - round(s/9));
                res = arr[j];
            }
        }
        cout<<res<<'\n';
        M=101;
        s=0;
    }
}