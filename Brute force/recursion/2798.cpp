// 블랙잭

#include <iostream>
using namespace std;

int n, m, k;
int sumNum;
int maxNum;

int arr[100];
int a[100];
bool check[100];

void func(int cnt){
    // end
    if(cnt == 3){
        sumNum = 0;
        for (int i=0; i<3; i++){
        // cout << a[i] << " ";
            sumNum += a[i];
        }
        if (maxNum < sumNum){
            if (sumNum <= m){
                maxNum = sumNum;
            }
        }
        return;
    }

    //next
    for (int i=0; i<n; i++){
        if(!check[i]){
            a[cnt] = arr[i];
            check[i] = true;
            func(cnt+1);
            check[i] = false;
        }
    }
}


int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> k;
        arr[i] = k;
    }
    func(0);

    cout << maxNum;
    return 0;
}