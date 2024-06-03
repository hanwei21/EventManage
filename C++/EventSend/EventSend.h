#pragma once

#include "gdelegatedefine.h";
#include "gevent.h"

typedef class EventSendClass*           PTEventSendClass;

class EVENTSENDEXPORT CGEventSendClass
{
public:
	CGEventSendClass();
	~CGEventSendClass();

	CGEvent* GetSendEvent1();
	CGEvent* GetSendEvent2();
	void SendEvent1();
	void SendEvent2();

	void SendEvent1(GEventArgs* args);
	void SendEvent2(GEventArgs* args);


private:
	DECLARE_DELEGATE(PTEventSendClass);
	
};