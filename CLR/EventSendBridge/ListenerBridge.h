#pragma once
#include "gevent.h"



typedef void(__stdcall* EventCallBack)(void*);

class  ListenerTrans : public GListener
{
public:
	ListenerTrans()
	{
		m_isValid = true;
		m_preMoveMapFun = NULL;
	}
	virtual void OnFire(GEventArgs *args)
	{
		m_preMoveMapFun(args);
	}
	bool IsValid()
	{
		return m_isValid;
	}
	void SetValid(bool isValid)
	{
		m_isValid = isValid;
	}
	bool RegisterCallback(void* fun)
	{
		m_preMoveMapFun = EventCallBack(fun);
		//cxp 注册时设成有效
		m_isValid = true;
		return true;
	}

private:
	EventCallBack		m_preMoveMapFun;
private:
	bool	m_isValid;
};