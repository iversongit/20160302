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
#include <algorithm>

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
	public:
		int _num;
};

vector<WordStatic> vec;
vector<WordStatic>::iterator it;

void WordStatic::read_file(){
	ifstream ifs("The_Holy_Bible.txt");
//	ifstream ifs("fstream.cpp");
	if(!ifs.good()){
		cout<<"ifstream open fail"<<endl;
		return;
	}

	string s;
	char c[15];

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

bool compare(const WordStatic &pst,const WordStatic &pst1 ){
	//return pst._num > pst1._num;
	if(pst._num > pst1._num)
		return true;
	else 
		return false;
}

void WordStatic::write_file(){
	std::sort(vec.begin(),vec.end(),compare);
	for(it=vec.begin(); it != vec.end(); it++){
		//	cout<<it->_ss<<": "<<it->_num<<endl;
			cout<<it->_ss<<": "<<it->_num<<" ";
	}
	
}

int main(){
	WordStatic w;
	w.read_file();
	w.write_file();
	return 0;
}
