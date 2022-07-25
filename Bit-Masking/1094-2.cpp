// 막대기 간단한 비트마스킹 풀이

#include <iostream>
using namespace std;

int main(){
    
    int X; 
    cin >> X;
    int ans = 0;
    for(int i = 0; i<=6; i++){
        if(X & (1<<i)) ans += 1;
    }
    cout << ans;
    return 0;
}