////////////////////////////////////////
// BrowserApp.cpp

#include "stdafx.h"
#include "BrowserApp.h"


// Definitions for the CBrowserApp class
CBrowserApp::CBrowserApp()
{
    // Constructor for CBrowserApp
}

BOOL CBrowserApp::InitInstance()
{
    // This function is called automatically when the application starts

    // Create the Frame
    m_Frame.Create();

	return TRUE;
}
