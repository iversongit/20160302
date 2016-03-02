 ///
 /// @file    wordstatic.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-03-02 03:19:20
 ///
 
#include <iostream>
#include <string>
#include <fstream>
#include <strings.h>
#include <string.h>
#include <vector>
//#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::vector;

class WordStatic{
	public:
	void read_file();
	void write_file();
	private:
		string _ss;
		int _num;
};

vector<WordStatic> vec;
vector<WordStatic>::iterator it;

void WordStatic::read_file(){
	ifstream ifs("The_Holy_Bible.txt");
	if(!ifs.good()){
		cout<<"ifstream open fail"<<endl;
		return;
	}

	string s;
	char c[4];

	while(ifs >> s){
		bzero(c,sizeof(c));
		strcpy(c,s.c_str());
		if(c[0] >= '0' && c[0] <= '9') continue;
		for(it=vec.begin(); it != vec.end(); it++){
			if(it->_ss == s){
				++(it->_num);
				break;
			}
		}
		if(it == vec.end()){
			WordStatic ww;
			ww._ss = s;
			ww._num = 1;
			vec.push_back(ww);
		}
	}
}

void WordStatic::write_file(){
//	int c[10];
//	string s;
//	std::sort(vec.begin(),vec.end());
	for(it=vec.begin(); it != vec.end(); it++){
//		bzero(c,sizeof(c));
//		s = static_cast<string>(it->_ss);
//		strcpy(c,s.c_str());
//		if(c[0] == 'a' || c[0] == 'A'){
			cout<<it->_ss<<": "<<it->_num<<endl;
//		}
	}
	
}

int main(){
	WordStatic w;
	w.read_file();
	w.write_file();
	return 0;
}
