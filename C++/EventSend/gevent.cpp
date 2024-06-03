#include "stdafx.h"
#include "gevent.h"
#include <algorithm>
using namespace std;

CGEvent::CGEvent()
{

}

CGEvent::~CGEvent()
{
	m_listeners.clear();
}

void CGEvent::FireEvent(GEventArgs* args)
{
	// 问题说明：数字制图项目反馈在做选择工具的二次开发时，程序有崩溃现象发生。
	// 问题原因：示例A,B监听者共同监听消息M。消息M到来时A处理消息M（处理过程中把B监听者移除并销毁了B），（因发送前使用了监听列表副本）而A处理消息M后再把消息发给已经被销毁的B（已销毁）则挂掉。
	// 修改说明：发送消息前确定对象是否还在监听列表中。
	// 修改人：PJC 2019-11-21（数字制图项目 郭宇反馈 王斗斗、周小飞、裴纪成共同查找问题2~3天）
	if (m_listeners.size() == 0)
		return;
	vector<GListener*> vecListeners = m_listeners; //使用副本，保证"此时监听者"才会被发送消息（在响应消息时，某些响应者会添加/移除监听列表）PJC
	for (vector<GListener*>::iterator itVec = vecListeners.begin(); itVec != vecListeners.end(); itVec++)
	{
		if (find(m_listeners.begin(), m_listeners.end(), (*itVec)) != m_listeners.end())// 判断监听者是否还在列表中（因为在响应消息时，某些响应者会添加/移除监听列表）PJC
			(*itVec)->OnFire(args);
	}
	return ;
}

//添加监听者
void   CGEvent::Add(GListener* listener)
{
	if(listener == NULL) // 添加NULL的监听没意义，故不进行添加
		return ;
	if (find(m_listeners.begin(), m_listeners.end(), listener) == m_listeners.end())
	{
		m_listeners.push_back(listener);
	}
}

//移除监听者
void    CGEvent::Remove(GListener* listener)
{
	m_listeners.erase(remove(m_listeners.begin(), m_listeners.end(), listener), m_listeners.end());
}

void CGEvent::operator += (GListener* listener)
{
	if(listener == NULL) // 添加NULL的监听没意义，故不进行添加
		return ;
	if (find(m_listeners.begin(), m_listeners.end(), listener) == m_listeners.end())
	{
		m_listeners.push_back(listener);
	}
}

void CGEvent::operator -= (GListener* listener)
{
	m_listeners.erase(remove(m_listeners.begin(), m_listeners.end(), listener), m_listeners.end());
}
void  FireEvent::Fire(CGEvent* args, GEventArgs* eventArgs) {
	if (args != NULL)
		args->FireEvent(eventArgs);
}
