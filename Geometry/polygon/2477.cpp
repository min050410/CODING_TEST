// 참외밭

#include <iostream>
#include <vector>
#define ll long long
#define inf 0x7fffffff
#define N 6
using namespace std;

int k;
int a, b;
// 방향, 길이
pair<int, int> arr[10000];
int s;
int small_s;

int main() {
    cin >> k;
    for (int i=0; i<N; i++){
        cin >> a >> b;
        arr[i].first = a;
        arr[i].second = b;
        if (i == 0 || i == 1 || i == 2) {
            arr[i+N].first = a;
            arr[i+N].second = b;
        }
    }

    for (int i=0; i<N; i++){
        if (arr[i].first == arr[i+2].first && arr[i+1].first == arr[i+3].first) {
            small_s = arr[i+1].second * arr[i+2].second;
            s = (arr[i].second + arr[i+2].second) * (arr[i+1].second + arr[i+3].second);
        }
    }
//    cout << s << ' ' << small_s;
    cout << k * (s - small_s);
}

