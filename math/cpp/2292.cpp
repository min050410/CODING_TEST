// 벌집

#include <iostream>

using namespace std;

int n, i;
int cnt;
int number_MAX=1;

int main(){
    cin >> n;
    for (i=0; i<n; i++){
        cnt = i*6;
        number_MAX += cnt;
        if(number_MAX >= n){
            cout << i+1;
            return 0;
        }
    }
}