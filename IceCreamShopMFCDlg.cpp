
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
	, IceCreamFlavorRd(0)
	, IceCreamSizeRd(0)
	, YogurtSizeRd(0)
	, OreoAddonChBxSelected(FALSE)
	, SprinklesAddonChBxSelected(FALSE)
	, StrawberriesAddonChBxSelected(FALSE)
	, PineappleAddonChBxSelected(FALSE)
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
	DDX_Radio(pDX, ICFlavorRdChocolate, IceCreamFlavorRd);
	DDV_MinMaxInt(pDX, IceCreamFlavorRd, 1, 3);
	DDX_Radio(pDX, ICSizeRdSmall, IceCreamSizeRd);
	DDV_MinMaxInt(pDX, IceCreamSizeRd, 1, 3);
	DDX_Radio(pDX, YogurtSizeRdSmall, YogurtSizeRd);
	DDV_MinMaxInt(pDX, YogurtSizeRd, 1, 3);
	DDX_Check(pDX, OreoAddonChBx, OreoAddonChBxSelected);
	DDX_Check(pDX, SprinklesAddonChBx, SprinklesAddonChBxSelected);
	DDX_Check(pDX, StrawberriesAddonChBx, StrawberriesAddonChBxSelected);
	DDX_Check(pDX, PineappleAddonChBx, PineappleAddonChBxSelected);
	DDX_Control(pDX, IDC_LIST1, display);
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
	ON_BN_CLICKED(ICFlavorRdChocolate, &CIceCreamShopMFCDlg::OnBnClickedIcflavorrdchocolate)
	ON_BN_CLICKED(ICFlavorRdVanilla, &CIceCreamShopMFCDlg::OnBnClickedIcflavorrdvanilla)
	ON_BN_CLICKED(ICFlavorRdMixed, &CIceCreamShopMFCDlg::OnBnClickedIcflavorrdmixed)
	ON_BN_CLICKED(ICSizeRdSmall, &CIceCreamShopMFCDlg::OnBnClickedIcsizerdsmall)
	ON_BN_CLICKED(ICSizeRdMedium, &CIceCreamShopMFCDlg::OnBnClickedIcsizerdmedium)
	ON_BN_CLICKED(ICSizeRdLarge, &CIceCreamShopMFCDlg::OnBnClickedIcsizerdlarge)
	ON_BN_CLICKED(IceCreamAddBtn, &CIceCreamShopMFCDlg::OnBnClickedIcecreamaddbtn)
	ON_BN_CLICKED(YogurtSizeRdSmall, &CIceCreamShopMFCDlg::OnBnClickedYogurtsizerdsmall)
	ON_BN_CLICKED(YogurtSizeRdMedium, &CIceCreamShopMFCDlg::OnBnClickedYogurtsizerdmedium)
	ON_BN_CLICKED(YogurtSizeRdLarge, &CIceCreamShopMFCDlg::OnBnClickedYogurtsizerdlarge)
	ON_BN_CLICKED(YogurtAddBtn, &CIceCreamShopMFCDlg::OnBnClickedYogurtaddbtn)
	ON_BN_CLICKED(OreoAddonChBx, &CIceCreamShopMFCDlg::OnBnClickedOreoaddonchbx)
	ON_BN_CLICKED(SprinklesAddonChBx, &CIceCreamShopMFCDlg::OnBnClickedSprinklesaddonchbx)
	ON_BN_CLICKED(StrawberriesAddonChBx, &CIceCreamShopMFCDlg::OnBnClickedStrawberriesaddonchbx)
	ON_BN_CLICKED(PineappleAddonChBx, &CIceCreamShopMFCDlg::OnBnClickedPineappleaddonchbx)
	ON_BN_CLICKED(DeletePrdBtn, &CIceCreamShopMFCDlg::OnBnClickedDeleteprdbtn)
	ON_BN_CLICKED(PayNowBtn, &CIceCreamShopMFCDlg::OnBnClickedPaynowbtn)
	ON_BN_CLICKED(ModifyPrdBtn, &CIceCreamShopMFCDlg::OnBnClickedModifyprdbtn)
	ON_BN_CLICKED(ModifyDessertBtn, &CIceCreamShopMFCDlg::OnBnClickedModifydessertbtn)
	ON_BN_CLICKED(ModifyIceCreamBtn, &CIceCreamShopMFCDlg::OnBnClickedModifyicecreambtn)
	ON_BN_CLICKED(ModifyYogurtBtn, &CIceCreamShopMFCDlg::OnBnClickedModifyyogurtbtn)
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
	
	display.InsertColumn(0,L"Product Name",LVCFMT_LEFT,100);
	display.InsertColumn(1, L"Size", LVCFMT_LEFT, 75);
	display.InsertColumn(2, L"Specs", LVCFMT_LEFT, 400);
	display.InsertColumn(3, L"Price", LVCFMT_LEFT, 75);
	display.InsertColumn(4, L"Product id", LVCFMT_LEFT, 75);
	


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

