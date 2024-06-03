#include "stdafx.h"
#include "EventSendClass.h"
using namespace std;

EventSendClass::EventSendClass() {
}
EventSendClass::~EventSendClass() {
}

CGEvent* EventSendClass::GetSendEvent1() {
	return &sendEvent1;
}
CGEvent* EventSendClass::GetSendEvent2() {
	return &sendEvent2;
}

void EventSendClass::SendEvent1() {
	FireEvent::Fire(&sendEvent1, NULL);
}

void EventSendClass::SendEvent2() {
	FireEvent::Fire(&sendEvent2, NULL);
}

void EventSendClass::SendEvent1(GEventArgs* args) {
	FireEvent::Fire(&sendEvent1, args);
}
void EventSendClass::SendEvent2(GEventArgs* args) {
	FireEvent::Fire(&sendEvent2, args);
}