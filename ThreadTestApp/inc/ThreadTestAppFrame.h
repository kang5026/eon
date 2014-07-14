#ifndef _THREAD_TEST_APP_FRAME_H_
#define _THREAD_TEST_APP_FRAME_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class ThreadTestAppFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	ThreadTestAppFrame(void);
	virtual ~ThreadTestAppFrame(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_THREAD_TEST_APPFRAME_H_
