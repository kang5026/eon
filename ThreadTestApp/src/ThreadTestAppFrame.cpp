#include <new>
#include "ThreadTestAppFrame.h"
#include "ThreadTestAppForm.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

ThreadTestAppFrame::ThreadTestAppFrame(void)
{
}

ThreadTestAppFrame::~ThreadTestAppFrame(void)
{
}

result
ThreadTestAppFrame::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Create a form
	ThreadTestAppForm* pThreadTestAppForm = new (std::nothrow) ThreadTestAppForm();
	TryReturn(pThreadTestAppForm != null, false, "The memory is insufficient.");
	pThreadTestAppForm->Initialize();

	// Add the form to the frame
	AddControl(pThreadTestAppForm);

	// Set the current form
	SetCurrentForm(pThreadTestAppForm);

	// Draw the form
	pThreadTestAppForm->Invalidate(true);

	// TODO: Add your frame initialization code here.

	return r;
}

result
ThreadTestAppFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your frame termination code here.
	return r;
}


