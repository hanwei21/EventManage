
// TestAppDlg.h : ͷ�ļ�
//

#pragma once
#include "gevent.h"
#include "EventSend.h"



class CThemesListenser : public GListener
{
public:
	CThemesListenser() {}
	~CThemesListenser() {}
	void OnFire(GEventArgs* args)
	{
		int a = 0;
		a++;
		a++;
	}
private:
};




class CThemesListenser2 : public GListener
{
public:
	CThemesListenser2() {}
	~CThemesListenser2() {}
	void OnFire(GEventArgs* args)
	{
		int a = 0;
		a++;
		a++;
	}
private:
};

class TestEventSendClass {
public:
	TestEventSendClass() {
	}
	virtual ~TestEventSendClass() {
	}

	CGEvent* GetSendEvent1() {
		return &sendEvent1;
	}
	void SendEvent1() {
		FireEvent::Fire(&sendEvent1, NULL);
	}

private:
	CGEvent sendEvent1;
};

// CTestAppDlg �Ի���
class CTestAppDlg : public CDialogEx
{
// ����
public:
	CTestAppDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
private:
	CGEventSendClass eventSend;
	CThemesListenser listenser1;
	CThemesListenser2 listenser2;
};
