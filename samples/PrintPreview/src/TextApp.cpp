///////////////////////////////////////////////
// TextApp.cpp -  Definitions for the CTextApp class

#include "stdafx.h"
#include "TextApp.h"
#include "resource.h"

// Constructor.
CTextApp::CTextApp()
{
}

// Called when the application starts.
BOOL CTextApp::InitInstance()
{
    //Create the Frame Window
    m_frame.Create();   // throws a CWinException on failure

    return TRUE;
}

// Called when the message queue is empty.
BOOL CTextApp::OnIdle(LONG count)
{
    UNREFERENCED_PARAMETER(count);
    m_frame.OnToolbarUpdate();

    return FALSE;
}

