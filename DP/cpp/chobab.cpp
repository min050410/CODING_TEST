// 회전초밥

#include<bits/stdc++.h>
using namespace std;
int cost[21],prefer[21],n,budget,memo[10000001];
int dp(int capacity){
    if(memo[capacity]) return memo[capacity];
    int maxi = 0;
    for(int i = 0; i < n ;i++){
        if(capacity+cost[i] <= budget){
            maxi = max(maxi,dp(capacity+cost[i])+prefer[i]);
        }
    }
    memo[capacity] = maxi;
    return memo[capacity];
}
int main(){
    cin>>n>>budget;
    for(int i=0;i<n;i++){
        cin>>cost[i]>>prefer[i];
    }
    cout<<dp(0);
}