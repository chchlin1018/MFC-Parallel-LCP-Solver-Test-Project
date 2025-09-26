// PhysicsView.cpp : implementation of the CPhysicsView class
//

#include "pch.h"
#include "framework.h"
#include "PhysicsSimMFC.h"
#include "PhysicsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPhysicsView

IMPLEMENT_DYNCREATE(CPhysicsView, CView)

BEGIN_MESSAGE_MAP(CPhysicsView, CView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CPhysicsView construction/destruction

CPhysicsView::CPhysicsView() noexcept
{
	// TODO: add construction code here

}

CPhysicsView::~CPhysicsView()
{
}

BOOL CPhysicsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPhysicsView drawing

void CPhysicsView::OnDraw(CDC* /*pDC*/)
{
	// TODO: add draw code for native data here
    m_openGLContext.Render();
    SwapBuffers(wglGetCurrentDC());
}


// CPhysicsView diagnostics

#ifdef _DEBUG
void CPhysicsView::AssertValid() const
{
	CView::AssertValid();
}

void CPhysicsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG


// CPhysicsView message handlers

int CPhysicsView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_openGLContext.Create(m_hWnd);
	return 0;
}


void CPhysicsView::OnDestroy()
{
	CView::OnDestroy();

	m_openGLContext.Destroy();
}


void CPhysicsView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	m_openGLContext.Resize(cx, cy);
}


BOOL CPhysicsView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return TRUE; // Prevent MFC from erasing the background
}

