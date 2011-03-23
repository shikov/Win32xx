///////////////////////////////////////
// FormDoc.cpp

// Based on code provided by Lynn Allan


#include "stdafx.h"
#include "FormDoc.h"


// Definitions for the CFormDoc class
CFormDoc::CFormDoc() : m_bCheckA(FALSE), m_bCheckB(FALSE),
                       m_bCheckC(FALSE), m_Radio(0)
{
}

CFormDoc::~CFormDoc()
{
}

DWORD CFormDoc::GetRegDwordFromOpenKey(HKEY hKey, LPCTSTR pName)
{
  DWORD   dwType;
  DWORD   dwCount = sizeof(DWORD);
  DWORD   dwValue = 0;
  if (ERROR_SUCCESS == RegQueryValueEx(hKey, pName, NULL, &dwType, (LPBYTE)&dwValue, &dwCount))
	  return dwValue;
  else
	  return 0;
}

void CFormDoc::LoadDocRegistry(LPCTSTR szKeyName)
{
	HKEY hKey;
	tString tsKey = _T("Software\\");
	tsKey += szKeyName;
	tsKey += _T("\\Document Settings");
	if (ERROR_SUCCESS ==RegOpenKeyEx(HKEY_CURRENT_USER, tsKey.c_str(), 0,
		KEY_READ, &hKey))
	{
		m_bCheckA = GetRegDwordFromOpenKey(hKey, _T("CheckA")) & 1;
		m_bCheckB = GetRegDwordFromOpenKey(hKey, _T("CheckB")) & 1;
		m_bCheckC = GetRegDwordFromOpenKey(hKey, _T("CheckC")) & 1;
		m_Radio = GetRegDwordFromOpenKey(hKey, _T("Radio"));

		RegCloseKey(hKey);
	}
}

void CFormDoc::SaveDocRegistry(LPCTSTR szKeyName)
{
	HKEY hKey;
	tString tsKey = _T("Software\\");
	tsKey += szKeyName;
	tsKey += _T("\\Document Settings");

	RegCreateKeyEx(HKEY_CURRENT_USER, tsKey.c_str(), 0, NULL,
		REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);

	RegSetValueEx(hKey, _T("CheckA"), 0, REG_DWORD, (LPBYTE)&m_bCheckA, sizeof(DWORD));
	RegSetValueEx(hKey, _T("CheckB"), 0, REG_DWORD, (LPBYTE)&m_bCheckB, sizeof(DWORD));
	RegSetValueEx(hKey, _T("CheckC"), 0, REG_DWORD, (LPBYTE)&m_bCheckC, sizeof(DWORD));
	RegSetValueEx(hKey, _T("Radio"), 0, REG_DWORD, (LPBYTE)&m_Radio, sizeof(DWORD));

	RegCloseKey(hKey);
}

