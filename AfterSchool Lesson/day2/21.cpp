#include <iostream>
using namespace std;

int arr[1000];
int arr2[1000];
int aPoint;
int bPoint;

int flag;

// 비기면 승점 1
// 이기면 승점 3


int main() {
    for (int i=0; i<10; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<10; i++) {
        cin >> arr2[i];
    }
    for (int i=0; i<10; i++) {
        if (arr[i] > arr2[i]) {
            aPoint+=3;
            flag = 1;
        }
        else if (arr[i] == arr2[i]) {
            aPoint++;
            bPoint++;
        }
        else {
            bPoint+=3;
            flag = 2;
        }
    }

    cout << aPoint << ' ' << bPoint << '\n';
    if (aPoint > bPoint) {
        cout << 'A';
    }
    else if (bPoint > aPoint) {
        cout << 'B';
    }
    else {
        if (flag == 0) {
            cout << 'D';
        }
        else if (flag == 1) {
            cout << 'A';
        }
        else {
            cout << 'B';
        }
    }
}