//////////////////////////////////////////////////
// ThreadApp.h
//  Declaration of the CThreadApp class

#ifndef THREADAPP_H
#define THREADAPP_H

#include "MainWnd.h"

class CThreadApp : public CWinApp
{
public:
    CThreadApp();
    virtual ~CThreadApp();
    virtual BOOL InitInstance();
    CMainWindow& GetMainWnd() {return m_mainWnd;}

private:
    CMainWindow m_mainWnd;  
};


// returns a pointer to the CThreadApp object
inline CThreadApp* GetThreadApp() { return static_cast<CThreadApp*>(GetApp()); }


#endif  //THREADAPP_H

