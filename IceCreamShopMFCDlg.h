
// IceCreamShopMFCDlg.h : header file
//

#pragma once

#include "Product.h"
#include "Dessert.h"
#include "Frozen.h"
#include "IceCream.h"
#include "Yogurt.h"
#include "Order.h"
using namespace sizesAndKinds;

// CIceCreamShopMFCDlg dialog
class CIceCreamShopMFCDlg : public CDialogEx
{
// Construction
public:
	CIceCreamShopMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ICECREAMSHOPMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int DessertSizeRd;
	afx_msg void OnBnClickedDessertsizerdsmall();
	afx_msg void OnBnClickedDessertsizerdmedium();
	afx_msg void OnBnClickedDessertsizerdlarge();
	int DessertKindRd;
	afx_msg void OnBnClickedDessertkindrdwaffle();
	afx_msg void OnBnClickedDessertkindrdpancake();
	afx_msg void OnBnClickedDessertkindrdcheesecake();
	afx_msg void OnBnClickedDessertaddbtn();
	int IceCreamFlavorRd;
	afx_msg void OnBnClickedIcflavorrdchocolate();
	afx_msg void OnBnClickedIcflavorrdvanilla();
	afx_msg void OnBnClickedIcflavorrdmixed();
	int IceCreamSizeRd;
	afx_msg void OnBnClickedIcsizerdsmall();
	afx_msg void OnBnClickedIcsizerdmedium();
	afx_msg void OnBnClickedIcsizerdlarge();
	afx_msg void OnBnClickedIcecreamaddbtn();
};
