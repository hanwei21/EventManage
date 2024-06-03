#pragma once
#include "gevent.h"

class EventSendClass {
public:
	EventSendClass();
	virtual ~EventSendClass();

	CGEvent* GetSendEvent1();
	CGEvent* GetSendEvent2();
	void SendEvent1();
	void SendEvent2();

	void SendEvent1(GEventArgs* args);
	void SendEvent2(GEventArgs* args);

private:
	CGEvent sendEvent1;
	CGEvent sendEvent2;
};