#include<iostream>
#include<cstring>
using namespace std;

namespace COMP_POS
{
    enum { CLERK, SENIOR, ASSIST, MANAGER };

    void ShowPositionInfo(int pos)
    {
        switch(pos)
        {
            case CLERK:
                cout << "사원" << endl;
                break;
            case SENIOR:
                cout << "주임" << endl;
                break;
            case ASSIST:
                cout << "대리" << endl;
                break;
            case MANAGER:
                cout << "과장" << endl;
        }
    }
}

class NameCard
{
private:
    char * name;
    char * comp_name;
    char * phoneNumber;
    int comp_pos;
public:
    NameCard(char * name,char * comp_name,char * phoneNumber,int comp_pos): comp_pos(comp_pos) {
        this->name = new char[strlen(name) + 1];
        this->comp_name = new char[strlen(comp_name) + 1];
        this->phoneNumber = new char[strlen(phoneNumber) + 1];
        strcpy(this->name ,name);
        strcpy(this->comp_name ,comp_name);
        strcpy(this->phoneNumber ,phoneNumber);
    }
    NameCard(const NameCard& n): comp_pos(n.comp_pos){
        this->name = new char[strlen(n.name) + 1];
        this->comp_name = new char[strlen(n.comp_name) + 1];
        this->phoneNumber = new char[strlen(n.phoneNumber) + 1];
        strcpy(this->name ,n.name);
        strcpy(this->comp_name ,n.comp_name);
        strcpy(this->phoneNumber ,n.phoneNumber);
    }
    void ShowNameCardInfo(){
        cout << this->name << endl;
        cout << this->comp_name << endl;
        cout << this->phoneNumber << endl;
        COMP_POS::ShowPositionInfo(this->comp_pos);
    }
    ~NameCard(){
        delete this->name;
        delete this->comp_name;
        delete this->phoneNumber;
    }
};

int main(void)
{
    NameCard manClerk("Lee", "Busan", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1 = manClerk;
    NameCard manSenior("Hong", "Seoul", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2 = manSenior;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}

