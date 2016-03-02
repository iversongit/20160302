 ///
 /// @file    fstream.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-01 21:43:14
 ///
 
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

int test(void){
	ifstream ifs("iostream_1.cpp");
	if(!ifs.good()){
		cout<<"ifstream open fail"<<endl;
		return -1;
	}
	vector<string> vec;
	string ss;
	while(getline(ifs,ss)){
		vec.push_back(ss);
	}
	vector<string>::iterator it = vec.begin();
	for(;it != vec.end(); ++it){
		cout<<*it<<endl;
	}
	return 0;
}

int main(void){
	ifstream ifs("iostream_1.cpp");
	if(!ifs.good()){
		cout<<"ifstream open fail"<<endl;
		return -1;
	}

	ofstream ofs("test.txt");
	if(!ofs.good()){
		cout<<"ofstream open fail"<<endl;
		return -1;
	}
	
	string ss;
	while(getline(ifs,ss)){
		ofs<<ss<<endl;		
	}

	return 0;
}
