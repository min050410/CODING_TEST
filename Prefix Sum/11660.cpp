// 구간합 구하기 5
// 구간 합 2차원 배열 문제이다
// 한개의 줄마다 prefix sum을 계산해 구간 합을 구했다 
// O(n^2) 시간복잡도이다

#include <iostream>
#include <vector>
using namespace std;

int arr[1025][1025];
int n, m;
int x1, y1, x2, y2;
int cnt;
vector<int> res;

int main(){

    cin >> n >> m;

    for (int i = 1;i <= n; i++){
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            // prefix sum 계산
            arr[i][j] += arr[i][j-1];
        }
    }

//    for (int i = 1;i <= n; i++){
//        for (int j = 1; j <= n; j++) {
//            cout << arr[i][j] << ' ';
//        }
//        cout << '\n';
//    }


    // 구간 합
    for (int i = 0; i < m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j <= x2; j++) {
            cnt += arr[j][y2]-arr[j][y1-1];
        }

        res.push_back(cnt);
        cnt = 0;
    }

    for (const auto &r: res) {
        cout << r << '\n';
    }
    return 0;
}