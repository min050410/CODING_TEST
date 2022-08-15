// 도영이가 만든 맛있는 음식

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 

    int ans=2147483647;
    vector<pair<int,int>> v;

    int n; cin>>n;
    for(int i=0; i<n; i++){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }


    for(int i=1; i<(1<<n); i++){ // 1(00..001) 부터 2^n-1(11..111)까지 (n자리수)
        int a=1, b=0;
        for(int x=0; x<n; x++){ // 최대 n-1칸 shiftleft
            if(i & (1<<x)){ //조건문 결과가 1이면 해당 재료 사용한거임 
                a*= v[x].first;
                b+= v[x].second;
            }
        }
        ans=min(ans, abs(a-b));
    }
    cout<<ans;
    return 0;
}