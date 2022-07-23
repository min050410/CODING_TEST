// 막대기 pq 풀이

#include <iostream>
#include <queue>
using namespace std;

int main(){
    
    int X; 
    cin >> X;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(64);
    int sum = 64;
    
    while(sum>X){

        int half = pq.top() / 2;
        pq.pop();
        
        pq.push(half);
        pq.push(half);
        
        if(sum - half >= X){
            int mini = pq.top();
            sum -= mini;
            pq.pop();
        }
    }
    cout << pq.size();
    return 0;
}