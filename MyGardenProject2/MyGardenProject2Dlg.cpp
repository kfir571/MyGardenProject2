
// MyGardenProject2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MyGardenProject2.h"
#include "MyGardenProject2Dlg.h"
#include "afxdialogex.h"
#include "Plant.h"
#include"Edible.h"
#include"Ornamental.h"
#include"Carnivorous_plant.h"
#include"Climbing_Plant.h"

using namespace std;

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


// CMyGardenProject2Dlg dialog
  

/////////////////////////////////////////////////////////////////////////////    ����

CMyGardenProject2Dlg::CMyGardenProject2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYGARDENPROJECT2_DIALOG, pParent)
	, m_Valu_Info_View(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	Change_Name_Typ = "kfir";
	Change_Typ_Typ = "dor";
	//plants.resize(20);
	
}

void CMyGardenProject2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_comboBox1);
	DDX_Control(pDX, IDC_COMBO2, m_comboBox2);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editboxName);
	DDX_Control(pDX, IDC_EDIT_SPECIES, m_editboxSpeecies);
	DDX_Control(pDX, IDC_EDIT_BREEDING_GRUND, m_editboxBreeding);
	DDX_Control(pDX, IDC_EDIT_SUN_EXPOSURE, m_editboxSun);
	DDX_Control(pDX, IDC_EDIT_WATERING, m_editboxWatering);
	DDX_Control(pDX, IDC_EDIT_MORE_INFO, m_editboxMorInfo);
	DDX_Control(pDX, IDC_EDIT_EATING_SEASON, m_editboxEatingSeason);

	DDX_Control(pDX, IDC_COMBO3_GROWING_AREA, m_comboBox3_Growing_area);
	DDX_Control(pDX, IDC_EDIT_FEEDING, m_editbox_Feeding);
	DDX_Control(pDX, IDC_COMBO3_HADLAYA, m_comboBox_Hadlaya);
	DDX_Control(pDX, IDC_EDIT_VIEW_INFORMATION, m_editbox_View_information);
	DDX_Text(pDX, IDC_EDIT_VIEW_INFORMATION, m_Valu_Info_View);
	DDX_Control(pDX, IDC_LIST_CONTROL_ITEMS, m_list_control_ltems);
}

BEGIN_MESSAGE_MAP(CMyGardenProject2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CMyGardenProject2Dlg::OnBnClickedCancel)

	ON_CBN_SELCHANGE(IDC_COMBO1, &CMyGardenProject2Dlg::OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMyGardenProject2Dlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON_ADD_PLANT, &CMyGardenProject2Dlg::OnBnClickedButtonAddPlant)
	ON_BN_CLICKED(IDC_BUT_SAVE, &CMyGardenProject2Dlg::OnBnClickedButSave)
	ON_BN_CLICKED(IDC_BUT_LOAD, &CMyGardenProject2Dlg::OnBnClickedButLoad)
	ON_CBN_SELCHANGE(IDC_COMBO3_GROWING_AREA, &CMyGardenProject2Dlg::OnCbnSelchangeCombo3GrowingArea)
	ON_CBN_SELCHANGE(IDC_COMBO3_HADLAYA, &CMyGardenProject2Dlg::OnCbnSelchangeCombo3Hadlaya)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CMyGardenProject2Dlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_CANGE, &CMyGardenProject2Dlg::OnBnClickedButtonCange)
	ON_BN_CLICKED(IDC_BUTTON_VIEW_DATA, &CMyGardenProject2Dlg::OnBnClickedButtonViewData)
END_MESSAGE_MAP()


// CMyGardenProject2Dlg message handlers

