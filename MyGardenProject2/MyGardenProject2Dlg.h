
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
	afx_msg void OnBnClickedButtonAddPlant();
	afx_msg void OnBnClickedButSave();
	afx_msg void OnBnClickedButLoad();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonCange();
	afx_msg void OnBnClickedButtonViewData();

	CComboBox m_comboBox1;
	CComboBox m_comboBox2;
	CComboBox m_comboBox3_Growing_area;
	CComboBox m_comboBox_Hadlaya;


	CEdit m_editboxName;
	CEdit m_editboxSpeecies;
	CEdit m_editboxBreeding;
	CEdit m_editboxSun;
	CEdit m_editboxWatering;
	CEdit m_editboxMorInfo;
	CEdit m_editboxEatingSeason;
	CEdit m_editbox_Feeding;
	CEdit m_editbox_View_information;

	CListCtrl m_list_control_ltems;
//
	CTypedPtrArray<CObArray, Plant*> plant;
	CString m_Valu_Info_View;

	int Vector_Search(CString name);
	int Change_Flag = 0;
	int Save_Flag = 0;

	bool Delete_Item();
	bool Change(CString name,CString Type);

	void Reload_List_Contrl();
	void ViewData(CString name, CString Type);
	void Return_Name_and_Type(CString* name, CString* Type);//מחזיר את השם והסוג הצמח by referns

	//זמני משתני בדיקה 
	CString Change_Name_Typ;
	CString Change_Typ_Typ;

	
};

