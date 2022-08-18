// 냅색문제

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll n, m;
vector<ll> setA;
vector<ll> setB;
ll arr[1000000];

// 나뉜 리스트를 조합으로 변경
// 조합의 모든 경우의 수가 있어야 m - (setA원소) >= (setB원소) 가 되는 모든 가짓수를 구할 수 있다.
void Combination(int Left, int Right, vector<ll>& Set, ll sum) {
    if(Left > Right) {
        Set.push_back(sum);
        return;
    }
    Combination(Left + 1, Right, Set, sum);
    Combination(Left + 1, Right, Set, sum + arr[Left]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    //meet in the middle
    Combination(0, n/2, setA, 0);
    Combination(n/2 + 1, n-1, setB, 0);

    sort(setB.begin(), setB.end());
    ll ans = 0;
    for (int i=0; i<setA.size(); i++) {
        // upper_bound로 만족하는 경우들을 한번에 구함
        ans += upper_bound(setB.begin(), setB.end(), m - setA[i]) - setB.begin();
    }

    cout << ans;
}