BOOL CMyGardenProject2Dlg::OnInitDialog()
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
	DWORD dwExStyle = m_list_control_ltems.GetExtendedStyle();
	m_list_control_ltems.SetExtendedStyle(dwExStyle | LVS_EX_CHECKBOXES | LVS_EX_BORDERSELECT);
	m_list_control_ltems.InsertColumn(0, _T("Type"), LVCFMT_CENTER, 100);
	m_list_control_ltems.InsertColumn(1, _T("Name"), LVCFMT_CENTER, 100);
	m_list_control_ltems.ModifyStyle(LVS_TYPEMASK, LVS_REPORT); // ����� ������ �� �������


	//m_list_control_ltems.SetItemText(0, 0, _T("0,0"));
	//m_list_control_ltems.SetItemText(0, 1, _T("0,1"));

	//m_list_control_ltems.InsertItem(1, _T("fdgfd"));

	//m_list_control_ltems.SetItemText(1, 0, _T("1,0"));
	//m_list_control_ltems.SetItemText(1, 1, _T("1,1"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyGardenProject2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyGardenProject2Dlg::OnPaint()
{
	CRect rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
	int screen_x_size = rect.Width();
	int screen_y_size = rect.Height();
	::SetWindowPos(m_hWnd, HWND_TOPMOST, 150, 150, screen_x_size -295, screen_y_size-270, SWP_NOZORDER);

	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		//


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
HCURSOR CMyGardenProject2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyGardenProject2Dlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}



void CMyGardenProject2Dlg::OnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}


void CMyGardenProject2Dlg::OnCbnSelchangeCombo2()
{

	int combobox2SelctedItem = m_comboBox2.GetCurSel();
	if (combobox2SelctedItem !=LB_ERR)
	{
		CString str;
		m_comboBox2.GetLBText(combobox2SelctedItem, str);
	}
}


void CMyGardenProject2Dlg::OnBnClickedButtonAddPlant()
{
    int combobox3SelctedItem;
	int combobox4SelctedItem;
	int combobox1SelctedItem = m_comboBox1.GetCurSel();
	int combobox2SelctedItem = m_comboBox2.GetCurSel();
	
	//Checks whether the plant type rubric is complete
	if (combobox2SelctedItem != LB_ERR)
	{
		CString Name, Speecies, Breeding, Sun, Watering, MorInfo, 
			EatingSeason, Plant_type, Planting_season, Growing_area, Feeding, Hadlaya;

		//���� �� ��� ������ ����� ����� 
		m_comboBox2.GetLBText(combobox2SelctedItem, Plant_type);

		//���� �� ������� �� comboBox1
		m_comboBox1.GetLBText(combobox1SelctedItem, Planting_season);
		//���� �� ������� �� edit box
		m_editboxName.GetWindowTextW(Name);
		m_editboxSpeecies.GetWindowTextW(Speecies);
		m_editboxBreeding.GetWindowTextW(Breeding);
		m_editboxSun.GetWindowTextW(Sun);
		m_editboxWatering.GetWindowTextW(Watering);
		m_editboxMorInfo.GetWindowTextW(MorInfo);
		m_editboxEatingSeason.GetWindowTextW(EatingSeason);
		m_editboxMorInfo.GetWindowTextW(MorInfo);

		//Checks if the plant is in a database
		if (Vector_Search(Name) == -1)
		{
			//Creat the laibel in the list control
			m_list_control_ltems.InsertItem(0, _T(""));
			m_list_control_ltems.SetItemText(0, 1, Name);
			//Create a new object And puts it into a vector
			switch (Plant_type.GetLength())
			{
				//"Edible plant"
			case 12:
				TRACE(_T("Edible plant\n"));
				m_list_control_ltems.SetItemText(0, 0, _T("Edible plant"));
			//	plants.push_back(new Edible(Name, Speecies, Breeding, Sun, Watering));
				plant.Add(new Edible(Name, Speecies, Breeding, Sun, Watering, Planting_season, EatingSeason, MorInfo));
				break;
				//"Carnivorous plant"
			case 17:
				TRACE(_T("Carnivorous plant"));
				m_list_control_ltems.SetItemText(0, 0, _T("Carnivorous plant"));
				m_editbox_Feeding.GetWindowTextW(Feeding);
				combobox3SelctedItem = m_comboBox3_Growing_area.GetCurSel();
				m_comboBox3_Growing_area.GetLBText(combobox2SelctedItem, Growing_area);
				plant.Add(new Carnivorous_plant(Name, Speecies, Breeding, Sun, Watering, Planting_season, Growing_area, Feeding, MorInfo));
				//plant[plant.GetCount() - 1]->Get_Hadlaya;
				break;

				//"A climbing plant"
			case 16:
				TRACE(_T("A climbing plant"));
				m_list_control_ltems.SetItemText(0, 0, _T("A climbing plant"));
				combobox4SelctedItem = m_comboBox_Hadlaya.GetCurSel();
				m_comboBox_Hadlaya.GetLBText(combobox4SelctedItem, Hadlaya);
				combobox3SelctedItem = m_comboBox3_Growing_area.GetCurSel();
				m_comboBox3_Growing_area.GetLBText(combobox2SelctedItem, Growing_area);
				plant.Add(new Climbing_Plant(Name, Speecies, Breeding, Sun, Watering, Planting_season, Growing_area,Hadlaya, MorInfo));
				break;
				//"An ornamental plant"
			case 19:
				TRACE(_T("An ornamental plant"));
				m_list_control_ltems.SetItemText(0, 0, _T("An ornamental plant"));
				combobox3SelctedItem = m_comboBox3_Growing_area.GetCurSel();
				m_comboBox3_Growing_area.GetLBText(combobox2SelctedItem, Growing_area);
				plant.Add(new Ornamental(Name, Speecies, Breeding, Sun, Watering, Planting_season, Growing_area, MorInfo));
				break;


			default:
				// code block
				break;
			}
			//int t = 0;
			//Name = plants.back()->Get_Name();
			//TRACE(Name);


			//Clears the cells of the data
			m_editboxName.SetWindowTextW(_T(""));
			m_editboxSpeecies.SetWindowTextW(_T(""));
			m_editboxBreeding.SetWindowTextW(_T(""));
			m_editboxSun.SetWindowTextW(_T(""));
			m_editboxWatering.SetWindowTextW(_T(""));
			m_editboxMorInfo.SetWindowTextW(_T(""));
			m_editboxEatingSeason.SetWindowTextW(_T(""));
			m_comboBox1.SetWindowTextW(_T(""));
			m_comboBox2.SetWindowTextW(_T(""));
			m_comboBox3_Growing_area.SetWindowTextW(_T(""));
			m_comboBox_Hadlaya.SetWindowTextW(_T(""));
			m_editbox_Feeding.SetWindowTextW(_T(""));
		}
		else
		{
			AfxMessageBox(_T("���� ���� �����"));
		}
	}
	else
	{
		AfxMessageBox(_T("�� ���� �� ��� �����"));
		
	}



	
}


