// 카펫 

#include <string>
#include <vector>
#include <cmath>
#define db double

db m;
db s;

using namespace std;

vector<int> solution(int b, int y) {
    db b1 = b;
    db y1 = y;
    vector<int> answer;
    s = (b1+4)/2;
    m = b1+y1;

    // x^2 - sx + mx 이차방정식

    db f2 = (s + sqrt(pow(s,2) - (4*m)))/2;
    db f1 = m/f2;
    answer.push_back(round(f2));
    answer.push_back(round(f1));
    return answer;
}