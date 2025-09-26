// PhysicsView.h : interface of the CPhysicsView class
//

#pragma once

#include "OpenGLContext.h"

class CPhysicsView : public CView
{
protected: // create from serialization only
	CPhysicsView() noexcept;
	DECLARE_DYNCREATE(CPhysicsView)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual void OnDraw(CDC* pDC);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CPhysicsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    COpenGLContext m_openGLContext;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};

