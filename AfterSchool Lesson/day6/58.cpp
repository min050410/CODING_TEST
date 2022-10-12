#include <iostream>
using namespace std;
int n;
int arr[1000];
int cnt;

void preorder (int x) {
    if (arr[x]) {
        cnt++;
        if (cnt < 7) cout << arr[x] << " ";
        else cout << arr[x];
        preorder((2*x)+1);
        preorder((2*x)+2);
    }
}

void inorder (int x) {
    if (arr[x]) {
        cnt++;
        inorder((2*x)+1);
        if (cnt < 7) cout << arr[x] << " ";
        else cout << arr[x];
        inorder((2*x)+2);
    }
}

void postorder (int x) {
    if (arr[x]) {
        cnt++;
        postorder((2*x)+1);
        postorder((2*x)+2);
        if (cnt < 9) cout << arr[x] << " ";
        else cout << arr[x];
    }
}

int main() {
    for (int i=0;i<7;i++) {
        cin>>arr[i];
    }
    preorder(0);
    cnt = 0;
    cout<<'\n';
    inorder(0);
    cnt = 0;
    cout<<'\n';
    postorder(0);
}
