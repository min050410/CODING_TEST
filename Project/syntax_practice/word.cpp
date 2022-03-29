#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
bool isChecked[1000];
char command[100];
char one_command;
int command_test;
int cnt = 1;

// 구조체 사용
typedef struct __List
{
    int key;
    basic_string<char> word;
    basic_string<char> mean;
    __List * next;
}List;

// function
void printHelp();
void printHelp(char oneCommand);
// 단어 번호는 1부터 시작 ( 함수의 디폴트 값 )
void addWord(int num = 1);
void showWord(List * &list);
void sortWord();
int & importRandomWord(int size, int & ref);
void methodError();
void inOrderTest();
void randomTest();

List * today_vocabulary = new List;

int main()
{
    today_vocabulary->next = nullptr;
    today_vocabulary->word = "영어단어";
    today_vocabulary->mean = "뜻";
    today_vocabulary->key = 0;

    //system
    cout << "오늘의 단어 공부를 시작합니다." << endl;
    cout << "명령어를 입력해주세요 (help를 입력해 도움말을 볼 수 있어요)" << endl;
    cout << "exit를 입력해 프로그램을 종료합니다." << endl;

    while(strcmp(command, "exit")!=0){
        cin >> command;
        if(strcmp(command, "help")==0){
            printHelp();
            cin >> one_command;
            if(one_command == '+'){
                // 함수 오버로딩
                printHelp(one_command);
            }
        }
        else if(strcmp(command, "add") == 0){
            addWord(cnt);
            cnt++;
        }
        else if(strcmp(command, "show") == 0){
            showWord(today_vocabulary);
        }
        else if(strcmp(command, "sort") == 0){
            sortWord();
        }

        else if(strcmp(command, "test") == 0){
            cout << "순서대로 단어 연습을 하고 싶으시다면 1, 랜덤으로 연습을 하고 싶으시다면 2를 눌러주세요" << endl;
            cin >> command_test;
            if(command_test == 1 || command_test == 2){
                switch (command_test) {
                    case 1:
                        inOrderTest();
                        break;
                    default:
                        randomTest();
                }
            }
            else{
                methodError();
            }
        }
        else if(strcmp(command, "exit") == 0){}
        else{
            methodError();
        }
    }

    cout << "프로그램이 종료되었습니다. 동적할당을 해제합니다.." << endl;
    delete today_vocabulary;
    return 0;
}

void printHelp(){
    cout << "안녕하세요 영어 단어를 쉽게 외우기 위한 랜덤 단어 생성기 프로그램입니다." << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "add : 단어, 뜻 추가하기" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "sort : 단어 a, b, c 순으로 정렬하기" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "test : 시험 보기" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "더 자세한 설명은 +를 입력해 주세요 ( 도움말에서 나갈려면 아무 버튼을 눌러 주세요 )" << endl;
}

void printHelp(char oneCommand){
    if(oneCommand == '+'){
        cout << "--------------------------------------------------------------------" << endl;
        cout << "add를 입력해 차례대로 단어와 뜻을 추가할 수 있습니다." << endl;
        cout << "sort 기능은 vector에 넣어서 sort 라이브러리로 구현했습니다. a b c 순으로 사전처럼 정렬해줍니다." << endl;
        cout << "test 를 치면 넣은 순서대로 시험을 칠 것인지 랜덤으로 시험을 칠 것인지 물어봅니다." << endl;
        cout << "랜덤으로 쳐도 모든 단어를 다 볼 수 있습니다. 시험이 끝나면 점수가 나오고 만점을 받으면 만점이라고 뜹니다." << endl;
        cout << "made by min050410" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "( 도움말에서 나갈려면 아무 버튼을 눌러 주세요 )" << endl;
    }
}

void addWord(int num) {
    char * a = new char;
    char * b = new char;

    List * addedList = new List;
    addedList->key = num;

    cout << "영어 단어를 입력해주세요" << endl;
    cin >> a;
    cout << "뜻을 입력해주세요" << endl;
    cin >> b;

    addedList->word = a;
    addedList->mean = b;

    List * temp = today_vocabulary;

    while(temp->next != nullptr){
        temp = temp -> next;
    }

    temp->next = addedList;
    addedList->next = nullptr;

    cout << "영어 단어 " << a << " 가 정상적으로 삽입되었습니다" << endl;

}

