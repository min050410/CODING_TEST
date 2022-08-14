// 덱

#include <iostream>
#include <deque>
#include <string>

using namespace std;

string str;
int n;
int x;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
		
	deque<int> dq;
	
	cin >> n;
	
	while(n--){
		cin >> str;
		
		if(str=="push_front"){
			cin >> x;
			dq.push_front(x);
		}
		
		else if(str=="push_back"){
			cin >> x;
			dq.push_back(x);
		}
		
		else if(str=="pop_front"){
			if(!dq.empty()){
				cout << dq.front() <<"\n";
				dq.pop_front();
			}
			else
				cout << "-1\n";
		}
		
		else if(str=="pop_back"){
			if(!dq.empty()){
				cout << dq.back()<<"\n";
				dq.pop_back();
			}
			else
				cout << "-1\n";
		}
		
		else if(str=="size"){
			cout << dq.size() <<"\n";
		}
		
		else if(str=="empty"){
			cout << dq.empty() <<"\n";
		}
		
		else if(str=="front"){
			if(!dq.empty()){
				cout << dq.front() <<"\n";
			}
			else
				cout << "-1\n";
		}
		
		else if(str=="back"){
			if(!dq.empty()){
				cout << dq.back() <<"\n";
			}
			else
				cout << "-1\n";
		}
	}		
	return 0;
}