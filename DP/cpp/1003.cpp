// 피보나치 함수

#include <iostream>
#include <algorithm>
using namespace std;
using std::max;
using std::min;

int m[10000];
int m2[10000];
int num[1000];
int big;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for(int i=1; i<=n; i++){
    cin >> num[i];
    big = max(big, num[i]);
  }

  m[0] = m2[1] = 1;
  m[1] = m2[0] = 0;

  for(int i=2; i<=big; i++){
    m[i] = m[i-1] + m[i-2];
    m2[i] = m2[i-1] + m2[i-2];
      
  }

  for(int i=1; i<=n; i++){
    cout << m[num[i]] << " " << m2[num[i]] << "\n";
  }
}
