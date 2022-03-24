// 소수 찾기

#include <iostream>
#include <vector>

using namespace std;

int number = 1000;
int a[10000];
vector<int> res;
int n, k;
int cnt;

int main(){

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> k;
        res.push_back(k);
    }

    // 에라토스테네스의 체 알고리즘
    // 1. 초기화
    // 2. 2부터 시작해서 특정 수의 배수에 해당하는 수 모두 지우기
    // 3. 이미 지워진 숫자가 아니라면 그 배수부터 출발하여, 가능한 모든 숫자 지우기
    // 4. 2부터 시작하여 남아있는 수 모두 출력

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

    // 출력 test
//    for (int i=2; i<number; i++){
//        if(a[i] != 0){
//            cout << a[i] << " ";
//        }
//    }

    for(const auto &r: res){
        if(a[r]!=0){
            cnt++;
        }
    }

    cout << cnt;
}