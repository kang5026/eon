/*
 * SecondThread.cpp
 *
 *  Created on: Jul 9, 2014
 *      Author: 강성호
 */

#include "SecondThread.h"

SecondThread::SecondThread() {
	// TODO Auto-generated constructor stub
	subCount = 10;
}

SecondThread::~SecondThread() {
	// TODO Auto-generated destructor stub
}

Object*
SecondThread::Run(){

	while(1){
		subCount++;
		AppLog("subCount : %d\n", subCount);

		Tizen::Base::Runtime::Thread::Sleep(1000);

		if(subCount == 15){
			break;
		}
	}

	return null;
}
