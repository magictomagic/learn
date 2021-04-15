// [3, 7, 6]
// [1, 3, 2]
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	string str = "";
	cin>>str;
	int len = str.size();
	if(str[0] >= 'A' && str[0] <= 'Z'){
		str = str.substr(1, len - 1);
	}
	// cout<<str;
	len = str.size();
	int up = 0, lo = 0, head = 0, tail = 0;
	bool flag = true;
	// bool ans = true;
	// for(int i = 0; i < len; i++){
	for(auto t:str){
		if(t >= 'A' && t <= 'Z'){
			up ++;
		}else{
			lo ++;
		}
	}
	
	if(up == len || lo == len){
		cout<<"True";
		// flag = true;
	}else{
		// flag = false;
			cout<<"False";
	}

	
	return 0;
}