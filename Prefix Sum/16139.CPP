// 인간 - 컴퓨터 상호작용
// 50점 이유 기존에 테스트 케이스 for문에 prefix sum 연산을 해 시간 복잡도가 높았지만 
// 26개의 알파벳을 이차원 배열을 이용해 밖에서 미리 계산함으로써 시간 복잡도를 낮추었다.

#include <iostream>
#include <vector>
using namespace std;

int arr[100][200001];
string s;
char key;
int n;
int a, b;
int ap;
vector<int> ans;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    cin >> n;

    // a to z
    for (int i=0; i<27; i++) {
        for (int j = 0; j < s.length(); j++) {
            // prefix sum 계산
            if (s[j] == 96 + i) {
                arr[i][j] = 1;
            }
            if (i != 0) {
                arr[i][j] += arr[i][j - 1];
            }
        }
    }

    // 테스트 케이스 시작
    for (int t = 0; t < n; t++) {
        cin >> key >> a >> b;

//      for (int i=0; i < s.length(); i++) {
//          cout << arr[i] << ' ';
//      }
//      cout << '\n';

        // key가 a이면 0
        // 예외처리1 : 시작부터 찾는 문자가 나온 경우
        if (a == 0 && arr[key-96][a] == 1) {
            // 문자 갯수 1 증가
            ap++;
        }
        // 예외처리2 : 찾는 구간중 왼쪽에 문자가 있는 경우
        if (a!=0 && arr[key-96][a-1] != arr[key-96][a]) {
            // 문자 갯수 1 증가
            ap++;
        }

        // 구간 합을 이용해 문자의 개수를 구함
        ans.push_back(arr[key-96][b] - arr[key-96][a] + ap);
        // 초기화
        ap = 0;
    }

    for (const auto as: ans) {
        cout << as << '\n';
    }

    return 0;
}