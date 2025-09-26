// PropertyEditView.cpp : implementation of the CPropertyEditView class
//

#include "pch.h"
#include "framework.h"
#include "PhysicsSimMFC.h"
#include "PropertyEditView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPropertyEditView

IMPLEMENT_DYNCREATE(CPropertyEditView, CEditView)

BEGIN_MESSAGE_MAP(CPropertyEditView, CEditView)
END_MESSAGE_MAP()

// CPropertyEditView construction/destruction

CPropertyEditView::CPropertyEditView() noexcept
{
	// TODO: add construction code here

}

CPropertyEditView::~CPropertyEditView()
{
}

BOOL CPropertyEditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CEditView::PreCreateWindow(cs);
}


// CPropertyEditView diagnostics

#ifdef _DEBUG
void CPropertyEditView::AssertValid() const
{
	CEditView::AssertValid();
}

void CPropertyEditView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG


// CPropertyEditView message handlers

