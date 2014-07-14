/*
 * SecondThread.h
 *
 *  Created on: Jul 9, 2014
 *      Author: 강성호
 */

#ifndef SECONDTHREAD_H_
#define SECONDTHREAD_H_

#include <FBase.h>

using namespace Tizen::Base;
using namespace Tizen::Base::Runtime;

class SecondThread
	: public Tizen::Base::Runtime::IRunnable
{
public:
	SecondThread();
	virtual ~SecondThread();

	virtual Object *  Run (void);
	int subCount;

	//Thread* pSubThread;
};

#endif /* SECONDTHREAD_H_ */
