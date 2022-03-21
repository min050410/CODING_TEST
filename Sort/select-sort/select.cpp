#include <iostream>
using namespace std;

int n, m, key, temp;
int arr[1000];

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> m;
        arr[i] = m;
    }

    for (int i=0; i<n; i++){
        key = i;
        for (int j=i; j<n; j++){
            if(arr[key] > arr[j]){
                key = j;
            }
        }
        //swap
        temp = arr[i];
        arr[i] = arr[key];
        arr[key] = temp;
    }

    for (int i=0; i<n; i++){
        cout << arr[i] << '\n';
    }
}

