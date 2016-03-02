 ///
 /// @file    stringstream.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-01 23:05:57
 ///
 
#include <iostream>
#include <sstream>
#include <string>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::stringstream;
using std::istringstream;
using std::ostringstream;

//字符串的格式化
//对于字符串输入流而言，可以把字符串转成特定的类型
//对于字符串输出流而言，可以把特定的类型转成字符串

string int_string(int val){
	ostringstream sso;
	sso<<val;
	return sso.str();
}

int main(void){
	int val1 = 50;
	int val2 = 1024;
	stringstream ss;
	ss<<"val1= "<<val1<<" "<<"val2= "<<val2<<endl;
	string str = ss.str();
	cout<<str<<endl;

	cout<<"val1(int to string):"<<int_string(val1)<<endl;

	cout<<"-----------------------------"<<endl;
	int a,b;
	string s1,s2;
	istringstream ss1(str);
	ss1>>s1>>a>>s2>>b;
	cout<<"s1 ="<<s1<<endl;
	cout<<"a ="<<a<<endl;	
	cout<<"s2 ="<<s2<<endl;
	cout<<"b ="<<b<<endl;
#if 0
	cout<<"-----------------------------"<<endl;

	int c,d;
	string s3,s4;
	istringstream ss2(str);
	ss2>>c>>s3>>d>>s4;
	cout<<"c ="<<c<<endl;
	cout<<"s3 ="<<s3<<endl;	
	cout<<"d ="<<d<<endl;
	cout<<"s4 ="<<s4<<endl;
#endif
	return 0;
}
