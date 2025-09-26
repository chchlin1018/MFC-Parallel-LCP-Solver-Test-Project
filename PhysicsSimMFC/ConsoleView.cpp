// ConsoleView.cpp : implementation of the CConsoleView class
//

#include "pch.h"
#include "framework.h"
#include "PhysicsSimMFC.h"
#include "ConsoleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CConsoleView

IMPLEMENT_DYNCREATE(CConsoleView, CEditView)

BEGIN_MESSAGE_MAP(CConsoleView, CEditView)
END_MESSAGE_MAP()

// CConsoleView construction/destruction

CConsoleView::CConsoleView() noexcept
{
	// TODO: add construction code here

}

CConsoleView::~CConsoleView()
{
}

BOOL CConsoleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CEditView::PreCreateWindow(cs);
}


// CConsoleView diagnostics

#ifdef _DEBUG
void CConsoleView::AssertValid() const
{
	CEditView::AssertValid();
}

void CConsoleView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG


// CConsoleView message handlers

