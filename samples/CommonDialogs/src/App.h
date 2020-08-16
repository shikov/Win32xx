/* (28-Aug-2016) [Tab/Indent: 8/8][Line/Box: 80/74]                    (App.h) *
********************************************************************************
|                                                                              |
|                    Authors: Robert Tausworthe, David Nash                    |
|                                                                              |
===============================================================================*

    Contents Description: Declaration of the CApp class for the CommonDialogs 
    sample program using the Win32++ Windows interface classes. A global access
    function is also defined to the CApp object.

    Programming Notes: The programming standards roughly follow those 
    established by the 1997-1999 Jet Propulsion Laboratory Deep Space Network
    Planning and Preparation Subsystem project for C++ programming.

*******************************************************************************/

#ifndef SDI_APP_H
#define SDI_APP_H

/*============================================================================*/
    class 
CApp : public CWinApp                                                       /*

    This application's app class, a pattern for developing new apps.
*-----------------------------------------------------------------------------*/
{
    public:
        CApp() {}
        ~CApp(){}

        BOOL    InitInstance(); 
        CString MakeAppDataPath(const CString& subpath) const;

    private:
        BOOL    OnIdle(LONG);

        CMainFrame  m_frame;        // the main frame object
};

/*============================================================================*/
    inline
CApp* TheApp()                                                              /*

    Global access to this application object.
*----------------------------------------------------------------------------*/
{
    return (CApp*)GetApp();
}
/*-----------------------------------------------------------------------------*/
#endif // define SDI_APP_H

