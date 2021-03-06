
// modView.cpp: CmodView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "mod.h"
#endif

#include "modDoc.h"
#include "modView.h"
#include "NewMod.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//CString path, name;

// CmodView

IMPLEMENT_DYNCREATE(CmodView, CFormView)

BEGIN_MESSAGE_MAP(CmodView, CFormView)
	ON_COMMAND(ID_MOD_NEW, &CmodView::OnNewMod)
END_MESSAGE_MAP()

// CmodView 构造/析构

CmodView::CmodView() noexcept
	: CFormView(IDD_MOD_FORM)
{
	// TODO: 在此处添加构造代码

}

CmodView::~CmodView()
{
}

void CmodView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CmodView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CmodView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CmodView 诊断

#ifdef _DEBUG
void CmodView::AssertValid() const
{
	CFormView::AssertValid();
}

void CmodView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CmodDoc* CmodView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmodDoc)));
	return (CmodDoc*)m_pDocument;
}
#endif //_DEBUG


// CmodView 消息处理程序


void CmodView::OnNewMod()
{
	// TODO: 在此添加命令处理程序代码
	CNewMod dlg;
	dlg.DoModal();
}
