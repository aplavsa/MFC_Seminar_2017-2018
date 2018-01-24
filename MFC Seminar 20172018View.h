
// MFC Seminar 20172018View.h : interface of the CMFCSeminar20172018View class
//

#pragma once


class CMFCSeminar20172018View : public CView
{
protected: // create from serialization only
	CMFCSeminar20172018View();
	DECLARE_DYNCREATE(CMFCSeminar20172018View)

// Attributes
public:
	CMFCSeminar20172018Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCSeminar20172018View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_text;
	CPoint point;
	LOGFONT font;
	int size;
	COLORREF boja_teksta;
	CFont fontovi;

	afx_msg LRESULT OnTimer(WPARAM wParam, LPARAM lParam);

	HANDLE hThread;

	void updateTime(void);

	void startThread(void)
	{
		_beginthread(&CMFCSeminar20172018View::static_fun_2, 0, this);
	}
private:
	static void static_fun_2(void * args)
	{
		static_cast<CMFCSeminar20172018View*>(args)->updateTime();
	}
protected:
	
//	afx_msg LRESULT OnUpdatetime(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUpdatetime(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MFC Seminar 20172018View.cpp
inline CMFCSeminar20172018Doc* CMFCSeminar20172018View::GetDocument() const
   { return reinterpret_cast<CMFCSeminar20172018Doc*>(m_pDocument); }
#endif

