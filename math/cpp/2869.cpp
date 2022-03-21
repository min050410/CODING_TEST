// 달팽이는 올라가고 싶다

#include <iostream>

using namespace std;

int a, b, v;
int day;

int main(){
    cin >> a >> b >> v;

    int day = (v - b) / (a - b);


    if( (v - b) % (a - b) != 0 ) {
        day++;
    }

    cout << day;
}
