// SceneTreeView.cpp : implementation of the CSceneTreeView class
//

#include "pch.h"
#include "framework.h"
#include "PhysicsSimMFC.h"
#include "SceneTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSceneTreeView

IMPLEMENT_DYNCREATE(CSceneTreeView, CTreeView)

BEGIN_MESSAGE_MAP(CSceneTreeView, CTreeView)
END_MESSAGE_MAP()

// CSceneTreeView construction/destruction

CSceneTreeView::CSceneTreeView() noexcept
{
	// TODO: add construction code here

}

CSceneTreeView::~CSceneTreeView()
{
}

BOOL CSceneTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CTreeView::PreCreateWindow(cs);
}


// CSceneTreeView diagnostics

#ifdef _DEBUG
void CSceneTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CSceneTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG


// CSceneTreeView message handlers

