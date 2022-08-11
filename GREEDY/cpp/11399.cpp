// ATM

#include <stdio.h>
#include <algorithm>
using namespace std;
 
int main() {
    int N;
    cin >> N;
 
    int* arr = new int[N];
 
    for (int i = 0; i < N; i++)
        cin >> arr[i];
 
    sort(arr, arr + N);
 
    int time = 0, tmp = 0;
    for (int i = 0; i < N; i++) {
        tmp += arr[i];
        time += tmp;
    }
    cout << time;
    return 0;
}