// 분해합

#include <iostream>
#include <cstring>
using namespace std;

int n;

int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int temp = n;
    int digit = 0;
    // 자릿수
    while (temp){
        temp/=10;
        digit++;
    }
    int begin = n - digit * 9;
    char s[10];
    int sum = 0;
    bool find = false;
    for (int i=begin; i<=n; ++i){
        sprintf(s, "%ld", i);
        sum = i;
        for (int j=0; j<strlen(s); j++){
            sum += s[j] - '0';
        }
        if (sum == n){
            find = true;
            cout << i << '\n';
            break;
        }
    }
    if (!find) cout << "0\n";

    return 0;
}