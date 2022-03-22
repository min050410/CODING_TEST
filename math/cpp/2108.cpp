// 통계학 

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, a;
int arr[500001];
vector<int> v;
int mid, lot;
int range;
double ave;
int max_n, idx;

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a;
        ave += a;
        v.push_back(a);
        arr[v[i]+4000]++;
    }

    ave /= n;
    ave = floor(ave + 0.5);
    // sort
    sort(v.begin(), v.end());

    mid = v[v.size()/2];

    for (int i=0; i<8001; i++){
        if(arr[i] > max_n){
            max_n = arr[i];
            idx = i;
        }
    }

    for (int i=idx+1; i<8001; i++){
        if(arr[i]==max_n){
            idx = i;
            break;
        }
    }

    lot = idx - 4000;

    range = v.back() - v.front();

    cout << ave << '\n';
    cout << mid << '\n';
    cout << lot << '\n';
    cout << range << '\n';

}