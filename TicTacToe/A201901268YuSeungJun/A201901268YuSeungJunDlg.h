
// A201901268YuSeungJunDlg.h: 헤더 파일
//

#pragma once


// CA201901268YuSeungJunDlg 대화 상자
class CA201901268YuSeungJunDlg : public CDialogEx
{
// 생성입니다.
public:
	CA201901268YuSeungJunDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_A201901268YUSEUNGJUN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButt00();
	afx_msg void OnClickedButt01();
	afx_msg void OnClickedButt02();
	afx_msg void OnClickedButt10();
	afx_msg void OnClickedButt11();
	afx_msg void OnClickedButt12();
	afx_msg void OnClickedButt20();
	afx_msg void OnClickedButt21();
	afx_msg void OnClickedButt22();
	afx_msg void OnClickedButtNewgame();
	afx_msg void OnClickedButtReset();
	CEdit m_00;
	CEdit m_01;
	CEdit m_02;
	CEdit m_10;
	CEdit m_11;
	CEdit m_12;
	CEdit m_20;
	CEdit m_21;
	CEdit m_22;
	CString m_whoTurn;
	int m_playerO;
	int m_playerX;
	bool win();
	char turn();
	void endgame(bool win);
	void ResetArray();
};