// ===================== Dessert Selection Pane =====================

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
	int nItem;
	sizeOption DessertSizeOption = S;
	dessertOption DessertKindOption = waffle;
	CString DessertName = _T("Waffle"), price = _T(""), size = _T("Small"), totalPrice = _T(""),id=_T("");

	// What kind has been selected:
	switch (DessertKindRd)
	{
	case 1:
		DessertKindOption = waffle;
		DessertName = _T("Waffle");
		break;
	case 2:
		DessertKindOption = pancake;
		DessertName = _T("Pancake");
		break;
	case 3:
		DessertKindOption = cheesecake;
		DessertName = _T("CheeseCake");
		break;
	}

	// What size has been selected:
	switch (DessertSizeRd)
	{
	case 1:
		DessertSizeOption = S;
		size = _T("Small");
		break;
	case 2:
		DessertSizeOption = M;
		size = _T("Medium");
		break;
	case 3:
		DessertSizeOption = L;
		size = _T("Large");
		break;
	}

	//Creating instance of Dessert with the size and kind selected and adding to MyOrder
	Dessert* OrderedDessert = new Dessert(DessertName, DessertKindOption, DessertSizeOption);
	MyOrder.addProduct(OrderedDessert);
	id.Format(_T("%d"), OrderedDessert->getId());

	//adding new line to list control
	nItem = display.InsertItem(0, DessertName);
	price.Format(_T("%g ₪"), OrderedDessert->getPrice());
	display.SetItemText(nItem, 1, size);
	display.SetItemText(nItem, 3, price);
	display.SetItemText(nItem, 4, id);
	
	// Update Total Price on Pay Now Button
	totalPrice.Format(_T("Pay (total: %g ₪)"), MyOrder.calculateTotalPrice());
	GetDlgItem(PayNowBtn)->SetWindowText(totalPrice);

}

// ==================================================================


// ===================== IceCream Selection Pane ====================

// IceCream Flavor Radio handler:
void CIceCreamShopMFCDlg::OnBnClickedIcflavorrdchocolate()
{
	// IceCream Chocolate Flavor Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(ICFlavorRdChocolate);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		IceCreamFlavorRd = 1;
	}
}
void CIceCreamShopMFCDlg::OnBnClickedIcflavorrdvanilla()
{
	// IceCream Vanilla Flavor Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(ICFlavorRdVanilla);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		IceCreamFlavorRd = 2;
	}
}
void CIceCreamShopMFCDlg::OnBnClickedIcflavorrdmixed()
{
	// IceCream Mixed Flavor Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(ICFlavorRdMixed);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		IceCreamFlavorRd = 3;
	}
}

// IceCream CupSize Radio handler:
void CIceCreamShopMFCDlg::OnBnClickedIcsizerdsmall()
{
	// IceCream Small Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(ICSizeRdSmall);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		IceCreamSizeRd = 1;
	}
}
void CIceCreamShopMFCDlg::OnBnClickedIcsizerdmedium()
{
	// IceCream Medium Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(ICSizeRdMedium);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		IceCreamSizeRd = 2;
	}
}
void CIceCreamShopMFCDlg::OnBnClickedIcsizerdlarge()
{
	// IceCream Large Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(ICSizeRdLarge);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		IceCreamSizeRd = 3;
	}
}