void showWord(List * &list) {
    List * temp = list;
    while(temp != nullptr){
        cout << temp->word << " " << temp->mean << endl;
        temp = temp -> next;
    }
}

void sortWord() {
    // sort
    vector<pair<string, string>> v;
    List * temp = today_vocabulary->next;

    while(temp != nullptr) {
        v.emplace_back(temp->word, temp->mean);
        temp = temp->next;
    }

    // temp 다시 초기화
    temp = today_vocabulary->next;

    int i = 0 ;

    // string 자료형 sort
    sort(v.begin(), v.end());

    while(!v.empty()){
        // cout << v.front().first << " " << v.front().second << '\n';
        temp -> word = v.begin()->first;
        temp -> mean = v.begin()->second;
        temp -> key = i+1;
        if(temp -> next == nullptr){
            break;
        }
        temp = temp -> next;
        v.erase(v.begin());
    }

    cout << "정렬되었습니다. show를 입력해 확인해보세요." << endl;
}

void inOrderTest(){
    int score = 0;
    char answer[100];
    int i = 1;

    cout << "1번부터 순서대로 치는 시험에 오신 것을 환영합니다! 만약 정렬을 했다면 정렬된 순으로 나옵니다.." << endl;
    cout << "그럼 시작하겠습니다." << endl;

    List * temp = today_vocabulary->next;
    while(temp != nullptr){
        cout << i++ << ". "<< temp -> word << endl;
        cin >> answer;
        // const 사용
        const char * nowWord = (temp -> mean).c_str();
        if(strcmp(answer, nowWord) == 0){
            cout << "정답입니다! 현재 점수는 : " << ++score << endl;
        }
        else{
            cout << "오답입니다 ㅠㅠ 정답은 " << temp->mean << " 입니다.." << endl;
        }
        temp = temp -> next;
    }
    cout << "시험이 종료되었습니다. 총 점수는 " << score << " 입니다." << endl;
    if(score == i-1){
        cout << "wow 만점이네요!" << endl;
    }
}

void randomTest(){
    vector<pair<string, string>> v;
    int score = 0;
    char answer[100] = {};
    int num = 1;

    cout << "랜덤으로 나오는 시험에 오신 것을 환영합니다!" << endl;
    cout << "그럼 시작하겠습니다." << endl;

    List * temp = today_vocabulary->next;
    while(temp != nullptr){
        // vector에 삽입
        v.emplace_back(temp->word, temp->mean);
        temp = temp -> next;
    }

    for (int i=0; i<v.size(); i++){
        int ref = 0;
        int &ref2 = importRandomWord(v.size(), ref);
//        cout << ref << '\n';

        cout << num++ << ". "<< v[ref].first << endl;
        cin >> answer;

        // const 사용
        const char * nowWord = (v[ref].second).c_str();
        if(strcmp(answer, nowWord) == 0){
            cout << "정답입니다! 현재 점수는 : " << ++score << endl;
        }
        else{
            cout << "오답입니다 ㅠㅠ 정답은 " << v[ref].second << " 입니다.." << endl;
        }
    }

    cout << "시험이 종료되었습니다. 총 점수는 " << score << " 입니다." << endl;
    if(score == v.size()){
        cout << "wow 만점이네요!" << endl;
    }

    // bool array 초기화
    for (int i=0; i<v.size(); i++){
        isChecked[i] = false;
    }
}

// 반환형으로 참조자 사용, 매개변수 참조자 사용
int & importRandomWord(int size, int &ref){
    srand(time(NULL));
    int i = rand() % size;
    // bool array 사용
    while(isChecked[i]){
        i = rand() % size;
    }
    isChecked[i] = true;
    ref = i;
    return ref;
}

void methodError(){
    cout << "잘못된 명령어입니다. ( help를 입력해 도움말을 보세요 )" << endl;
};
