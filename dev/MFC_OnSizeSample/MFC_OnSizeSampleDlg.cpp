
// MFC_OnSizeSampleDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "MFC_OnSizeSample.h"
#include "MFC_OnSizeSampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCOnSizeSampleDlg ダイアログ



CMFCOnSizeSampleDlg::CMFCOnSizeSampleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_ONSIZESAMPLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	this->m_IsShowWindow = FALSE;
}

void CMFCOnSizeSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_LeftButton);
	DDX_Control(pDX, IDC_BUTTON2, m_RightButton);
	DDX_Control(pDX, IDC_EDIT_SAMPLE, m_SampleEdit);
	DDX_Control(pDX, IDC_STATIC_AREA, m_SampleFrame);
	DDX_Control(pDX, IDC_STATIC_SAMPLE, m_StaticEditSample);
}

BEGIN_MESSAGE_MAP(CMFCOnSizeSampleDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CMFCOnSizeSampleDlg メッセージ ハンドラー

BOOL CMFCOnSizeSampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	//ShowWindow(SW_MAXIMIZE);

	//ShowWindow(SW_MINIMIZE);

	// TODO: 初期化をここに追加します。
	/*
	 *	コントロールのサイズ/オフセットを算出する。
	 *	このとき、必ずクライアント領域の値を算出すること。
	 *	MoveWindow()では、クライアント領域の位置を指定するため
	 */
	CRect DialogClientRect = { 0, 0, 0, 0 };
	this->GetClientRect(&DialogClientRect);

	//右側ボタンのオフセットとサイズを取得
	CRect RightBtnRect = { 0, 0, 0, 0 };
	this->m_RightButton.GetWindowRect(&RightBtnRect);
	this->ScreenToClient(&RightBtnRect);	//クライアント領域での位置を取得
	this->m_RightBtnHOffset = DialogClientRect.right - RightBtnRect.right;
	this->m_RightBtnVOffset = DialogClientRect.bottom - RightBtnRect.bottom;
	this->m_RightBtnWidth = RightBtnRect.right - RightBtnRect.left;
	this->m_RightBtnHeight = RightBtnRect.bottom - RightBtnRect.top;

	//左側ボタンのオフセットとサイズを取得
	CRect LeftBtnRect = { 0, 0, 0, 0 };
	this->m_LeftButton.GetWindowRect(&LeftBtnRect);
	this->ScreenToClient(&LeftBtnRect);	//クライアント領域での位置を取得
	this->m_LeftBtnHOffset = DialogClientRect.right - LeftBtnRect.right;
	this->m_LeftBtnVOffset = DialogClientRect.bottom - LeftBtnRect.bottom;
	this->m_LeftBtnWidth = LeftBtnRect.right - LeftBtnRect.left;
	this->m_LeftBtnHeight = LeftBtnRect.bottom - LeftBtnRect.top;

	//エディットボックスのオフセットとサイズを取得
	CRect EditBoxRect = { 0, 0, 0, 0 };
	this->m_SampleEdit.GetWindowRect(&EditBoxRect);
	this->ScreenToClient(&EditBoxRect);
	//this->m_EditBoxTop = EditBoxRect.top - DialogClientRect.top;
	this->m_EditBoxLeft = EditBoxRect.left - DialogClientRect.left;
	this->m_EditBoxHOffset = DialogClientRect.right - EditBoxRect.right;
	this->m_EditBoxVOffset = DialogClientRect.bottom - EditBoxRect.bottom;
	this->m_EditBoxHeight = EditBoxRect.bottom - EditBoxRect.top;

	//グループフレームのオフセットとサイズを取得
	CRect FrameRect = { 0, 0, 0, 0 };
	this->m_SampleFrame.GetWindowRect(&FrameRect);
	this->ScreenToClient(&FrameRect);
	//this->m_FrameTop = FrameRect.top - DialogClientRect.top;
	this->m_FrameLeft = FrameRect.left - DialogClientRect.left;
	this->m_FrameHOffset = DialogClientRect.right - FrameRect.right;
	this->m_FrameVOffset = DialogClientRect.bottom - FrameRect.bottom;
	this->m_FrameHeight = FrameRect.bottom - FrameRect.top;

	//Staticエディットコントロール
	CRect StaticTextRect = { 0, 0, 0, 0 };
	this->m_StaticEditSample.GetWindowRect(&StaticTextRect);
	this->ScreenToClient(&StaticTextRect);
	//this->m_StaticTextTop = StaticTextRect.top - DialogClientRect.top;
	this->m_StaticTextLeft = StaticTextRect.left - DialogClientRect.left;
	this->m_StaticTextHOffset = DialogClientRect.right - StaticTextRect.right;
	this->m_StaticTextVOffset = DialogClientRect.bottom - StaticTextRect.bottom;

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CMFCOnSizeSampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CMFCOnSizeSampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCOnSizeSampleDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (FALSE == this->m_IsShowWindow) {
		return;	//ダイアログが表示されていない場合には、何もしない
	}

	CRect NewRightBtnRect = {
		cx - this->m_RightBtnHOffset - this->m_RightBtnWidth,
		cy - this->m_RightBtnVOffset - this->m_RightBtnHeight,
		cx - this->m_RightBtnHOffset,
		cy - this->m_RightBtnVOffset
	};
	this->m_RightButton.MoveWindow(&NewRightBtnRect);

	CRect NewLeftBtnRect = {
		cx - this->m_LeftBtnHOffset - this->m_LeftBtnWidth,
		cy - this->m_LeftBtnVOffset - this->m_LeftBtnHeight,
		cx - this->m_LeftBtnHOffset,
		cy - this->m_LeftBtnVOffset
	};
	this->m_LeftButton.MoveWindow(&NewLeftBtnRect);

	CRect NewEditBoxRect = {
		this->m_EditBoxLeft,
		cy - this->m_EditBoxVOffset - this->m_EditBoxHeight,
		cx - this->m_EditBoxHOffset,
		cy - this->m_EditBoxVOffset
	};
	this->m_SampleEdit.MoveWindow(&NewEditBoxRect);

	CRect NewFrameRect = {
		this->m_FrameLeft,
		cy - this->m_FrameVOffset - this->m_FrameHeight,
		cx - this->m_FrameHOffset,
		cy - this->m_FrameVOffset
	};
	this->m_SampleFrame.MoveWindow(&NewFrameRect);

	CRect NewStaticEditRect = {
		this->m_StaticTextLeft,
		this->m_StaticTextTop,
		cx - this->m_StaticTextHOffset,
		cy - this->m_StaticTextVOffset
	};
	this->m_StaticEditSample.MoveWindow(&NewStaticEditRect);

	InvalidateRect(NULL);

	TRACE(_T("nType = %d\n"), nType);
	TRACE(_T("cx    = %d\n"), cx);
	TRACE(_T("cy    = %d\n"), cy);
}


void CMFCOnSizeSampleDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	if (FALSE == this->m_IsShowWindow) {
		this->m_IsShowWindow = bShow;
	}
}