//Returns the position in the vector, otherwise returns -1
int CMyGardenProject2Dlg::Vector_Search(CString name) {
	int to_return = -1;
	for (int i = 0; i < plant.GetSize() ; i++)
	{
		if (plant[i]->Get_Name() == name)
		{
			to_return = i;
			break;
		}
	}
	return to_return;
}

//Delete an organ from an index Returns 1 if deleted otherwise 0
bool CMyGardenProject2Dlg::Delete_Item(CString name) {

	CObject* path;
	int index = Vector_Search(name);
	if ( index != -1  && (path = plant.GetAt(index)) != NULL)
	{
		plant.RemoveAt(index);
		delete path;

		return 1;
	}
	return 0;
}

bool CMyGardenProject2Dlg::Change(CString name, CString Type) {

	Plant* path;
	int index = Vector_Search(name);
	int combobox1SelctedItem = m_comboBox1.GetCurSel();

	if (Change_Flag == 0 && index != -1)
	{
		Change_Flag = 1;
		path = plant.GetAt(index);
		
		if (path->Return_Type() == Type)
		{
			Change_Name_Typ = name;
			Change_Typ_Typ = Type;


	
			m_editboxName.SetWindowTextW(path->Get_Name());
			m_editboxSpeecies.SetWindowTextW(path->Get_Species());
			m_editboxBreeding.SetWindowTextW(path->Get_Breeding_Grund());
			m_editboxSun.SetWindowTextW(path->Get_Sun_Exposure());
			m_editboxWatering.SetWindowTextW(path->Get_Watering());
			m_editboxMorInfo.SetWindowTextW(path->Get_Mor_Info());/////// �� ����
			m_comboBox1.SetWindowTextW(path->Get_Planting_season());
		
			switch (Type.GetLength())
			{
			case 12:
				TRACE(_T("Edible plant\n"));
				m_editboxEatingSeason.SetWindowTextW(path->Get_Information());

				break;
				//"Carnivorous plant"
			case 17:
				TRACE(_T("Carnivorous plant"));
				m_comboBox3_Growing_area.SetWindowTextW(path->Get_Father_Information());
				m_editbox_Feeding.SetWindowTextW(path->Get_Information());
				break;
				//"A climbing plant"
			case 16:
				TRACE(_T("A climbing plant"));
				m_comboBox_Hadlaya.SetWindowTextW(path->Get_Information());
				m_comboBox3_Growing_area.SetWindowTextW(path->Get_Father_Information());
				break;
				//"An ornamental plant"
			case 19:
				TRACE(_T("An ornamental plant"));
				m_comboBox3_Growing_area.SetWindowTextW(path->Get_Information());
				break;


			default:
				// code block
				break;
			}
			return 1;

		}

	}

	
	if (Change_Flag == 1 && Change_Name_Typ == name && Change_Typ_Typ == Type && index != -1)// ���� ������� ���� ���� ���� ������� ������ ���� ���� �� ��� �������
	{
		path = plant.GetAt(index);

		CString Name, Speecies, Breeding, Sun, Watering, MorInfo,
			    EatingSeason, Plant_type, Planting_season, Growing_area, Feeding, Hadlaya;

		
		combobox1SelctedItem = m_comboBox1.GetCurSel();
		
		//m_comboBox1.GetLBText(combobox1SelctedItem, Planting_season);
		//path->Set_Planting_season(Planting_season);

		m_editboxName.GetWindowTextW(Name);
		path->Set_Name(Name);

		m_editboxSpeecies.GetWindowTextW(Speecies);
		path->Set_Species(Speecies);

		m_editboxBreeding.GetWindowTextW(Breeding);
		path->Set_Breeding_Grund(Breeding);

		m_editboxSun.GetWindowTextW(Sun);
		path->Set_Sun_Exposure(Sun);

		m_editboxWatering.GetWindowTextW(Watering);
		path->Set_Watering(Watering);

		m_comboBox1.GetWindowTextW(Planting_season);
		path->Set_Planting_season(Planting_season);
		


		m_editboxMorInfo.GetWindowTextW(MorInfo);////////////�� ����
		path->Set_Mor_Info(MorInfo);

		switch (Type.GetLength())
		{
		case 12:
			TRACE(_T("Edible plant\n"));
			//path->Get_Information();
			//path->Get_Planting_season();
			m_editboxEatingSeason.GetWindowTextW(EatingSeason);
			path->Set_Information(EatingSeason);

			break;
			//"Carnivorous plant"
		case 17:
			TRACE(_T("Carnivorous plant"));
			m_comboBox3_Growing_area.GetWindowTextW(Growing_area);
			path->Set_Father_Information(Growing_area);
			m_editbox_Feeding.GetWindowTextW(Feeding);
			path->Set_Information(Feeding);
			//m_editbox_Feeding.SetWindowTextW(path->Get_Planting_season())
			break;
			//"A climbing plant"
		case 16:
			TRACE(_T("A climbing plant"));
			m_comboBox3_Growing_area.GetWindowTextW(Growing_area);
			path->Set_Father_Information(Growing_area);
			m_comboBox_Hadlaya.GetWindowTextW(Hadlaya);
			path->Set_Information(Hadlaya);
			break;
			//"An ornamental plant"
		case 19:
			TRACE(_T("An ornamental plant"));
			break;
			m_comboBox3_Growing_area.GetWindowTextW(Growing_area);
			path->Set_Information(Growing_area);

		default:
			// code block
			break;
		}

		//����� �������
		m_editboxName.SetWindowTextW(_T(""));
		m_editboxSpeecies.SetWindowTextW(_T(""));
		m_editboxBreeding.SetWindowTextW(_T(""));
		m_editboxSun.SetWindowTextW(_T(""));
		m_editboxWatering.SetWindowTextW(_T(""));
		m_editboxMorInfo.SetWindowTextW(_T(""));
		m_editboxEatingSeason.SetWindowTextW(_T(""));
		m_comboBox1.SetWindowTextW(_T(""));
		m_comboBox2.SetWindowTextW(_T(""));
		m_comboBox3_Growing_area.SetWindowTextW(_T(""));
		m_comboBox_Hadlaya.SetWindowTextW(_T(""));
		m_editbox_Feeding.SetWindowTextW(_T(""));
		
		Change_Flag = 0;
		return 1;

	}
	return 0;
}

