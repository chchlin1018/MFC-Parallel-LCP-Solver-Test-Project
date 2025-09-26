// PropertyEditView.h : interface of the CPropertyEditView class
//

#pragma once

class CPropertyEditView : public CEditView
{
protected: // create from serialization only
	CPropertyEditView() noexcept;
	DECLARE_DYNCREATE(CPropertyEditView)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CPropertyEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

