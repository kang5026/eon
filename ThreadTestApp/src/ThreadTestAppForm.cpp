/*IRunninable 인터페이스를 상속 받은 스레드 테스트 앱입니다.
앱 실행과 동시에 스레드가 동작하며 5초뒤에 break;로 스레드 종료합니다.
스레드 동작동안 폼화면이 나타나지않으며 5초뒤에 스레드 종료후 동작합니다.
메인 폼에 스레드를 상속시켜서 그런 것으로 보입니다.
스레드로 돌릴 기능들은 따로 클래스를 만들어서 스레드 돌려야 할 듯 합니다.*/

/*join() 함수 활성화하면 스레드 종료후 폼이 보여진다.
 * 스레드의 동작이 종료될때까지 다른 작업을 멈추는 함수이다.*/

#include "ThreadTestAppForm.h"
#include "AppResourceId.h"


ThreadTestAppForm::ThreadTestAppForm(void)
{
	isRunning = true;
	count = 0;
}

ThreadTestAppForm::~ThreadTestAppForm(void)
{
	isRunning = false;
}

bool
ThreadTestAppForm::Initialize(void)
{
	result r = Construct(IDL_FORM);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}
result
ThreadTestAppForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID
	Tizen::Ui::Controls::Button* pButtonOk = static_cast< Button* >(GetControl(IDC_BUTTON_OK));
	if (pButtonOk != null)
	{
		pButtonOk->SetActionId(IDA_BUTTON_OK);
		pButtonOk->AddActionEventListener(*this);
	}

	pThread = new Thread;
	pThread->Construct(*this);
	pThread->Start();
	//pThread->Join(); 	// 활성화하면 스레드가 종료된 후 폼이 보여진다.

	pThread2 = new Thread;
	pSecondThread = new SecondThread();
	pThread2->Construct(*pSecondThread);
	pThread2->Start();
	return r;
}

result
ThreadTestAppForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	pThread->Stop();
	delete pThread;
	pThread = null;

	return r;
}

void
ThreadTestAppForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
	case IDA_BUTTON_OK:
		AppLog("OK Button is clicked!\n");
		break;
	default:
		break;
	}
}

void
ThreadTestAppForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}

Object*
ThreadTestAppForm::Run(){
	isRunning = true;
	while(isRunning){
		count++;

		AppLog("Thread동작입니다. [%d] \n", count);
		Tizen::Base::Runtime::Thread::Sleep(1000);
		if(count == 5){
			//pThread->Stop();
			break;
		}
	}
	return null;
}
