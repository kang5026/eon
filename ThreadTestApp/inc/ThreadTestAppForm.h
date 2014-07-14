#ifndef _THREAD_TEST_APP_FORM_H_
#define _THREAD_TEST_APP_FORM_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>
#include "SecondThread.h"

class SecondThread;

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;
using namespace Tizen::Base::Runtime;

class ThreadTestAppForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Base::Runtime::IRunnable	// 스레드를 위한 상속

{
public:
	ThreadTestAppForm(void);
	virtual ~ThreadTestAppForm(void);
	bool Initialize(void);

	bool isRunning;
	virtual Object* Run(void);	// 스레드 동작
	int count;
	Thread* pThread;
	Thread* pThread2;

	SecondThread* pSecondThread;

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

protected:
	static const int IDA_BUTTON_OK = 101;
};

#endif	//_THREAD_TEST_APP_FORM_H_
