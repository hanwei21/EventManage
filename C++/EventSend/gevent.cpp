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
	// ����˵����������ͼ��Ŀ��������ѡ�񹤾ߵĶ��ο���ʱ�������б�����������
	// ����ԭ��ʾ��A,B�����߹�ͬ������ϢM����ϢM����ʱA������ϢM����������а�B�������Ƴ���������B����������ǰʹ���˼����б�������A������ϢM���ٰ���Ϣ�����Ѿ������ٵ�B�������٣���ҵ���
	// �޸�˵����������Ϣǰȷ�������Ƿ��ڼ����б��С�
	// �޸��ˣ�PJC 2019-11-21��������ͼ��Ŀ ����� ����������С�ɡ���ͳɹ�ͬ��������2~3�죩
	if (m_listeners.size() == 0)
		return;
	vector<GListener*> vecListeners = m_listeners; //ʹ�ø�������֤"��ʱ������"�Żᱻ������Ϣ������Ӧ��Ϣʱ��ĳЩ��Ӧ�߻����/�Ƴ������б�PJC
	for (vector<GListener*>::iterator itVec = vecListeners.begin(); itVec != vecListeners.end(); itVec++)
	{
		if (find(m_listeners.begin(), m_listeners.end(), (*itVec)) != m_listeners.end())// �жϼ������Ƿ����б��У���Ϊ����Ӧ��Ϣʱ��ĳЩ��Ӧ�߻����/�Ƴ������б�PJC
			(*itVec)->OnFire(args);
	}
	return ;
}

//��Ӽ�����
void   CGEvent::Add(GListener* listener)
{
	if(listener == NULL) // ���NULL�ļ���û���壬�ʲ��������
		return ;
	if (find(m_listeners.begin(), m_listeners.end(), listener) == m_listeners.end())
	{
		m_listeners.push_back(listener);
	}
}

//�Ƴ�������
void    CGEvent::Remove(GListener* listener)
{
	m_listeners.erase(remove(m_listeners.begin(), m_listeners.end(), listener), m_listeners.end());
}

void CGEvent::operator += (GListener* listener)
{
	if(listener == NULL) // ���NULL�ļ���û���壬�ʲ��������
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
