
// IceCreamShopMFCDlg.cpp : implementation file
//

#include "Product.h"
#include "Dessert.h"
#include "Frozen.h"
#include "IceCream.h"
#include "Yogurt.h"
#include "Order.h"
using namespace sizesAndKinds;


#include "pch.h"
#include "framework.h"
#include "IceCreamShopMFC.h"
#include "IceCreamShopMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CIceCreamShopMFCDlg dialog



CIceCreamShopMFCDlg::CIceCreamShopMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ICECREAMSHOPMFC_DIALOG, pParent)
	, DessertSizeRd(0)
	, DessertKindRd(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIceCreamShopMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, DessertSizeRdSmall, DessertSizeRd);
	DDV_MinMaxInt(pDX, DessertSizeRd, 1, 3);
	DDX_Radio(pDX, DessertKindRdWaffle, DessertKindRd);
	DDV_MinMaxInt(pDX, DessertKindRd, 1, 3);
}

BEGIN_MESSAGE_MAP(CIceCreamShopMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(DessertSizeRdSmall, &CIceCreamShopMFCDlg::OnBnClickedDessertsizerdsmall)
	ON_BN_CLICKED(DessertSizeRdMedium, &CIceCreamShopMFCDlg::OnBnClickedDessertsizerdmedium)
	ON_BN_CLICKED(DessertSizeRdLarge, &CIceCreamShopMFCDlg::OnBnClickedDessertsizerdlarge)
	ON_BN_CLICKED(DessertKindRdWaffle, &CIceCreamShopMFCDlg::OnBnClickedDessertkindrdwaffle)
	ON_BN_CLICKED(DessertKindRdPancake, &CIceCreamShopMFCDlg::OnBnClickedDessertkindrdpancake)
	ON_BN_CLICKED(DessertKindRdCheesecake, &CIceCreamShopMFCDlg::OnBnClickedDessertkindrdcheesecake)
	ON_BN_CLICKED(DessertAddBtn, &CIceCreamShopMFCDlg::OnBnClickedDessertaddbtn)
END_MESSAGE_MAP()


// CIceCreamShopMFCDlg message handlers

BOOL CIceCreamShopMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//#############################
	
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CIceCreamShopMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CIceCreamShopMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CIceCreamShopMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// Dessert Size Radio handler:
void CIceCreamShopMFCDlg::OnBnClickedDessertsizerdsmall()
{
	// Dessert Small Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(DessertSizeRdSmall);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		DessertSizeRd = 1;
	}
}
void CIceCreamShopMFCDlg::OnBnClickedDessertsizerdmedium()
{
	// Dessert Medium Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(DessertSizeRdMedium);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		DessertSizeRd = 2;
	}
}
void CIceCreamShopMFCDlg::OnBnClickedDessertsizerdlarge()
{
	// Dessert Large Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(DessertSizeRdLarge);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		DessertSizeRd = 3;
	}
}

// Dessert Kind Radio handler:
void CIceCreamShopMFCDlg::OnBnClickedDessertkindrdwaffle()
{
	// Dessert Waffle Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(DessertKindRdWaffle);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		DessertKindRd = 1;
	}
}
void CIceCreamShopMFCDlg::OnBnClickedDessertkindrdpancake()
{
	// Dessert Pancake Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(DessertKindRdPancake);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		DessertKindRd = 2;
	}
}
void CIceCreamShopMFCDlg::OnBnClickedDessertkindrdcheesecake()
{
	// Dessert Cheesecake Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(DessertKindRdCheesecake);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		DessertKindRd = 3;
	}
}

// Dessert Add Button handler:

void CIceCreamShopMFCDlg::OnBnClickedDessertaddbtn()
{
	sizeOption DessertSizeOption = S;
	dessertOption DessertKindOption = waffle;
	CString DessertName = _T("General");

	// What size has been selected:
	switch (DessertSizeRd)
	{
	case 1:
		DessertSizeOption = S;
		break;
	case 2:
		DessertSizeOption = M;
		break;
	case 3:
		DessertSizeOption = L;
		break;
	}

	// What kind has been selected:
	switch (DessertKindRd)
	{
	case 1:
		DessertKindOption = pancake;
		DessertName = _T("Pancake");
		break;
	case 2:
		DessertKindOption = waffle;
		DessertName = _T("Waffle");
		break;
	case 3:
		DessertKindOption = cheesecake;
		DessertName = _T("CheeseCake");
		break;
	}

	//Creating instance of Dessert with the size and kind selected:
	Dessert ds(DessertName, DessertKindOption, DessertSizeOption);
	AfxMessageBox(_T("Dessert added successfully !"));

	// TODO: adding the dessert to list to display,

}