// Dessert Add Button handler:
void CIceCreamShopMFCDlg::OnBnClickedIcecreamaddbtn()
{
	int nItem = -1;
	sizeOption IceCreamSizeOption = S;
	flavorOption IceCreamFlavorOption = chocolate;
	CString IceCreamName = _T("Ice Cream"), price = _T(""), size = _T("Small"), specs = _T("Chocolate"), totalPrice = _T(""),id=_T("");
	
	// What kind has been selected:
	switch (IceCreamFlavorRd)
	{
	case 1:
		IceCreamFlavorOption = chocolate;
		specs = _T("Chocolate");
		break;
	case 2:
		IceCreamFlavorOption = vanilla;
		specs = _T("Vanilla");
		break;
	case 3:
		IceCreamFlavorOption = mixed;
		specs = _T("Chocolate and Vanilla");
		break;
	}

	// What size has been selected:
	switch (IceCreamSizeRd)
	{
	case 1:
		IceCreamSizeOption = S;
		size = _T("Small");
		break;
	case 2:
		IceCreamSizeOption = M;
		size = _T("Medium");
		break;
	case 3:
		IceCreamSizeOption = L;
		size = _T("Large");
		break;
	}


	//Creating instance of IceCream with the size and kind selected:
	IceCream* OrederedIceCream = new IceCream(IceCreamName,IceCreamSizeOption,IceCreamFlavorOption);
	MyOrder.addProduct(OrederedIceCream);
	id.Format(_T("%d"), OrederedIceCream->getId());
	
	//adding new line to list control
	nItem = display.InsertItem(0, IceCreamName);
	price.Format(_T("%g ₪"), OrederedIceCream->getPrice());
	display.SetItemText(nItem, 1, size);
	display.SetItemText(nItem, 2, specs);
	display.SetItemText(nItem, 3, price);
	display.SetItemText(nItem, 4, id);

	// Update Total Price on Pay Now Button
	totalPrice.Format(_T("Pay (total: %g ₪)"), MyOrder.calculateTotalPrice());
	GetDlgItem(PayNowBtn)->SetWindowText(totalPrice);
}

// ==================================================================



// ====================== Yogurt Selection Pane =====================

// Yogurt CupSize Radio handler:
void CIceCreamShopMFCDlg::OnBnClickedYogurtsizerdsmall()
{
	// Yogurt Small Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(YogurtSizeRdSmall);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		YogurtSizeRd = 1;
	}
}
void CIceCreamShopMFCDlg::OnBnClickedYogurtsizerdmedium()
{
	// Yogurt Medium Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(YogurtSizeRdMedium);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		YogurtSizeRd = 2;
	}
}
void CIceCreamShopMFCDlg::OnBnClickedYogurtsizerdlarge()
{
	// Yogurt Large Radio Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(YogurtSizeRdLarge);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		YogurtSizeRd = 3;
	}
}

// Yogurt Addons Checkbox handler:
void CIceCreamShopMFCDlg::OnBnClickedOreoaddonchbx()
{
	// Oreo CheckBox Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(OreoAddonChBx);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		OreoAddonChBxSelected = true;
	}
	else
	{
		OreoAddonChBxSelected = false;
	}
}
void CIceCreamShopMFCDlg::OnBnClickedSprinklesaddonchbx()
{
	// Sprinkles CheckBox Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(SprinklesAddonChBx);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		SprinklesAddonChBxSelected = true;
	}
	else
	{
		SprinklesAddonChBxSelected = false;
	}
}
void CIceCreamShopMFCDlg::OnBnClickedStrawberriesaddonchbx()
{
	// Strawberries CheckBox Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(StrawberriesAddonChBx);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		StrawberriesAddonChBxSelected = true;
	}
	else
	{
		StrawberriesAddonChBxSelected = false;
	}
}
void CIceCreamShopMFCDlg::OnBnClickedPineappleaddonchbx()
{
	// Pineapple CheckBox Selected
	CButton* m_ctlCheck = (CButton*)GetDlgItem(PineappleAddonChBx);
	int ChkBox = m_ctlCheck->GetCheck();
	if (ChkBox == BST_CHECKED)
	{
		PineappleAddonChBxSelected = true;
	}
	else
	{
		PineappleAddonChBxSelected = false;
	}
}

