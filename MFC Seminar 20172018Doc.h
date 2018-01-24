
// MFC Seminar 20172018Doc.h : interface of the CMFCSeminar20172018Doc class
//

#include "atlcoll.h"
#pragma once



class tekst
{
public:
	tekst();
	CString tekst_stringa;
	COLORREF boja_teksta;
	LOGFONT fonts;


	~tekst();
	CPoint tocka;

	tekst(CString input, COLORREF color, LOGFONT font_text, CPoint position);





};


class CMFCSeminar20172018Doc : public CDocument
{
protected: // create from serialization only
	CMFCSeminar20172018Doc();
	DECLARE_DYNCREATE(CMFCSeminar20172018Doc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMFCSeminar20172018Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

public:
	CString m_text;
	CPoint tocka;
	tekst date;
};
