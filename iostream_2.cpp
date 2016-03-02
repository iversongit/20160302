 ///
 /// @file    iostream_2.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-01 22:01:44
 ///
 
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::fstream;

int test(void){
	//ios::ate对输出流没有用
	//ios::app用于在文件末尾添加数据
	//ofstream ofs("text.txt",std::ios::ate);
	ofstream ofs("test.txt",std::ios::app);
	if(!ofs.good()){
		cout<<"ofstream open fail"<<endl;
		return -1;
	}

	cout<<ofs.tellp()<<endl;
	ofs<<"this is just a test"<<endl;

	cout<<ofs.tellp()<<endl;
	ofs.close();
	return 0;
}

int test1(void){
//ios::app对输入流没有用
//ios::ate模式针对输入流来使用
//	ifstream ifs("test.txt",std::ios::app);
	ifstream ifs("test.txt",std::ios::ate);
	if(!ifs.good()){
		cout<<"ifstream open fail"<<endl;
		return -1;
	}

	cout<<ifs.tellg()<<endl;
	ifs.close();
	return 0;
}

int main(void){
	fstream fs("d1.dat",std::ios::in | std::ios::out);
	if(!fs.good()){
		cout<<"fstream open fail"<<endl;
		return -1;
	}

	int val,i;
	for(i=0; i<10; i++){
		cin>>val;
		fs<<val<<' ';
	}

	cout<<fs.tellp()<<endl;

	fs.seekg(0,std::ios::beg);

	for(i=0; i<10; i++){
		fs>>val;
		cout<<val<<endl;
	}
	fs.close();
	return 0;
}