// Yogurt Add Button handler:
void CIceCreamShopMFCDlg::OnBnClickedYogurtaddbtn()
{
	int nItem;
	sizeOption yogurtSizeOption = S;
	vector<CString>	yogurtAddons = {};
	CString YogurtName = _T("Frozen Yogurt"), price = _T(""), size = _T("Small"), specs = _T("Addons: "), totalPrice = _T(""), id = _T("");

	// What size has been selected:
	switch (YogurtSizeRd)
	{
	case 1:
		yogurtSizeOption = S;
		size = _T("Small");
		break;
	case 2:
		yogurtSizeOption = M;
		size = _T("Medium");
		break;
	case 3:
		yogurtSizeOption = L;
		size = _T("Large");
		break;
	}
	// Is Oreos been selected:
	if (OreoAddonChBxSelected)
	{
		yogurtAddons.push_back(_T("Oreo"));
		specs += _T("Oreo ");
	}

	// Is Sprinkles been selected:
	if (SprinklesAddonChBxSelected)
	{
		yogurtAddons.push_back(_T("Sprinkles"));
		if (specs != _T("Addons: ")) 
		{
			specs += _T(", Sprinkles");
		}
		else 
		{
			specs += _T("Sprinkles");
		}
	}

	// Is Strawberries been selected:
	if (StrawberriesAddonChBxSelected)
	{
		yogurtAddons.push_back(_T("Strawberries"));
		if (specs != _T("Addons: ")) 
		{
			specs += _T(", Strawberries");
		}
		else 
		{
			specs += _T("Strawberries");
		}
	}

	// Is Pineapple been selected:
	if (PineappleAddonChBxSelected)
	{
		yogurtAddons.push_back(_T("Pineapple"));
		if (specs != _T("Addons: ")) 
		{
			specs += _T(", Pineapple");
		}
		else 
		{
			specs += _T("Pineapple");
		}
	}
	
	if (specs == _T("Addons: ")) 
	{
		specs = _T("No Addons");
	}

	//Creating instance of Yogurt with the size and kind selected:
	Yogurt* OrederedYogurt = new Yogurt(YogurtName, yogurtSizeOption, yogurtAddons);
	MyOrder.addProduct(OrederedYogurt);
	id.Format(_T("%d"), OrederedYogurt->getId());

	//adding new line to list control
	nItem = display.InsertItem(0, YogurtName);
	price.Format(_T("%g ₪"), OrederedYogurt->getPrice());
	display.SetItemText(nItem, 1, size);
	display.SetItemText(nItem, 2, specs);
	display.SetItemText(nItem, 3, price);
	display.SetItemText(nItem, 4, id);
	
	// Update Total Price on Pay Now Button
	totalPrice.Format(_T("Pay (total: %g ₪)"), MyOrder.calculateTotalPrice());
	GetDlgItem(PayNowBtn)->SetWindowText(totalPrice);
}

// ==================================================================


// ================== Delete Product Button handler =================

void CIceCreamShopMFCDlg::OnBnClickedDeleteprdbtn()
{
	int nItem = -1;
	CString name, price, specs, size, totalPrice;
	nItem = display.GetNextItem(nItem, LVNI_SELECTED);
	int id = _ttoi(display.GetItemText(nItem, 4));
	Product* productToDelete = 	MyOrder.getProductById(id);
	if (productToDelete != nullptr) {
		MyOrder.removeProduct(productToDelete);
		display.DeleteItem(nItem);
	}
	else {
		AfxMessageBox(_T("Deleting encountered error: No Product was found."));
	}
	
	// Update Total Price on Pay Now Button
	totalPrice.Format(_T("Pay (total: %g ₪)"), MyOrder.calculateTotalPrice());
	GetDlgItem(PayNowBtn)->SetWindowText(totalPrice);
}

// ==================================================================




// ================== Modify Product Button handler =================

