// WA : 키가 같을 때에서도 분노유발자 처리를 해줘야 했다. 문제에는 큰학생이라고 했는데 좀 이상하다. 

#include <iostream>
#define ll long long
#define inf 0x7fffffff

using namespace std;

int n;
int arr[10000];
int cnt;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int flag = 1;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i]-arr[j]<=0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
//            cout << i << ' ';
            cnt++;
        }
        else {
            flag = 1;
        }
    }
    // 맨 마지막 학생은 분노유발자가 아님
    cout << cnt-1;
}
