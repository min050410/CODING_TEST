#include <iostream>
#include <queue>

using namespace std;

priority_queue <int,vector<int>,greater<>> pq;

int n, a;

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a;
        pq.push(a);
    }
    for (int i=0; i<n; i++){
        cout << pq.top() << '\n';
        pq.pop();
    }
}