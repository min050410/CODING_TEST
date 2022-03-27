// 골드바흐의 추측

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int number = 10001;
int a[1000000];
int n;
int n1, n2;
bool flag;
int idx;
int T;
int temp = 10000;

int main(){

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;

    // 에라토스테네스의 체

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

    for (int k=0; k<T; k++){

        cin >> n;
        vector<pair<int, int>> res;

        for (int i=n/2; a[i]<n; i++){
            if(a[i] != 0){
                n1 = a[i];
                n2 = n - a[i];
                for(int j=0; a[j]<n; j++){
                    // n2가 소수인지 확인
                    if(n2 == a[j]){
                        flag = true;
                        break;
                    }
                }
            }
            if(flag){
                res.emplace_back(n2, n1);
                break;
            }
        }

//        for (int i=0; i<res.size(); i++){
//            if(abs(res[i].first-res[i].second) < temp){
//                temp = abs(res[i].first - res[i].second);
//                idx = i;
//            }
//        }

        cout << res[0].first << ' ' << res[0].second << '\n';
        temp = 10000;
        flag = false;
    }
}