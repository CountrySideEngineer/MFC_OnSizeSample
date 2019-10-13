
// MFC_OnSizeSampleDlg.h : ヘッダー ファイル
//

#pragma once


// CMFCOnSizeSampleDlg ダイアログ
class CMFCOnSizeSampleDlg : public CDialogEx
{
// コンストラクション
public:
	CMFCOnSizeSampleDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_ONSIZESAMPLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	
	//ここから自前関数
	//virtual void GetOffset(CRect& BaseRect, CRect& ControlRect, int& HOffset, int& VOffset);
	//virtual void GetSize(CRect& BaseRect, CRect& ControlRect, int& HOffset, int& VOffset);


	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);

protected:
	BOOL	m_IsShowWindow;

	CRect	m_DialogRect;
	CRect	m_StaticTextRect;
	CRect	m_EditBoxRect;
	CRect	m_RightButtonRect;
	CRect	m_LeftButtonRect;

	int m_WidthMin;
	int m_HeightMin;

	int m_RightBtnHOffset;	//右ボタンの画面右側からのオフセット(ウィンドウ領域)
	int m_RightBtnVOffset;	//右ボタンの画面下側からのオフセット(ウィンドウ領域)
	int m_RightBtnWidth;	//右ボタンのボタンの幅
	int m_RightBtnHeight;	//右ボタンのボタンの高さ
	int m_LeftBtnHOffset;	//左ボタンの画面右側からのオフセット(ウィンドウ領域)
	int m_LeftBtnVOffset;	//左ボタンの画面下側からのオフセット(ウィンドウ領域)
	int m_LeftBtnWidth;		//左ボタンのボタンの幅
	int m_LeftBtnHeight;	//左ボタンのボタンの高さ

	//エディットボックスの位置
	int m_EditBoxLeft;		//エディットボックスの左側座標
	int m_EditBoxHOffset;	//エディットボックスの水平方向のオフセット
	int m_EditBoxVOffset;	//エディットボックスの垂直方向のオフセット
	int m_EditBoxHeight;	//エディットボックスの高さ
	//グループフレームの位置
	int m_FrameLeft;		//グループフレームの左側座標
	int m_FrameHOffset;		//グループフレームの水平方向のオフセット
	int m_FrameVOffset;		//グループフレームの垂直方向のオフセット
	int m_FrameHeight;		//グループフレームの垂直方向のオフセット
	//静的テキストの位置
	int m_StaticTextTop;	//静的テキストのトップ座標
	int m_StaticTextLeft;	//静的テキストの左側座標
	int m_StaticTextHOffset;//静的テキストの画面右側からのオフセット(水平方向)
	int m_StaticTextVOffset;//静的テキストの画面下側からのオフセット(垂直方向)
	

protected:
	CButton m_LeftButton;
	CButton m_RightButton;
	CEdit m_SampleEdit;
	CStatic m_SampleFrame;
	CStatic m_StaticEditSample;

public:
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
};
