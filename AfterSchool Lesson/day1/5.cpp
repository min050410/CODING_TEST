#include <iostream>
#include <algorithm>
#define ll long long
#define inf 0x7fffffff

using namespace std;

int a, b;
int sex;
int age;

int main() {
    scanf("%d-%d", &a, &b);
    sex = b/1000000;
    age = (a/100000)*10+(a%100000)/10000;
    if (sex == 1 || sex == 2) {
        age = 119 - age + 1;
    }
    else {
        age = 19 - age + 1;
    }
    if (sex == 1 || sex == 3) {
        printf("%d %c",age,'M');
    }
    else {
        printf("%d %c",age,'W');
    }
}