// ConsoleView.h : interface of the CConsoleView class
//

#pragma once

class CConsoleView : public CEditView
{
protected: // create from serialization only
	CConsoleView() noexcept;
	DECLARE_DYNCREATE(CConsoleView)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CConsoleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

