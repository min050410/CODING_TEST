// 단어 수학
// 구현은 쉬웠음 과정을 떠올리기 어려운 문제
// 풀어야 하는 과제 : 하나에 알파벳에 9, 8, 7 ... 1 중 숫자 지정, 지정한 후 더해서 최댓값 구하기
// 숫자를 지정하는 방법 : greedy적으로 가장 큰 자릿수에 많이 배치된 알파벳을 높은 숫자로 지정
/* 
1. 큰 자릿수에 많이 배치된 알파벳을 구하는 방법? 알파벳이 N의 자릿수에 있다면 알파벳의 값에 N을 더함
2. 구한 값을 가지고 내림차순 정렬 
3. 내림차순 정렬 순으로 알파벳에 9부터 차례대로 숫자 지정
*/

// 예시
/* 
만약 G가 100의 자릿수에 한개 있고 1의 자릿수의 한개 있다면 G의 값은 101이 됨. -> map 자료형으로 알파벳과 값 둘 다 저장
똑같은 방식으로 A가 10000의 자릿수에 있다면 A의 값은 10000이 됨.
A가 G보다 우선순위가 높으므로 A에 가장 높은 수인 9를 지정함.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#define inf 0x7fffffff
#define ll long long

using namespace std;
ll n;
vector<string> v;
map<char, ll> m;
string a;
ll cnt;
int max_length;

bool comp(pair<char, ll> a, pair<char, ll> b) {
    return a.second > b.second;
}

// 가장 높은 자리가 관건이겠네요.
void solve() {
    cin >> n;   

    for (int i=0; i<n; i++) {
        cin >> a;
        v.push_back(a);
        for (int j=0; j<a.length(); j++) {
            m.count(a[j]) ? m[a[j]] += pow(10, a.length()-j-1) : m[a[j]] = pow(10, a.length()-j-1);
        }
    }

    vector<pair<char,ll>> vec( m.begin(), m.end() );
    sort(vec.begin(), vec.end(), comp);

    int j=9;
    for (int i=0; i<vec.size(); i++) {
        m[vec[i].first] = j;
        j--; 
    }

    // 숫자 만들기
    for (int i=0; i<n; i++) {
        for (int j=0; j<v[i].size(); j++) {
            cnt += m[v[i][j]] * pow(10, v[i].size()-j-1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    cout << cnt;
    return 0;
}

