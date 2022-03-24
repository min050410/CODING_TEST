// 소수

#include <iostream>

using namespace std;

int number = 10000;
int a[1000000];
int n, m;
int first_Num;
int flag, cnt;

int main(){

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i=2; i<number; i++){
        a[i] = i;
    }

    for (int i=2; i<number; i++){
        if(a[i] == 0){
            continue;
        }
        for (int j=2*i; j<=number; j+=i){
            a[j] = 0;
        }
    }

    for (int i=n; i<=m; i++){
        if(a[i] != 0){
            if(flag == 0){
                first_Num = a[i];
                flag = 1;
            }
            cnt += a[i];
        }
    }
    if(first_Num == 0){
        cout << -1;
    }
    else {
        cout << cnt << '\n';
        cout << first_Num;
    }


}