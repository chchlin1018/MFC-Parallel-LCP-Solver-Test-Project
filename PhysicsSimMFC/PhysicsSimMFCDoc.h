// PhysicsSimMFCDoc.h : interface of the CPhysicsSimMFCDoc class
//


#pragma once

#include "src/PhysicsWorld.h"

class CPhysicsSimMFCDoc : public CDocument
{
protected: // create from serialization only
	CPhysicsSimMFCDoc() noexcept;
	DECLARE_DYNCREATE(CPhysicsSimMFCDoc)

// Attributes
public:
    PhysicsWorld& GetWorld() { return m_world; }

// Operations
public:
    void ImportUsd(const CString& path);
    void ImportFbx(const CString& path);

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CPhysicsSimMFCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    PhysicsWorld m_world;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