// Main button:
void CIceCreamShopMFCDlg::OnBnClickedModifyprdbtn()
{
	nItemToModify = display.GetNextItem(nItemToModify, LVNI_SELECTED);

	if (nItemToModify == -1)
	{
		AfxMessageBox(_T("No Product was selected, please select a product to modify."));
	}
	else
	{
		GetDlgItem(DeletePrdBtn)->EnableWindow(FALSE);
		GetDlgItem(ModifyPrdBtn)->EnableWindow(FALSE);
		CString productName = display.GetItemText(nItemToModify, 0);
		CString productID = display.GetItemText(nItemToModify, 4);
		sizeOption productSize;
		PrdIdToModify = _ttoi(productID);
		//Modifies Dessert:				
		if (productName == _T("Waffle") || productName == _T("CheeseCake") || productName == _T("Pancake")) 
		{
			//replace 'Modify' buttons and disabling 'Add' buttons:
			GetDlgItem(ModifyDessertBtn)->EnableWindow(TRUE);
			GetDlgItem(DessertAddBtn)->EnableWindow(FALSE);
			GetDlgItem(IceCreamAddBtn)->EnableWindow(FALSE);
			GetDlgItem(YogurtAddBtn)->EnableWindow(FALSE);
			
			Dessert* selectedDessert= ((Dessert*)MyOrder.getProductById(PrdIdToModify));
			productSize = selectedDessert->getSize();
			dessertOption dessertKind = selectedDessert->getKind();
			
			switch (productSize)
			{
			case 1:
				((CButton*)GetDlgItem(DessertSizeRdSmall))->SetCheck(TRUE);
				((CButton*)GetDlgItem(DessertSizeRdMedium))->SetCheck(FALSE);
				((CButton*)GetDlgItem(DessertSizeRdLarge))->SetCheck(FALSE);
				break;
			case 2:
				((CButton*)GetDlgItem(DessertSizeRdSmall))->SetCheck(FALSE);
				((CButton*)GetDlgItem(DessertSizeRdMedium))->SetCheck(TRUE);
				((CButton*)GetDlgItem(DessertSizeRdLarge))->SetCheck(FALSE);
				break;
			case 3:
				((CButton*)GetDlgItem(DessertSizeRdSmall))->SetCheck(FALSE);
				((CButton*)GetDlgItem(DessertSizeRdMedium))->SetCheck(FALSE);
				((CButton*)GetDlgItem(DessertSizeRdLarge))->SetCheck(TRUE);
				break;
			}
			switch (dessertKind)
			{
			case 1:
				((CButton*)GetDlgItem(DessertKindRdWaffle))->SetCheck(TRUE);
				((CButton*)GetDlgItem(DessertKindRdPancake))->SetCheck(FALSE);
				((CButton*)GetDlgItem(DessertKindRdCheesecake))->SetCheck(FALSE);
				break;
			case 2:
				((CButton*)GetDlgItem(DessertKindRdWaffle))->SetCheck(FALSE);
				((CButton*)GetDlgItem(DessertKindRdPancake))->SetCheck(TRUE);
				((CButton*)GetDlgItem(DessertKindRdCheesecake))->SetCheck(FALSE);
				break;
			case 3:
				((CButton*)GetDlgItem(DessertKindRdWaffle))->SetCheck(FALSE);
				((CButton*)GetDlgItem(DessertKindRdPancake))->SetCheck(FALSE);
				((CButton*)GetDlgItem(DessertKindRdCheesecake))->SetCheck(TRUE);
				break;
			}
		}
		//Modifies IceCream:
		if (productName == _T("Ice Cream")) 
		{
			//replace 'Modify' buttons and disabling 'Add' buttons:
			GetDlgItem(ModifyIceCreamBtn)->EnableWindow(TRUE);
			GetDlgItem(IceCreamAddBtn)->EnableWindow(FALSE);
			GetDlgItem(DessertAddBtn)->EnableWindow(FALSE);
			GetDlgItem(YogurtAddBtn)->EnableWindow(FALSE);
			IceCream* selectedIceCream = ((IceCream*)MyOrder.getProductById(PrdIdToModify));
			productSize = selectedIceCream->getCupSize();
			flavorOption iceCreamFlavor = selectedIceCream->getFlavor();
			
			switch (productSize)
			{
			case 1:
				((CButton*)GetDlgItem(ICSizeRdSmall))->SetCheck(TRUE);
				((CButton*)GetDlgItem(ICSizeRdMedium))->SetCheck(FALSE);
				((CButton*)GetDlgItem(ICSizeRdLarge))->SetCheck(FALSE);
				break;
			case 2:
				((CButton*)GetDlgItem(ICSizeRdSmall))->SetCheck(FALSE);
				((CButton*)GetDlgItem(ICSizeRdMedium))->SetCheck(TRUE);
				((CButton*)GetDlgItem(ICSizeRdLarge))->SetCheck(FALSE);
				break;
			case 3:
				((CButton*)GetDlgItem(ICSizeRdSmall))->SetCheck(FALSE);
				((CButton*)GetDlgItem(ICSizeRdMedium))->SetCheck(FALSE);
				((CButton*)GetDlgItem(ICSizeRdLarge))->SetCheck(TRUE);
				break;
			}
			switch (iceCreamFlavor)
			{
			case 1:
				((CButton*)GetDlgItem(ICFlavorRdChocolate))->SetCheck(TRUE);
				((CButton*)GetDlgItem(ICFlavorRdVanilla))->SetCheck(FALSE);
				((CButton*)GetDlgItem(ICFlavorRdMixed))->SetCheck(FALSE);
				break;
			case 2:
				((CButton*)GetDlgItem(ICFlavorRdChocolate))->SetCheck(FALSE);
				((CButton*)GetDlgItem(ICFlavorRdVanilla))->SetCheck(TRUE);
				((CButton*)GetDlgItem(ICFlavorRdMixed))->SetCheck(FALSE);
				break;
			case 3:
				((CButton*)GetDlgItem(ICFlavorRdChocolate))->SetCheck(FALSE);
				((CButton*)GetDlgItem(ICFlavorRdVanilla))->SetCheck(FALSE);
				((CButton*)GetDlgItem(ICFlavorRdMixed))->SetCheck(TRUE);
				break;
			}
		}
		//Modifies Yogurt:
		if (productName == _T("Frozen Yogurt"))
		{
			GetDlgItem(ModifyYogurtBtn)->EnableWindow(TRUE);
			GetDlgItem(IceCreamAddBtn)->EnableWindow(FALSE);
			GetDlgItem(DessertAddBtn)->EnableWindow(FALSE);
			GetDlgItem(YogurtAddBtn)->EnableWindow(FALSE);
			Yogurt* selectedYogurt = ((Yogurt*)MyOrder.getProductById(PrdIdToModify));
			productSize = selectedYogurt->getCupSize();
			vector<CString>yogurtAddons = selectedYogurt->getAddons();
			
			switch (productSize)
			{
			case 1:
				((CButton*)GetDlgItem(YogurtSizeRdSmall))->SetCheck(TRUE);
				((CButton*)GetDlgItem(YogurtSizeRdMedium))->SetCheck(FALSE);
				((CButton*)GetDlgItem(YogurtSizeRdLarge))->SetCheck(FALSE);
				break;
			case 2:
				((CButton*)GetDlgItem(YogurtSizeRdSmall))->SetCheck(FALSE);
				((CButton*)GetDlgItem(YogurtSizeRdMedium))->SetCheck(TRUE);
				((CButton*)GetDlgItem(YogurtSizeRdLarge))->SetCheck(FALSE);
				break;
			case 3:
				((CButton*)GetDlgItem(YogurtSizeRdSmall))->SetCheck(FALSE);
				((CButton*)GetDlgItem(YogurtSizeRdMedium))->SetCheck(FALSE);
				((CButton*)GetDlgItem(YogurtSizeRdLarge))->SetCheck(TRUE);
				break;
			}
			

			((CButton*)GetDlgItem(OreoAddonChBx))->SetCheck(FALSE);
			((CButton*)GetDlgItem(SprinklesAddonChBx))->SetCheck(FALSE);
			((CButton*)GetDlgItem(StrawberriesAddonChBx))->SetCheck(FALSE);
			((CButton*)GetDlgItem(PineappleAddonChBx))->SetCheck(FALSE);

			for (int i = 0; i < yogurtAddons.size(); i++) 
			{
				if(yogurtAddons[i] == _T("Oreo"))
				{
					((CButton*)GetDlgItem(OreoAddonChBx))->SetCheck(TRUE);
				}
				if(yogurtAddons[i] == _T("Sprinkles"))
				{
					((CButton*)GetDlgItem(SprinklesAddonChBx))->SetCheck(TRUE);
				}
				if(yogurtAddons[i] == _T("Strawberries"))
				{
					((CButton*)GetDlgItem(StrawberriesAddonChBx))->SetCheck(TRUE);
				}
				if(yogurtAddons[i] == _T("Pineapple"))
				{
					((CButton*)GetDlgItem(PineappleAddonChBx))->SetCheck(TRUE);
				}
			}
		}
	}
}

