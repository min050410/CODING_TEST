// 그룹 단어 체커

#include<iostream>

using namespace std;

int n, cnt;

bool isGroup(const char *a){
    int arr[200]={};
    for (int i=0; a[i]!='\0'; i++){
        if (arr[a[i]]>=1){
            if(a[i] != a[i-1]){
                return false;
            }
        }
        else{
            arr[a[i]]++;
        }
    }
    return true;
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        char input[101]={};
        cin >> input;
        if(isGroup(input)) {
            cnt++;
        }
    }
    cout << cnt;
}