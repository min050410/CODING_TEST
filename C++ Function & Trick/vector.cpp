#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
using namespace std;
int main() {
    vector<int> v={1,2,3};
    // x보다 크거나 같은 최소 원소 위치
    cout<<lower_bound(v.begin(),v.end(),2)-v.begin();
    // x보다 큰 최소 원소 위치
    cout<<upper_bound(v.begin(),v.end(),3)-v.begin();
    // 정렬
    sort(v.begin(),v.end());
    // 원소를 반대로
    reverse(v.begin(),v.end());
    // 가장 큰 원소 반환
    cout<<*max_element(v.begin(),v.end());
    // 시작 위치 부터 끝 위치까지 value+=value로 초기화 {2,4,6}
    iota(v.begin(),v.end(),2);
    // 원소 삭제
    v.erase(v.begin()+2);
    // 배열 초기화
    int arr[100]; memset(arr, -1, sizeof(arr));
    // 채우기
    fill(v.begin(),v.end(),1);
    // 연속한 같은 원소들을 하나로 만들기
    v.erase(unique(v.begin(),v.end()),v.end());
    // 값 교체
    int a=1,b=2; swap(a,b);
}