void CMyGardenProject2Dlg::OnBnClickedButSave()
{
	const TCHAR szFilter[] = _T("Plant files(*.Plant)|*.Plamt|AiiFiles(*.*)|*.*||");
	CFileDialog fDialog(FALSE, _T("plant"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	if (fDialog.DoModal() == IDOK)
	{
		CString fileName = fDialog.GetPathName();
		CFile file(fileName, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		plant.Serialize(ar);
		ar.Close();
		file.Close();
		
	}
}


void CMyGardenProject2Dlg::OnBnClickedButLoad()
{
	const TCHAR szFilter[] = _T("Plant files(*.Plant)|*.Plamt|AiiFiles(*.*)|*.*||");
	CFileDialog fDialog(TRUE, _T("plant"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	if (fDialog.DoModal() == IDOK)
	{
		CString fileName = fDialog.GetPathName();
		CFile file(fileName, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		plant.Serialize(ar);
		ar.Close();
		file.Close();
	}
}

//delet
void CMyGardenProject2Dlg::OnCbnSelchangeCombo3GrowingArea()
{
	// TODO: Add your control notification handler code here
}

//delet
void CMyGardenProject2Dlg::OnCbnSelchangeCombo3Hadlaya()
{
	// TODO: Add your control notification handler code here
}


void CMyGardenProject2Dlg::OnBnClickedButtonDelete()
{
	CString name;
	m_editboxName.GetWindowTextW(name);
	if (Delete_Item(name))
	{
		TRACE(_T("Deletion succeeded"));
		AfxMessageBox(_T("Deletion succeeded"));
		
	}
	else
	{
		AfxMessageBox(_T("Deletion failed"));
		TRACE(_T("Deletion failed"));
	}
}


void CMyGardenProject2Dlg::OnBnClickedButtonCange()
{

	CString name, Plant_type;

	int combobox2SelctedItem = m_comboBox2.GetCurSel();	m_editboxName.GetWindowTextW(name);

	if (combobox2SelctedItem != LB_ERR && name != "")
	{
		
		m_comboBox2.GetLBText(combobox2SelctedItem, Plant_type);

		if (Change(name,Plant_type))
		{
			AfxMessageBox(_T("Change Secses"));
			TRACE(_T("Change Secses"));
		}
		else
		{
			AfxMessageBox(_T("Change failed"));
			TRACE(_T("Change failed"));
		}
	}
	else
	{
		AfxMessageBox(_T("�� ���� �� ����� �� ��� ����\n ��� ����"));
	}

}


void CMyGardenProject2Dlg::OnBnClickedButtonViewData()
{
	CString Name, Speecies, Breeding, Sun, Watering, MorInfo;
	CString	EatingSeason, Plant_type, Planting_season, Growing_area, Feeding, Hadlaya;
	Plant* path;
	CString name, View_data;
	m_editboxName.GetWindowTextW(name);
	int index = Vector_Search(name);
	int combobox2SelctedItem = m_comboBox2.GetCurSel();
	if (combobox2SelctedItem != LB_ERR && index != -1)
	{
		m_comboBox2.GetWindowTextW(Plant_type);
		path = plant.GetAt(index);
		
		Name = path->Get_Name();
		Speecies = path->Get_Species();
		Breeding = path->Get_Breeding_Grund();
		Sun = path->Get_Sun_Exposure();
		Watering = path->Get_Watering();
		Planting_season = path->Get_Planting_season();




		switch (Plant_type.GetLength())
		{
		case 12:
			TRACE(_T("Edible plant\n"));
			EatingSeason = path->Get_Information();
			View_data += _T(":��") + Name+ _T("\n") + _T("��:") + Speecies ;
			UpdateData(TRUE);
		//	View_data.Format("name: %s,\r\nspess: % s\r\n"),Name, Speecies);
				UpdateData(FALSE);
			break;
			//"Carnivorous plant"
		case 17:
			TRACE(_T("Carnivorous plant"));
			Growing_area = path->Get_Father_Information();
			Feeding = path->Get_Information();
			break;
			//"A climbing plant"
		case 16:
			TRACE(_T("A climbing plant"));
			Growing_area = path->Get_Father_Information();
			Hadlaya = path->Get_Information();
			break;
			//"An ornamental plant"
		case 19:
			TRACE(_T("An ornamental plant"));
			break;
			Growing_area = path->Get_Information();
		default:
			// code block
			break;
		}


		CString a, b, myString = _T("This is a test");
		a = myString;
		a += _T("\n") + myString;


	}

}