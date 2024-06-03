#pragma once
#include <vector>
using namespace std;

#ifdef _EVENT_SEND_EXPORT_
#define EVENTSENDEXPORT  _declspec(dllexport)
#else
#define EVENTSENDEXPORT  _declspec(dllimport)
#endif


//===================================GEventArgs===================================
/// @brief 事件参数基类
//================================================================================
class EVENTSENDEXPORT GEventArgs
{
public:
	virtual ~GEventArgs() {}
};

//====================================GListener===================================
/// @brief 监听对象基类
//================================================================================
class EVENTSENDEXPORT GListener
{
public:
	//====================================OnFire()====================================
	/// 事件处理函数
	///
	/// @param [in] type 事件类型
	/// @param [in] args 事件参数
	///
	/// @return 1-成功；0-失败。
	//================================================================================
	virtual void        OnFire(GEventArgs* args) = 0;
};



class EVENTSENDEXPORT CGEvent
{
public:
	CGEvent();
	virtual ~CGEvent();

	//添加监听者
	void                Add(GListener* listener);
	//移除监听者
	void                Remove(GListener* listener);
	void                operator += (GListener* listener);
	void                operator -= (GListener* listener);

private:

	friend class   FireEvent;
	virtual void      FireEvent(GEventArgs* listener);
	vector<GListener*> m_listeners;
};


class EVENTSENDEXPORT FireEvent
{
public:
	FireEvent() {};
	virtual ~FireEvent() {};

	static void  Fire(CGEvent* args, GEventArgs* eventArgs);
};

#define _HKTCOMMON_LIB_  "EventSend.lib"

#ifndef _EVENT_SEND_EXPORT_
#pragma comment(lib,_HKTCOMMON_LIB_)
#endif

#ifndef __HKTCOMMON_HIDE_AUTOLINK_OUTPUT_
#pragma message("Automatically linking with " _HKTCOMMON_LIB_)
#endif
