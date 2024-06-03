#pragma once
#include <vector>
using namespace std;

#ifdef _EVENT_SEND_EXPORT_
#define EVENTSENDEXPORT  _declspec(dllexport)
#else
#define EVENTSENDEXPORT  _declspec(dllimport)
#endif


//===================================GEventArgs===================================
/// @brief �¼���������
//================================================================================
class EVENTSENDEXPORT GEventArgs
{
public:
	virtual ~GEventArgs() {}
};

//====================================GListener===================================
/// @brief �����������
//================================================================================
class EVENTSENDEXPORT GListener
{
public:
	//====================================OnFire()====================================
	/// �¼�������
	///
	/// @param [in] type �¼�����
	/// @param [in] args �¼�����
	///
	/// @return 1-�ɹ���0-ʧ�ܡ�
	//================================================================================
	virtual void        OnFire(GEventArgs* args) = 0;
};



class EVENTSENDEXPORT CGEvent
{
public:
	CGEvent();
	virtual ~CGEvent();

	//��Ӽ�����
	void                Add(GListener* listener);
	//�Ƴ�������
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
