
// MFC Seminar 20172018View.cpp : implementation of the CMFCSeminar20172018View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC Seminar 20172018.h"
#endif

#include "MFC Seminar 20172018Doc.h"
#include "MFC Seminar 20172018View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define UPDATETIME 0xf0f0
#define IDT_TIMER1 0xf011


// CMFCSeminar20172018View

IMPLEMENT_DYNCREATE(CMFCSeminar20172018View, CView)

BEGIN_MESSAGE_MAP(CMFCSeminar20172018View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_MESSAGE(WM_UPDATETIME, &CMFCSeminar20172018View::OnUpdatetime)
ON_MESSAGE(UPDATETIME, &CMFCSeminar20172018View::OnUpdatetime)
ON_MESSAGE(WM_TIMER, &CMFCSeminar20172018View::OnTimer)
ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFCSeminar20172018View construction/destruction
bool isSet = false;
CMFCSeminar20172018View::CMFCSeminar20172018View()
{
	/*CMFCSeminar20172018Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	tekst *temp;
	temp = &pDoc->date;

	temp->boja_teksta = COLORREF RGB(128, 128, 128);*/

	boja_teksta = COLORREF RGB(0, 0, 0);
	CFont* fonts;
	fonts = new CFont();
	fonts->CreatePointFont(20, _T("Arial"));
	

}

CMFCSeminar20172018View::~CMFCSeminar20172018View()
{
}

BOOL CMFCSeminar20172018View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}

// CMFCSeminar20172018View drawing

void CMFCSeminar20172018View::OnDraw(CDC* pDC)
{
	CMFCSeminar20172018Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;



	CRect r;
	GetClientRect(r);
	CBrush brush;
	COLORREF boja;
	boja = COLORREF(RGB(255, 255, 255));

	brush.CreateSolidBrush(boja);
	pDC->FillRect(r, &brush);


	fontovi.CreateFontIndirectW(&font);
	CFont *def_font = pDC->SelectObject(&fontovi);


	


	tekst *temp;
	temp = &pDoc->date;
	temp->boja_teksta = boja_teksta;
	CString datum = CTime::GetCurrentTime().Format("%H:%M:%S");
	temp->tekst_stringa = datum;
	pDC->SetTextColor(temp->boja_teksta);
	pDC->TextOut(10,10, temp->tekst_stringa);
	pDC->SelectObject(def_font);


	fontovi.DeleteObject();
	/*if (isSet==false) {
		updateTime();
		isSet = true;
	}*/
	//startThread();

	

	SetTimer(IDT_TIMER1, 1000, NULL);
	
}


// CMFCSeminar20172018View printing

BOOL CMFCSeminar20172018View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCSeminar20172018View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCSeminar20172018View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCSeminar20172018View diagnostics

#ifdef _DEBUG
void CMFCSeminar20172018View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCSeminar20172018View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCSeminar20172018Doc* CMFCSeminar20172018View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSeminar20172018Doc)));
	return (CMFCSeminar20172018Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCSeminar20172018View message handlers


void CMFCSeminar20172018View::updateTime(void) {
	CString time;

	/*CMFCSeminar20172018Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	tekst* temp;
	temp = &pDoc->date;*/
	
	/*while (1) {*/
	
		time = CTime::GetCurrentTime().Format("%H:%M:%S");
		/*temp->tekst_stringa = time;*/
		Sleep(1000);
		SendMessage(UPDATETIME, 0, 0);
		
		
	


}


//afx_msg LRESULT CMFCSeminar20172018View::OnUpdatetime(WPARAM wParam, LPARAM lParam)
//{
//	return 0;
//}


afx_msg LRESULT CMFCSeminar20172018View::OnUpdatetime(WPARAM wParam, LPARAM lParam)
{
	Invalidate();
	return 0;
}

afx_msg LRESULT CMFCSeminar20172018View::OnTimer(WPARAM wParam, LPARAM lParam) {
	Invalidate();
	return 0;
}


void CMFCSeminar20172018View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CFontDialog dlg;
	if (dlg.DoModal() == IDOK) {
		boja_teksta = dlg.GetColor();
		size = dlg.GetSize();
		dlg.GetCurrentFont(&font);
	}

	CView::OnLButtonDblClk(nFlags, point);
}
