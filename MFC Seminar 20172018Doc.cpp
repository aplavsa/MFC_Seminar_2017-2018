
// MFC Seminar 20172018Doc.cpp : implementation of the CMFCSeminar20172018Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC Seminar 20172018.h"
#endif

#include "MFC Seminar 20172018Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCSeminar20172018Doc

IMPLEMENT_DYNCREATE(CMFCSeminar20172018Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCSeminar20172018Doc, CDocument)
END_MESSAGE_MAP()


// CMFCSeminar20172018Doc construction/destruction

CMFCSeminar20172018Doc::CMFCSeminar20172018Doc()
{
	//date = tekst();
	tocka.SetPoint(0, 0);
	m_text = "Neki tekst!";

}

CMFCSeminar20172018Doc::~CMFCSeminar20172018Doc()
{
}

BOOL CMFCSeminar20172018Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCSeminar20172018Doc serialization

void CMFCSeminar20172018Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCSeminar20172018Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCSeminar20172018Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCSeminar20172018Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCSeminar20172018Doc diagnostics

#ifdef _DEBUG
void CMFCSeminar20172018Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCSeminar20172018Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCSeminar20172018Doc commands

tekst::tekst() {
	tekst_stringa = "tekst";
	boja_teksta = 0x00000000;


}
tekst::tekst(CString input, COLORREF color, LOGFONT font_text, CPoint position)
{
	this->tekst_stringa = input;
	this->boja_teksta = color;
	this->fonts = font_text;
	this->tocka = position;








}

tekst::~tekst()
{};
