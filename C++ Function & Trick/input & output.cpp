#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    string a;
    cout<<endl;
    // 버퍼를 지우는 시간을 줄여줌 
    cout<<'\n';
    // 한줄 입력
    getline(cin,a);
    // 소수점 제외
    cout<<fixed<<setprecision(2);
}