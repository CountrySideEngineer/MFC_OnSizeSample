
// MFC_OnSizeSample.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CMFCOnSizeSampleApp:
// このクラスの実装については、MFC_OnSizeSample.cpp を参照してください
//

class CMFCOnSizeSampleApp : public CWinApp
{
public:
	CMFCOnSizeSampleApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CMFCOnSizeSampleApp theApp;
