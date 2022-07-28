// XORXORXOR

#include<iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c % 2 == 0)
    {
        cout << a << endl;
    }
    else
    {
        cout << (a ^ b) << endl;
    }
    return 0;
}