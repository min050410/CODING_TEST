// rgb 거리
#include <iostream>
using namespace std;

int dp[10000][3];
int table[10000][3];
int result;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> table[i][0] >> table[i][1] >> table[i][2];
  }
  for(int i=0; i<3; i++){
    dp[0][i] = table[0][i];
  }
  for(int i=1; i<=n; i++){
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + table[i][0];
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + table[i][1];
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + table[i][2];
  }
  
  // cout << dp[n][0] << "\n";
  // cout << dp[n][1] << "\n";
  // cout << dp[n][2] << "\n";
  result = min(min(dp[n][0],dp[n][1]), dp[n][2]);
  cout << result;
}
