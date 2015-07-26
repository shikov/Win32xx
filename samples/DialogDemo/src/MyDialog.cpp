///////////////////////////////////////
// MyDialog.cpp

#include "stdafx.h"
#include "MyDialog.h"
#include "Hyperlink.h"
#include "resource.h"


// Definitions for the CMyDialog class
CMyDialog::CMyDialog(UINT nResID) : CDialog(nResID)
{
	// Load RichEdit version 2.0 or 3.0
	m_hInstRichEdit = LoadLibrary(_T("riched20.dll"));
    
	// Load RichEdit version 1.0 as a last resort
	if (m_hInstRichEdit == 0)
 		m_hInstRichEdit = LoadLibrary(_T("riched32.dll"));

	if (m_hInstRichEdit == 0)
		::MessageBox(NULL, _T("CMyDialog::CMyDialog  Failed to load RICHED32.DLL"), _T("Error"), MB_ICONWARNING);
}

CMyDialog::CMyDialog(LPCTSTR lpszResName) : CDialog(lpszResName)
{
	// Load RichEdit version 2.0 or 3.0
	m_hInstRichEdit = LoadLibrary(_T("riched20.dll"));
    
	// Load RichEdit version 1.0 as a last resort
	if (m_hInstRichEdit == 0)
 		m_hInstRichEdit = LoadLibrary(_T("riched32.dll"));

	if (m_hInstRichEdit == 0)
		::MessageBox(NULL, _T("CMyDialog::CMyDialog  Failed to load RICHED32.DLL"), _T("Error"), MB_ICONWARNING);
}

CMyDialog::~CMyDialog()
{
	::FreeLibrary(m_hInstRichEdit);
}

INT_PTR CMyDialog::DialogProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
//	switch (uMsg)
//	{
//		//Additional messages to be handled go here
//	}

	// Pass unhandled messages on to parent DialogProc
	return DialogProcDefault(uMsg, wParam, lParam); 
}

BOOL CMyDialog::OnCommand(WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	switch (LOWORD(wParam))
    {
	case IDC_BUTTON1:	return OnButton();
	case IDC_RADIO1:	return OnRadio1();
	case IDC_RADIO2:	return OnRadio2();
	case IDC_RADIO3:	return OnRadio3();
	case IDC_CHECK1:	return OnCheck1();
	case IDC_CHECK2:	return OnCheck2();
	case IDC_CHECK3:	return OnCheck3();
    }

	return FALSE;
}

void CMyDialog::OnDestroy()
{
	// End the application
	::PostQuitMessage(0);
}


BOOL CMyDialog::OnInitDialog()
{
	// Set the Icon
	SetIconLarge(IDW_MAIN);
	SetIconSmall(IDW_MAIN);

	// Put some text in the edit boxes
	SetDlgItemText(IDC_EDIT1, _T("Edit Control"));
	SetDlgItemText(IDC_RICHEDIT1, _T("Rich Edit Window"));

	// Put some text in the list box
	AttachItem(IDC_LIST1, m_ListBox);
	for (int i = 0 ; i < 8 ; i++)
		m_ListBox.AddString(_T("List Box"));

	// Turn our button into a MyButton object
	AttachItem(IDC_BUTTON2, m_Button);

	// Turn our static control into a hyperlink
	AttachItem(IDC_STATIC4, m_Hyperlink);

	return TRUE;
}

void CMyDialog::OnOK()
{
	MessageBox(_T("OK Button Pressed.  Program will exit now."), _T("Button"), MB_OK);
	CDialog::OnOK();
}

BOOL CMyDialog::OnButton()
{
	SetStatic(_T("Button Pressed"));
	TRACE("Button Pressed\n");
	return TRUE;
}

BOOL CMyDialog::OnCheck1()
{
	SetStatic(_T("Check Box 1"));
	TRACE("Check Box 1\n");
	return TRUE;
}

BOOL CMyDialog::OnCheck2()
{
	SetStatic(_T("Check Box 2"));
	TRACE("Check Box 2\n");
	return TRUE;
}

BOOL CMyDialog::OnCheck3()
{
	SetStatic(_T("Check Box 3"));
	TRACE("Check Box 3\n");
	return TRUE;
}

BOOL CMyDialog::OnRadio1()
{
	SetStatic(_T("Radio 1"));
	TRACE("Radio 1\n");
	return TRUE;
}

BOOL CMyDialog::OnRadio2()
{
	SetStatic(_T("Radio 2"));
	TRACE("Radio 2\n");
	return TRUE;
}

BOOL CMyDialog::OnRadio3()
{
	SetStatic(_T("Radio 3"));
	TRACE("Radio 3\n");
	return TRUE;
}

void CMyDialog::SetStatic(LPCTSTR szString)
{
	SetDlgItemText(IDC_STATIC3, szString);
}

