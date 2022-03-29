#include <iostream>
#include <set>

using namespace std;


int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // set의 특징
    // 중복을 없앰
    // 삽입하는 순서에 상관없이 정렬되서 입력이 된다.

    set<int> setNum;
    setNum.insert(5);
    setNum.insert(1);
    setNum.insert(3);
    setNum.insert(4);
    setNum.insert(2);
    setNum.insert(5);

    // set의 size
    cout << "Set size : " << setNum.size() << endl;

    // set의 요소 출력
    for (set<int>::iterator it = setNum.begin(); it!=setNum.end(); ++it){
        cout << ' ' << *it << '\n';
    }

    // set의 요소 찾기
    set<int>::iterator it = setNum.find(3);
    if (it != setNum.end()){
        cout << "found number : \'3\'" << '\n';
    }
    else{
        cout << "not found number : \'3\'" << '\n';
    }

    // set 요소 삭제
    setNum.erase(3);
    for (set<int>::iterator it = setNum.begin(); it!=setNum.end(); ++it){
        cout << *it << '\n';
    }
    return 0;
}