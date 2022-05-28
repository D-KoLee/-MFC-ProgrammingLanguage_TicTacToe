
// A201901268YuSeungJunDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "A201901268YuSeungJun.h"
#include "A201901268YuSeungJunDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

char tictactoe[3][3] = { {' ',' ', ' '},  {' ',' ', ' '},  {' ',' ', ' '} };
bool who = false;
int TURN = 0;
int plO = 0, plX = 0;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CA201901268YuSeungJunDlg 대화 상자



CA201901268YuSeungJunDlg::CA201901268YuSeungJunDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_A201901268YUSEUNGJUN_DIALOG, pParent)
	, m_playerO(0)
	, m_playerX(0)
	, m_whoTurn(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CA201901268YuSeungJunDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTT_00, m_00);
	DDX_Control(pDX, IDC_BUTT_01, m_01);
	DDX_Control(pDX, IDC_BUTT_02, m_02);
	DDX_Control(pDX, IDC_BUTT_10, m_10);
	DDX_Control(pDX, IDC_BUTT_11, m_11);
	DDX_Control(pDX, IDC_BUTT_12, m_12);
	DDX_Control(pDX, IDC_BUTT_20, m_20);
	DDX_Control(pDX, IDC_BUTT_21, m_21);
	DDX_Control(pDX, IDC_BUTT_22, m_22);
	DDX_Text(pDX, IDC_EDIT_PLAYER_O, m_playerO);
	DDX_Text(pDX, IDC_EDIT_PLAYER_X, m_playerX);
	DDX_Text(pDX, IDC_EDIT_WhoTurn, m_whoTurn);
}

BEGIN_MESSAGE_MAP(CA201901268YuSeungJunDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_00, &CA201901268YuSeungJunDlg::OnClickedButt00)
	ON_BN_CLICKED(IDC_BUTT_01, &CA201901268YuSeungJunDlg::OnClickedButt01)
	ON_BN_CLICKED(IDC_BUTT_02, &CA201901268YuSeungJunDlg::OnClickedButt02)
	ON_BN_CLICKED(IDC_BUTT_10, &CA201901268YuSeungJunDlg::OnClickedButt10)
	ON_BN_CLICKED(IDC_BUTT_11, &CA201901268YuSeungJunDlg::OnClickedButt11)
	ON_BN_CLICKED(IDC_BUTT_12, &CA201901268YuSeungJunDlg::OnClickedButt12)
	ON_BN_CLICKED(IDC_BUTT_20, &CA201901268YuSeungJunDlg::OnClickedButt20)
	ON_BN_CLICKED(IDC_BUTT_21, &CA201901268YuSeungJunDlg::OnClickedButt21)
	ON_BN_CLICKED(IDC_BUTT_22, &CA201901268YuSeungJunDlg::OnClickedButt22)
	ON_BN_CLICKED(IDC_BUTT_NEWGAME, &CA201901268YuSeungJunDlg::OnClickedButtNewgame)
	ON_BN_CLICKED(IDC_BUTT_RESET, &CA201901268YuSeungJunDlg::OnClickedButtReset)
END_MESSAGE_MAP()


// CA201901268YuSeungJunDlg 메시지 처리기