// Modify dessert button:
void CIceCreamShopMFCDlg::OnBnClickedModifydessertbtn()
{
	Dessert* DessertToModify = (Dessert*)MyOrder.getProductById(PrdIdToModify);
	sizeOption DessertSizeOption = S;
	dessertOption DessertKind = waffle;
	CString newPrice = _T(""), totalPrice = _T("");
	// What kind has been selected:

	switch (DessertKindRd)
	{
	case 1:
		DessertToModify->setKind(waffle);
		display.SetItemText(nItemToModify, 2, _T("Waffle"));
		break;
	case 2:
		DessertToModify->setKind(pancake);
		display.SetItemText(nItemToModify, 2, _T("Pancake"));
		break;
	case 3:
		DessertToModify->setKind(cheesecake);
		display.SetItemText(nItemToModify, 2, _T("CheeseCake"));
		break;
	}

	// What size has been selected:
	switch (DessertSizeRd)
	{
	case 1:
		DessertToModify->setSize(S);
		display.SetItemText(nItemToModify, 1, _T("Small"));
		break;
	case 2:
		DessertToModify->setSize(M);
		display.SetItemText(nItemToModify, 1, _T("Medium"));
		break;
	case 3:
		DessertToModify->setSize(L);
		display.SetItemText(nItemToModify, 1, _T("Large"));
		break;
	}

	//changing price on display
	newPrice.Format(_T("%g ₪"), DessertToModify->getPrice());
	display.SetItemText(nItemToModify, 3, newPrice);

	GetDlgItem(DeletePrdBtn)->EnableWindow(TRUE);
	GetDlgItem(ModifyPrdBtn)->EnableWindow(TRUE);
	GetDlgItem(ModifyDessertBtn)->EnableWindow(FALSE);
	GetDlgItem(IceCreamAddBtn)->EnableWindow(TRUE);
	GetDlgItem(YogurtAddBtn)->EnableWindow(TRUE);
	GetDlgItem(DessertAddBtn)->EnableWindow(TRUE);

	// Update Total Price on Pay Now Button
	totalPrice.Format(_T("Pay (total: %g ₪)"), MyOrder.calculateTotalPrice());
	GetDlgItem(PayNowBtn)->SetWindowText(totalPrice);
}

