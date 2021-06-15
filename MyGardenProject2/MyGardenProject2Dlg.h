
// MyGardenProject2Dlg.h : header file
//

#pragma once

#include <vector>
#include "Plant.h"
#include"Edible.h"

using namespace std;

// CMyGardenProject2Dlg dialog
class CMyGardenProject2Dlg : public CDialogEx
{
// Construction
public:
	CMyGardenProject2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYGARDENPROJECT2_DIALOG };
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
	afx_msg void OnBnClickedCancel();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButtonAddPlant();
		afx_msg void OnBnClickedButSave();
		afx_msg void OnBnClickedButLoad();
	CComboBox m_comboBox1;
	CComboBox m_comboBox2;
	CComboBox m_comboBox3_Growing_area;

	CEdit m_editboxName;
	CEdit m_editboxSpeecies;
	CEdit m_editboxBreeding;
	CEdit m_editboxSun;
	CEdit m_editboxWatering;
	CEdit m_editboxMorInfo;
	CEdit m_editboxEatingSeason;
	CEdit m_editbox_Feeding;


//
	CTypedPtrArray<CObArray, Plant*> plant;

	//vector<Plant*> plants;
	int Vector_Search(CString name);
	bool Delete_Item(CString name);
	bool Change(CString name,CString Type);
	int Change_Flag = 0;
	CString Change_Name_Typ;
	CString Change_Typ_Typ;

	
	afx_msg void OnCbnSelchangeCombo3GrowingArea();
	
	afx_msg void OnCbnSelchangeCombo3Hadlaya();
	CComboBox m_comboBox_Hadlaya;
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonCange();
	CEdit m_editbox_View_information;
	afx_msg void OnBnClickedButtonViewData();
	CString m_Valu_Info_View;
	CListCtrl m_list_control_ltems;
};

