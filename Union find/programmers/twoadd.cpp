// 두개 뽑아서 더하기

#include <string>
#include <vector>

using namespace std;
int checked[10000];

void r(int x, int n, vector<int> numbers) {
    if (x == n-1) {
        return;
    }
    for (int i=0; i<=n-1; i++){
        if (i != x && !checked[numbers[x]+numbers[i]]){
            checked[numbers[x]+numbers[i]] = 1;
            r(x+1, n, numbers);
        }
    }
}

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    r(0, n, numbers);
    vector<int> answer;
    
    for (int i=0; i<10000; i++){
        if (checked[i]){
            answer.push_back(i);
        }
    }
    return answer;
}