// Modify IceCream button:
void CIceCreamShopMFCDlg::OnBnClickedModifyicecreambtn()
{
	IceCream* IceCreamToModify = (IceCream*)MyOrder.getProductById(PrdIdToModify);
	flavorOption IceCreamFlavorOption = chocolate;
	CString newPrice = _T(""), totalPrice = _T("");
	// What kind has been selected:
	switch (IceCreamFlavorRd)
	{
	case 1:
		IceCreamToModify->setFlavor(chocolate);
		display.SetItemText(nItemToModify, 2, _T("Chocolate"));
		break;
	case 2:
		IceCreamToModify->setFlavor(vanilla);
		display.SetItemText(nItemToModify, 2, _T("Vanilla"));
		break;
	case 3:
		IceCreamToModify->setFlavor(mixed);
		display.SetItemText(nItemToModify, 2, _T("Chocolate and Vanilla"));
		break;
	}

	// What size has been selected:
	switch (IceCreamSizeRd)
	{
	case 1:
		IceCreamToModify->setCupSize(S);
		display.SetItemText(nItemToModify, 1, _T("Small"));
		break;
	case 2:
		IceCreamToModify->setCupSize(M);
		display.SetItemText(nItemToModify, 1, _T("Medium"));
		break;
	case 3:
		IceCreamToModify->setCupSize(L);
		display.SetItemText(nItemToModify, 1, _T("Large"));
		break;
	}

	//changing price on display
	newPrice.Format(_T("%g ₪"), IceCreamToModify->getPrice());
	display.SetItemText(nItemToModify, 3, newPrice);

	GetDlgItem(DeletePrdBtn)->EnableWindow(TRUE);
	GetDlgItem(ModifyPrdBtn)->EnableWindow(TRUE);
	GetDlgItem(ModifyIceCreamBtn)->EnableWindow(FALSE);
	GetDlgItem(IceCreamAddBtn)->EnableWindow(TRUE);
	GetDlgItem(DessertAddBtn)->EnableWindow(TRUE);
	GetDlgItem(YogurtAddBtn)->EnableWindow(TRUE);

	// Update Total Price on Pay Now Button
	totalPrice.Format(_T("Pay (total: %g ₪)"), MyOrder.calculateTotalPrice());
	GetDlgItem(PayNowBtn)->SetWindowText(totalPrice);
}

