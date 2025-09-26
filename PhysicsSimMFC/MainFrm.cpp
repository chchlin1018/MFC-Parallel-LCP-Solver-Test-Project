// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "PhysicsSimMFC.h"

#include "MainFrm.h"
#include "PhysicsSimMFCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
    ON_COMMAND(ID_FILE_IMPORT_FBX, &CMainFrame::OnFileImportFbx) // Added for FBX import
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame() noexcept
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
    // Create a splitter window
    if (!m_wndSplitter.CreateStatic(this, 1, 2)) // Main splitter: 1 row, 2 columns
        return FALSE;

    // Create the left and right panes
    if (!m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CSceneTreeView), CSize(250, 0), pContext) ||
        !m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CPhysicsView), CSize(0, 0), pContext))
    {
        m_wndSplitter.DestroyWindow();
        return FALSE;
    }

    return TRUE;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		 | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU;

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

void CMainFrame::OnFileImportFbx()
{
    CFileDialog dlg(TRUE, _T(".fbx"), NULL,
        OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
        _T("FBX Files (*.fbx)|*.fbx|All Files (*.*)|*.*||"), this);

    if (dlg.DoModal() == IDOK)
    {
        CString path = dlg.GetPathName();
        CPhysicsSimMFCDoc* pDoc = (CPhysicsSimMFCDoc*)GetActiveDocument();
        if (pDoc)
        {
            pDoc->ImportFbx(path);
        }
    }
}

