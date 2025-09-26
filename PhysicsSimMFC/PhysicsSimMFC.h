// PhysicsSimMFC.h : main header file for the PhysicsSimMFC application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"


// CPhysicsSimMFCApp:
// See PhysicsSimMFC.cpp for the implementation of this class
//

class CPhysicsSimMFCApp : public CWinApp
{
public:
	CPhysicsSimMFCApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPhysicsSimMFCApp theApp;

