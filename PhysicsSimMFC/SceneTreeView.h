// SceneTreeView.h : interface of the CSceneTreeView class
//

#pragma once

class CSceneTreeView : public CTreeView
{
protected: // create from serialization only
	CSceneTreeView() noexcept;
	DECLARE_DYNCREATE(CSceneTreeView)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CSceneTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