BOOL CA201901268YuSeungJunDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	UpdateData(TRUE);
	m_whoTurn = "O의 차례입니다.";
	UpdateData(FALSE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CA201901268YuSeungJunDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CA201901268YuSeungJunDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CA201901268YuSeungJunDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CA201901268YuSeungJunDlg::OnClickedButt00()
{
	if (tictactoe[0][0] == ' ')
	{
		tictactoe[0][0] = turn();
		if (tictactoe[0][0] == 'X') {
			m_00.SetWindowTextA("X");
		}
		else if (tictactoe[0][0] == 'O') {
			m_00.SetWindowTextA("O");
		}
		++TURN;
		endgame(win());
	}

}


void CA201901268YuSeungJunDlg::OnClickedButt01()
{
	if (tictactoe[0][1] == ' ')
	{
		tictactoe[0][1] = turn();
		if (tictactoe[0][1] == 'X') {
			m_01.SetWindowTextA("X");
		}
		else if (tictactoe[0][1] == 'O') {
			m_01.SetWindowTextA("O");
		}
		++TURN;
		endgame(win());
	}
}


void CA201901268YuSeungJunDlg::OnClickedButt02()
{
	if (tictactoe[0][2] == ' ')
	{
		tictactoe[0][2] = turn();
		if (tictactoe[0][2] == 'X') {
			m_02.SetWindowTextA("X");
		}
		else if (tictactoe[0][2] == 'O') {
			m_02.SetWindowTextA("O");
		}
		++TURN;
		endgame(win());
	}
}


void CA201901268YuSeungJunDlg::OnClickedButt10()
{
	if (tictactoe[1][0] == ' ')
	{
		tictactoe[1][0] = turn();
		if (tictactoe[1][0] == 'X') {
			m_10.SetWindowTextA("X");
		}
		else if (tictactoe[1][0] == 'O') {
			m_10.SetWindowTextA("O");
		}
		++TURN;
		endgame(win());
	}
}


void CA201901268YuSeungJunDlg::OnClickedButt11()
{
	if (tictactoe[1][1] == ' ')
	{
		tictactoe[1][1] = turn();
		if (tictactoe[1][1] == 'X') {
			m_11.SetWindowTextA("X");
		}
		else if (tictactoe[1][1] == 'O') {
			m_11.SetWindowTextA("O");
		}
		++TURN;
		endgame(win());
	}
}


void CA201901268YuSeungJunDlg::OnClickedButt12()
{
	if (tictactoe[1][2] == ' ')
	{
		tictactoe[1][2] = turn();
		if (tictactoe[1][2] == 'X') {
			m_12.SetWindowTextA("X");
		}
		else if (tictactoe[1][2] == 'O') {
			m_12.SetWindowTextA("O");
		}
		++TURN;
		endgame(win());
	}
}


void CA201901268YuSeungJunDlg::OnClickedButt20()
{
	if (tictactoe[2][0] == ' ')
	{
		tictactoe[2][0] = turn();
		if (tictactoe[2][0] == 'X') {
			m_20.SetWindowTextA("X");
		}
		else if (tictactoe[2][0] == 'O') {
			m_20.SetWindowTextA("O");
		}
		++TURN;
		endgame(win());
	}
}


void CA201901268YuSeungJunDlg::OnClickedButt21()
{
	if (tictactoe[2][1] == ' ')
	{
		tictactoe[2][1] = turn();
		if (tictactoe[2][1] == 'X') {
			m_21.SetWindowTextA("X");
		}
		else if (tictactoe[2][1] == 'O') {
			m_21.SetWindowTextA("O");
		}
		++TURN;
		endgame(win());
	}
}


void CA201901268YuSeungJunDlg::OnClickedButt22()
{
	if (tictactoe[2][2] == ' ')
	{
		tictactoe[2][2] = turn();
		if (tictactoe[2][2] == 'X') {
			m_22.SetWindowTextA("X");
		}
		else if (tictactoe[2][2] == 'O') {
			m_22.SetWindowTextA("O");
		}
		++TURN;
		endgame(win());
	}
}


void CA201901268YuSeungJunDlg::OnClickedButtNewgame()
{
	UpdateData(TRUE);
	m_playerX = m_playerO = 0;
	UpdateData(FALSE);
	plX = plO = 0;
	OnClickedButtReset();
	UpdateData(TRUE);
	m_whoTurn = "O의 차례입니다.";
	UpdateData(FALSE);
	who = false;
}


void CA201901268YuSeungJunDlg::OnClickedButtReset()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tictactoe[i][j] = ' ';
		}
	}
	TURN = 0;
	if (who == false) {
		UpdateData(TRUE);
		m_whoTurn = "O의 차례입니다.";
		UpdateData(FALSE);
	}
	else if (who == true) {
		UpdateData(TRUE);
		m_whoTurn = "X의 차례입니다.";
		UpdateData(FALSE);
	}
	ResetArray();
}

char CA201901268YuSeungJunDlg::turn()
{
	if (who == false) {
		who = !who;
		UpdateData(TRUE);
		m_whoTurn = "X의 차례입니다.";
		UpdateData(FALSE);
		return 'O';

	}
	else if (who == true) {
		who = !who;
		UpdateData(TRUE);
		m_whoTurn = "O의 차례입니다.";
		UpdateData(FALSE);
		return 'X';
	}
}
void CA201901268YuSeungJunDlg::endgame(bool win) {
	if (win == true) {
		if (who == false) {
			MessageBox("X가 이겼습니다", "게임이 끝났습니다.", MB_OK | MB_ICONINFORMATION);
			++plX;
			UpdateData(TRUE);
			m_playerX = plX;
			UpdateData(FALSE);
			OnClickedButtReset();
		}
		else if (who == true) {
			MessageBox("O가 이겼습니다", "게임이 끝났습니다.", MB_OK | MB_ICONINFORMATION);
			++plO;
			UpdateData(TRUE);
			m_playerO = plO;
			UpdateData(FALSE);
			OnClickedButtReset();
		}
	}
	else if (win == false && TURN >= 9) {
		MessageBox("승자가 없습니다. 무승부입니다.", "게임이 끝났습니다.", MB_OK | MB_ICONINFORMATION);
		OnClickedButtReset();
	}
}

bool CA201901268YuSeungJunDlg::win() {
	for (int i = 0; i < 3; i++) { // 가로줄 검사
		if (TURN <= 9 && tictactoe[i][0] != ' ' &&
			tictactoe[i][0] == tictactoe[i][1] &&
			tictactoe[i][1] == tictactoe[i][2]) {

			return true;
		}
	}
	for (int i = 0; i < 3; i++) { // 세로줄 검사
		if (TURN <= 9 && tictactoe[0][i] != ' ' &&
			tictactoe[0][i] == tictactoe[1][i] &&
			tictactoe[1][i] == tictactoe[2][i]) {

			return true;
		}
	}
	if (TURN <= 9 && tictactoe[0][0] != ' ' && // 역슬래쉬 '\'방향 검사
		tictactoe[0][0] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[2][2]) {
		return true;
	}
	if (TURN <= 9 && tictactoe[0][2] != ' ' && // 슬래쉬 '/' 방향 검사
		tictactoe[0][2] == tictactoe[1][1] && tictactoe[1][1] == tictactoe[2][0]) {
		return true;
	}
	return false;
}

void CA201901268YuSeungJunDlg::ResetArray() {
	m_00.SetWindowTextA(" "); m_01.SetWindowTextA(" "); m_02.SetWindowTextA(" ");
	m_10.SetWindowTextA(" "); m_11.SetWindowTextA(" "); m_12.SetWindowTextA(" ");
	m_20.SetWindowTextA(" "); m_21.SetWindowTextA(" "); m_22.SetWindowTextA(" ");
}