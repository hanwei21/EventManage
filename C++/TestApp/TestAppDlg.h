
// TestAppDlg.h : 头文件
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

// CTestAppDlg 对话框
class CTestAppDlg : public CDialogEx
{
// 构造
public:
	CTestAppDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
