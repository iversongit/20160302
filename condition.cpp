 ///
 /// @file    homework4_condition.cpp
 /// @iverson	(1564329410@qq.com)
 /// @date    2016-02-29 05:18:03
 ///
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>

using std::cout;
using std::endl;

class Mutexlock{                  //互斥锁类
	public:
		Mutexlock();
		~Mutexlock();
		void lock();
		void unlock();
//	private:
		pthread_mutex_t _mutex;   //由于pthread_cond_wait中要用到_mutex,为方便起见，
};                                //将_mutex设置于public下

class Condition{                  //条件变量类
	public:
		Condition();
		~Condition();
		void wait();
		void signal();
		void broadcast();
	private:
		pthread_cond_t _cond;
};

Condition cond;
Mutexlock mutex;

/*---------Mutexlock区------------*/
Mutexlock::Mutexlock(){
	cout<<"Mutexlock()"<<endl;
	pthread_mutex_init(&_mutex,NULL);
}

Mutexlock::~Mutexlock(){
	cout<<"~Mutexlock()"<<endl;
	pthread_mutex_destroy(&_mutex);
}

void Mutexlock::lock(){
	pthread_mutex_lock(&_mutex);
}

void Mutexlock::unlock(){
	pthread_mutex_unlock(&_mutex);
}

/*---------Condition区------------*/
Condition::Condition(){
	cout<<"Condition()"<<endl;
	pthread_cond_init(&_cond,NULL);
}

Condition::~Condition(){
	cout<<"~Condition()"<<endl;
	pthread_cond_destroy(&_cond);
}

void Condition::wait(){
	pthread_cond_wait(&_cond,&(mutex._mutex));
}

void Condition::signal(){
	pthread_cond_signal(&_cond);
}

void Condition::broadcast(){
	pthread_cond_broadcast(&_cond);
}

void * pthread_func(void* p){
	mutex.lock();
	cout<<"this is child thread"<<endl;
	cond.wait();
	cout<<"waking"<<endl;
	mutex.unlock();
	pthread_exit(NULL);
}

int main(void){
//创建子线程
	pthread_t phid[5];
	for(int i=0; i<5; i++){
		pthread_create(&phid[i],NULL,pthread_func,NULL); 	
	}
	sleep(1);
	mutex.lock();
	cout<<"this is main thread"<<endl;
	mutex.unlock();
//	cond.signal();
//	cond.broadcast();

	for(int j=0; j<5; j++){
		pthread_join(phid[j],NULL);
	}
//	pthread_join(phid,NULL);
	return 0;	
}
