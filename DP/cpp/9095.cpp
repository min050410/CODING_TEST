// 1,2,3 더하기

#include <iostream>
using namespace std;

int m[100];
int num[100];
int big;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  
  for(int i=0; i<n; i++){
    cin >> num[i];
    big = max(big, num[i]);
  }

  m[1]=1;
  m[2]=2;
  m[3]=4;

  for(int i=4; i<=big; i++){
    m[i]=m[i-1]+m[i-2]+m[i-3];
  }
  
  for(int i=0; i<n; i++){
    cout << m[num[i]] << "\n";
  }
}
