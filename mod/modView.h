
// modView.h: CmodView 类的接口
//

#pragma once


class CmodView : public CFormView
{
protected: // 仅从序列化创建
	CmodView() noexcept;
	DECLARE_DYNCREATE(CmodView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MOD_FORM };
#endif

// 特性
public:
	CmodDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CmodView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNewMod();
};

#ifndef _DEBUG  // modView.cpp 中的调试版本
inline CmodDoc* CmodView::GetDocument() const
   { return reinterpret_cast<CmodDoc*>(m_pDocument); }
#endif

