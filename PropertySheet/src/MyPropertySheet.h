
#ifndef MYPROPERTYSHEET_H
#define MYPROPERTYSHEET_H

#include "../../Win32++/propertysheet.h"


class CMyPropertySheet : public CPropertySheet
{
public:
	CMyPropertySheet(LPCTSTR pszCaption = NULL, HWND hwndParent = NULL);
	virtual LRESULT WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

};

class CButtonPage : public CPropertyPage
{
public:
	CButtonPage(UINT nIDTemplate, LPCTSTR szTitle = NULL);
	virtual BOOL DialogProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual void OnApply();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual BOOL OnQueryCancel();
	virtual void OnSetActive();
	virtual int Validate();
};

class CComboPage : public CPropertyPage
{
public:
	CComboPage(UINT nIDTemplate, LPCTSTR szTitle  = NULL);
	virtual BOOL DialogProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual void OnSetActive();
};


#endif // MYPROPERTYSHEET_H

