 ///
 /// @file    iostream_1.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-01 06:08:59
 ///
 
#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void printCin(){
	cout<<"cin.bad() ="<<cin.bad()<<endl;
	cout<<"cin.fail() ="<<cin.fail()<<endl;
	cout<<"cin.eof() ="<<cin.eof()<<endl;
	cout<<"cin.good() ="<<cin.good()<<endl;
}

int test(void){

	printCin();
	int num;
	while(cin>>num){
		cout<<num<<endl;
	}
	
	printCin();

	cout<<"重置IO流的状态"<<endl;
	cin.clear();
	printCin();

	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	string s;
	cin>>s;
	cout<<s<<endl;

	return 0;
}

int main(void){
	int num;
	while(cin>>num,!cin.eof()){
		if(cin.bad()){
			cout<<"系统级故障，不可恢复"<<endl;
			return -1;
		}else if(cin.fail()){
			cout<<"可以恢复的错误，重置IO流的状态"<<endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			continue;
		}
		cout<<"num ="<<num<<endl;
	}

	return 0;
}
