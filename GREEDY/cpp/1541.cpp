// 잃어버린 괄호

#include <iostream>
using namespace std;

string s;
int cnt;
int nowNum;
bool flag;

int main() {
    cin >> s;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '-') {
            if (!flag) {
                // '-' 가 가장 먼저 나오는 순간 캐치
                flag = true;
                cnt += nowNum;
                nowNum = 0;
            }
            else {
                cnt -= nowNum;
                nowNum = 0;
            }
        }
        else if (s[i] == '+') {
            if (!flag) {
                cnt += nowNum;
                nowNum = 0;
            }
            else {
                cnt -= nowNum;
                nowNum = 0;
            }
        }
        else {
            // 연산자 이전의 현재 수
            nowNum = (nowNum * 10) + (s[i] - '0');
        }
    }
    // 마지막 한번 더
    if (!flag) {
        cnt += nowNum;
        nowNum = 0;
    }
    else {
        cnt -= nowNum;
        nowNum = 0;
    }
    cout << cnt;
}