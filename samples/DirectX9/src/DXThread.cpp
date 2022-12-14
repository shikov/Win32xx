/////////////////////////////
// DXThread.cpp
//

#include "stdafx.h"
#include "DXApp.h"


////////////////////////////////////////
// CDXThread function definitions
//

// Constructor
CDXThread::CDXThread() : m_pView(0)
{
}

// Destructor
CDXThread::~CDXThread()
{
}

// This function runs when the thread starts
BOOL CDXThread::InitInstance()
{
    CMainFrame& frame = GetDXApp()->GetMainFrame();
    CDXView& view = frame.GetDXView();

    // assign the m_pView member variable
    m_pView = &view;

    // Create the DXView window.
    view.CreateEx(0, _T("DXView"), NULL, WS_CHILD | WS_VISIBLE, CRect(), frame, 0);

    return TRUE;    // return TRUE to run the message loop
}

// Here we override CWinThread::MessageLoop to accommodate the special needs of DirectX
int CDXThread::MessageLoop()
{
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while( msg.message != WM_QUIT )
    {
        if ( PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
        }
        else
        {
            // Reduce the thread's performance impact.
            if (WAIT_TIMEOUT == ::WaitForSingleObject(*this, 1))
                m_pView->Render();
        }
    }

    return LOWORD(msg.wParam);
}

