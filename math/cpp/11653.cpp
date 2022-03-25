// 소인수 분해

#include <iostream>

using namespace std;

int n;

void printPrimeFactor(int n);

int main(){

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    printPrimeFactor(n);

}

void printPrimeFactor(int n) {
    if(n==1){
        return;
    }
    for (int i=2; i<=n; i++){
        if (n%i == 0){
            cout << i << '\n';
            int div = n/i;
            printPrimeFactor(div);
            break;
        }
    }
}
