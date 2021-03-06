// NewMod.cpp: 实现文件
//

#include "stdafx.h"
#include "mod.h"
#include "NewMod.h"
#include "afxdialogex.h"
#include "Select.h"
#include "MainFrm.h"

CString path, name;

// CNewMod 对话框

IMPLEMENT_DYNAMIC(CNewMod, CDialogEx)

CNewMod::CNewMod(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NEWMOD, pParent)
{

}

CNewMod::~CNewMod()
{
}

void CNewMod::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNewMod, CDialogEx)
	ON_BN_CLICKED(IDB_MODVIEW, &CNewMod::OnModView)
	ON_BN_CLICKED(IDB_MODCREATE, &CNewMod::OnModCreate)
END_MESSAGE_MAP()


// CNewMod 消息处理程序


void CNewMod::OnModView()
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit* modPath = (CEdit*)GetDlgItem(IDE_MODPATH);
	modPath->SetWindowText(Select::SelectFolder(this));
}


void CNewMod::OnModCreate()
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit* modPath = (CEdit*)GetDlgItem(IDE_MODPATH);
	modPath->GetWindowText(path);
	CEdit* modName = (CEdit*)GetDlgItem(IDE_MODNAME);
	modName->GetWindowText(name);
	//MessageBox(_T("1"));
	CMainFrame* frame = (CMainFrame*)AfxGetMainWnd();
	//MessageBox(_T("2"));
	frame->CreateDirectoy(CD_NORMAL);
	//MessageBox(_T("3"));
	this->PostMessage(WM_CLOSE);
	//MessageBox(_T("4"));
}
