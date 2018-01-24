
// MFC Seminar 20172018.h : main header file for the MFC Seminar 20172018 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCSeminar20172018App:
// See MFC Seminar 20172018.cpp for the implementation of this class
//

class CMFCSeminar20172018App : public CWinApp
{
public:
	CMFCSeminar20172018App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCSeminar20172018App theApp;
