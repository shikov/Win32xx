///////////////////////////////////////
// main.cpp

#include "../DevWin++/Wincore.h"

// Note:  This application doesn't end when the window is closed
// Refer to the tutorial at http://users.bigpond.net.au/programming/tutorial.htm


INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	// Start DevWin++
	CWinApp MyApp;

	// Create a CWnd object
	CWnd MyWindow;

	// Create (and display) the window
	MyWindow.Create();

	// Run the application
	return MyApp.Run();
}


