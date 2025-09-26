// PhysicsSimMFCDoc.cpp : implementation of the CPhysicsSimMFCDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PhysicsSimMFC.h"
#endif

#include "PhysicsSimMFCDoc.h"
#include "usd_importer/UsdImporter.h"
#include "fbx_importer/FbxImporter.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPhysicsSimMFCDoc

IMPLEMENT_DYNCREATE(CPhysicsSimMFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CPhysicsSimMFCDoc, CDocument)
END_MESSAGE_MAP()


// CPhysicsSimMFCDoc construction/destruction

CPhysicsSimMFCDoc::CPhysicsSimMFCDoc() noexcept
{
	// TODO: add one-time construction code here

}

CPhysicsSimMFCDoc::~CPhysicsSimMFCDoc()
{
}

BOOL CPhysicsSimMFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CPhysicsSimMFCDoc serialization

void CPhysicsSimMFCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CPhysicsSimMFCDoc diagnostics

#ifdef _DEBUG
void CPhysicsSimMFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPhysicsSimMFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPhysicsSimMFCDoc commands

void CPhysicsSimMFCDoc::ImportUsd(const CString& path)
{
    UsdImporter importer;
    CT2A ascii(path);
    importer.ImportScene(ascii.m_psz, m_world);
    UpdateAllViews(NULL);
}

void CPhysicsSimMFCDoc::ImportFbx(const CString& path)
{
    FbxImporter importer;
    CT2A ascii(path);
    importer.ImportScene(ascii.m_psz, m_world);
    UpdateAllViews(NULL);
}

