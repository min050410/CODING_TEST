// 1로 만들기

#include <iostream>
using namespace std;

int m[1000000];

int main() {
  int x;
  cin >> x;

  m[2] = m[3] = 1;
  
  for(int i=4; i<=x; i++){
    m[i] = m[i-1] + 1;
    if(i%2==0){
      if(m[i] > m[i/2]+1) m[i] = m[i/2]+1;
    }
    if(i%3==0){
      if(m[i] > m[i/3]+1) m[i] = m[i/3]+1;
    }
  }
  cout << m[x];
}
