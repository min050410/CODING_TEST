// 계단오르기

#include <iostream>
using namespace std;

int dp[1000];
int table[1000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> table[i];
  }
  dp[0] = table[0];
  dp[1] = table[0] + table[1];
  dp[2] = max(table[1],table[0])+table[2];
  for(int i=3; i<n; i++){
    dp[i] = max(dp[i-2], dp[i-3] + table[i-1]) + table[i];
    // cout << "dp[" << i << "] : " << dp[i] << "\n";
  }
  cout << dp[n-1];
}

