// 스타트와 링크
// 백트래킹으로 스타트팀과 링크팀을 나누는 알고리즘을 생각하는데 이틀걸린 문제
// 3가지의 백트래킹 방법이 사용됨
// 1. 스타트 팀의 개수를 구하고 개수가 n/2이면 나머지는 링크 팀으로 채우기
// 2. 시작은 무조건 스타트 팀으로 시작 (team{1, 1, 2, 2} 와 team{2, 2, 1, 1}이 같으므로}
// 3. 경우의 수를 반으로 나눔 (중복 제거) 

#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long
#define inf 0x7fffffff
using namespace std;

int team[10000];
int n;
int arr[1000][1000];
bool half_case = true;
int m = inf;

// 팀을 모두 구한 뒤 각각의 점수를 구하고 뺀 값의 절댓값을 구함
void score_calc() {
    // 스타트팀
    int s = 0;
    // 링크팀
    int l = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            // 같은 사람이니 continue;
            if (i == j) continue;
            // 같은 스타트 팀인 경우
            if (team[i] == 1 && team[j] == 1) {
                s += arr[i][j];
            }
            // 같은 링크 팀인 경우
            if (team[i] == 2 && team[j] == 2) {
                l += arr[i][j];
            }
        }
    }
    // 절댓값의 최소
    m = min(m, abs(s - l));
}

int checked(int x) {
    int cnt = 0;
    int cnt2 = 0;
    for (int i=0; i<x; i++) {
        if (team[i] == 1)
            cnt++;
        if (team[i] == 2)
            cnt2++;
    }
    // 스타트 또는 링크팀이 n/2이면 나머지를 다른 팀으로 채우기
    if (cnt == n/2) {
        for (int i=x; i<n; i++)
            team[i] = 2;
        return 1;
    }
    else if (cnt2 == n/2) {
        for (int i=x; i<n; i++)
            team[i] = 1;
        return 1;
    }
    // n/2가 아니면 backtracking 함수 계속 실행
    else {
        return 0;
    }
}

void backtracking(int x) {
    // 재귀 종료
    if (x == n) {
        // 경우의 수를 반으로 나누기 위함
        if (half_case) {
//            for (int i = 0; i < n; i++) {
//                cout << team[i] << ' ';
//            }
//            cout << '\n';
            half_case = false;
            score_calc();
            return;
        }
        else {
            half_case = true;
            return;
        }
    }
    // i가 1이면 스타트팀, i가 2이면 링크팀
    for (int i=1; i<3; i++) {
        team[x] = i;
        // 만약 이미 한 팀의 정원이 충족하면 backtracking에 n 값을 줘서 다음 재귀에 종료
        if (checked(x)) backtracking(n);
        // 첫번째 team[0]은 무조건 1로
        else if (x == 0 && i == 2) return;
        else backtracking(x + 1);
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    backtracking(0);
    // 최솟값 출력
    cout << m;
}