// Modify Yogurt button:
void CIceCreamShopMFCDlg::OnBnClickedModifyyogurtbtn()
{
	Yogurt* yogurtToModify = (Yogurt*)MyOrder.getProductById(PrdIdToModify);
	vector<CString>yogurtAddons = {};
	CString newPrice = _T(""), specs = _T("Addons: "),totalPrice = _T("");

	// What size has been selected:
	switch (YogurtSizeRd)
	{
	case 1:
		yogurtToModify->setCupSize(S);
		display.SetItemText(nItemToModify, 1, _T("Small"));
		break;
	case 2:
		yogurtToModify->setCupSize(M);
		display.SetItemText(nItemToModify, 1, _T("Medium"));
		break;
	case 3:
		yogurtToModify->setCupSize(L);
		display.SetItemText(nItemToModify, 1, _T("Large"));
		break;
	}
	
	// Is Oreos been selected:
	if (OreoAddonChBxSelected)
	{
		yogurtAddons.push_back(_T("Oreo"));
		specs += _T("Oreo ");
	}

	// Is Sprinkles been selected:
	if (SprinklesAddonChBxSelected)
	{
		yogurtAddons.push_back(_T("Sprinkles"));
		if (specs != _T("Addons: "))
		{
			specs += _T(", Sprinkles");
		}
		else
		{
			specs += _T("Sprinkles");
		}
	}

	// Is Strawberries been selected:
	if (StrawberriesAddonChBxSelected)
	{
		yogurtAddons.push_back(_T("Strawberries"));
		if (specs != _T("Addons: "))
		{
			specs += _T(", Strawberries");
		}
		else
		{
			specs += _T("Strawberries");
		}
	}

	// Is Pineapple been selected:
	if (PineappleAddonChBxSelected)
	{
		yogurtAddons.push_back(_T("Pineapple"));
		if (specs != _T("Addons: "))
		{
			specs += _T(", Pineapple");
		}
		else
		{
			specs += _T("Pineapple");
		}
	}

	if (specs == _T("Addons: "))
	{
		specs = _T("No Addons");
	}

	yogurtToModify->setAddons(yogurtAddons);
	display.SetItemText(nItemToModify, 2, specs);
	
	GetDlgItem(DeletePrdBtn)->EnableWindow(TRUE);
	GetDlgItem(ModifyPrdBtn)->EnableWindow(TRUE);
	GetDlgItem(ModifyYogurtBtn)->EnableWindow(FALSE);
	GetDlgItem(IceCreamAddBtn)->EnableWindow(TRUE);
	GetDlgItem(DessertAddBtn)->EnableWindow(TRUE);
	GetDlgItem(YogurtAddBtn)->EnableWindow(TRUE);

	// Update Total Price on Pay Now Button
	totalPrice.Format(_T("Pay (total: %g ₪)"), MyOrder.calculateTotalPrice());
	GetDlgItem(PayNowBtn)->SetWindowText(totalPrice);
}

// ==================================================================



// ===================== Pay Now Button handler =====================
void CIceCreamShopMFCDlg::OnBnClickedPaynowbtn()
{
	if (MyOrder.getAmmount() == 0)
	{
		AfxMessageBox(_T("No items to purchase, please add one or more items."));
	}
	else
	{
		AfxMessageBox(_T("Oreded Completed!, thanks for ordering.\n\nAnd always remember:\n\"Money can't buy you happyness,\nbut it can buy you ICECREAM,\nand it basically the same thing!\""));
	}

}
// ==================================================================
