REM: A batch program to rebuild the Win32++ samples using VS2005 Express.
REM: The contents of the log file is erased
REM: The contents of the output\VS2005 directory will be erased

REM: Set the paths and environment variables
call "C:\Program Files (x86)\Microsoft Visual Studio 8\VC\vcvarsall.bat" x86


::Cleanup
call CleanSamples
call CleanTutorials

@echo on

REM: Change the directory to the Samples parent
pushd ..\Samples
if exist "..\output\VS2005\Debug" rmdir /s /q "..\output\VS2005\Debug"
if exist "..\output\VS2005\Release" rmdir /s /q "..\output\VS2005\Release"
if exist "..\output\VS2005\Tutorials" rmdir /s /q "..\output\VS2005\Tutorials"


::Compile code
vcbuild /rebuild Browser\ProjectFiles\Browser_2005.vcproj debug                     > "..\output\VS2005.log"
vcbuild /rebuild Browser\ProjectFiles\Browser_2005.vcproj release                   >>"..\output\VS2005.log"
vcbuild /rebuild CustomControl\ProjectFiles\CustomControl_2005.vcproj debug         >>"..\output\VS2005.log"
vcbuild /rebuild CustomControl\ProjectFiles\CustomControl_2005.vcproj release       >>"..\output\VS2005.log"
vcbuild /rebuild DateTime\ProjectFiles\DateTime_2005.vcproj debug                   >>"..\output\VS2005.log"
vcbuild /rebuild DateTime\ProjectFiles\DateTime_2005.vcproj release                 >>"..\output\VS2005.log"
vcbuild /rebuild Dialog\ProjectFiles\Dialog_2005.vcproj debug                       >>"..\output\VS2005.log"
vcbuild /rebuild Dialog\ProjectFiles\Dialog_2005.vcproj release                     >>"..\output\VS2005.log"
vcbuild /rebuild DialogBars\ProjectFiles\DialogBars_2005.vcproj debug               >>"..\output\VS2005.log"
vcbuild /rebuild DialogBars\ProjectFiles\DialogBars_2005.vcproj release             >>"..\output\VS2005.log"
vcbuild /rebuild DialogDemo\ProjectFiles\DialogDemo_2005.vcproj debug               >>"..\output\VS2005.log"
vcbuild /rebuild DialogDemo\ProjectFiles\DialogDemo_2005.vcproj release             >>"..\output\VS2005.log"
vcbuild /rebuild DialogResizing\ProjectFiles\DialogResizing_2005.vcproj debug       >>"..\output\VS2005.log"
vcbuild /rebuild DialogResizing\ProjectFiles\DialogResizing_2005.vcproj release     >>"..\output\VS2005.log"
vcbuild /rebuild DialogTab\ProjectFiles\DialogTab_2005.vcproj debug                 >>"..\output\VS2005.log"
vcbuild /rebuild DialogTab\ProjectFiles\DialogTab_2005.vcproj release               >>"..\output\VS2005.log"
vcbuild /rebuild DirectX\ProjectFiles\DirectX_2005.vcproj debug                     >>"..\output\VS2005.log"
vcbuild /rebuild DirectX\ProjectFiles\DirectX_2005.vcproj release                   >>"..\output\VS2005.log"
vcbuild /rebuild DLL\ProjectFiles\MakeDLL_2005.vcproj debug                         >>"..\output\VS2005.log"
vcbuild /rebuild DLL\ProjectFiles\MakeDLL_2005.vcproj release                       >>"..\output\VS2005.log"
vcbuild /rebuild DLL\ProjectFiles\TestDLL_2005.vcproj debug                         >>"..\output\VS2005.log"
vcbuild /rebuild DLL\ProjectFiles\TestDLL_2005.vcproj release                       >>"..\output\VS2005.log"
vcbuild /rebuild Dock\ProjectFiles\Dock_2005.vcproj debug                           >>"..\output\VS2005.log"
vcbuild /rebuild Dock\ProjectFiles\Dock_2005.vcproj release                         >>"..\output\VS2005.log"
vcbuild /rebuild DockContainer\ProjectFiles\DockContainer_2005.vcproj debug         >>"..\output\VS2005.log"
vcbuild /rebuild DockContainer\ProjectFiles\DockContainer_2005.vcproj release       >>"..\output\VS2005.log"
vcbuild /rebuild DockTabbedMDI\ProjectFiles\DockTabbedMDI_2005.vcproj debug         >>"..\output\VS2005.log"
vcbuild /rebuild DockTabbedMDI\ProjectFiles\DockTabbedMDI_2005.vcproj release       >>"..\output\VS2005.log"
vcbuild /rebuild Explorer\ProjectFiles\Explorer_2005.vcproj debug                   >>"..\output\VS2005.log"
vcbuild /rebuild Explorer\ProjectFiles\Explorer_2005.vcproj release                 >>"..\output\VS2005.log"
vcbuild /rebuild FastGDI\ProjectFiles\FastGDI_2005.vcproj debug                     >>"..\output\VS2005.log"
vcbuild /rebuild FastGDI\ProjectFiles\FastGDI_2005.vcproj release                   >>"..\output\VS2005.log"
vcbuild /rebuild FormDocView\ProjectFiles\FormDemo_2005.vcproj debug                >>"..\output\VS2005.log"
vcbuild /rebuild FormDocView\ProjectFiles\FormDemo_2005.vcproj release              >>"..\output\VS2005.log"
vcbuild /rebuild Frame\ProjectFiles\Frame_2005.vcproj debug                         >>"..\output\VS2005.log"
vcbuild /rebuild Frame\ProjectFiles\Frame_2005.vcproj release                       >>"..\output\VS2005.log"
vcbuild /rebuild GDIPlus\ProjectFiles\GDIPlus_2005.vcproj debug                     >>"..\output\VS2005.log"
vcbuild /rebuild GDIPlus\ProjectFiles\GDIPlus_2005.vcproj release                   >>"..\output\VS2005.log"
vcbuild /rebuild MDIFrame\ProjectFiles\MDIFrame_2005.vcproj debug                   >>"..\output\VS2005.log"
vcbuild /rebuild MDIFrame\ProjectFiles\MDIFrame_2005.vcproj release                 >>"..\output\VS2005.log"
vcbuild /rebuild MDIFrameDemo\ProjectFiles\MDIDemo_2005.vcproj debug                >>"..\output\VS2005.log"
vcbuild /rebuild MDIFrameDemo\ProjectFiles\MDIDemo_2005.vcproj release              >>"..\output\VS2005.log"
vcbuild /rebuild MDIFrameSplitter\ProjectFiles\MDIFrameSplitter_2005.vcproj debug   >>"..\output\VS2005.log"
vcbuild /rebuild MDIFrameSplitter\ProjectFiles\MDIFrameSplitter_2005.vcproj release >>"..\output\VS2005.log"
vcbuild /rebuild Networking\ClientDlg\Client_2005.vcproj debug                      >>"..\output\VS2005.log"
vcbuild /rebuild Networking\ClientDlg\Client_2005.vcproj release                    >>"..\output\VS2005.log"
vcbuild /rebuild Networking\ServerDlg\Server_2005.vcproj debug                      >>"..\output\VS2005.log"
vcbuild /rebuild Networking\ServerDlg\Server_2005.vcproj release                    >>"..\output\VS2005.log"
vcbuild /rebuild NotePad\ProjectFiles\Notepad_2005.vcproj debug                     >>"..\output\VS2005.log"
vcbuild /rebuild NotePad\ProjectFiles\Notepad_2005.vcproj release                   >>"..\output\VS2005.log"
vcbuild /rebuild Performance\ProjectFiles\Performance_2005.vcproj debug             >>"..\output\VS2005.log"
vcbuild /rebuild Performance\ProjectFiles\Performance_2005.vcproj release           >>"..\output\VS2005.log"
vcbuild /rebuild Picture\ProjectFiles\Picture_2005.vcproj debug                     >>"..\output\VS2005.log"
vcbuild /rebuild Picture\ProjectFiles\Picture_2005.vcproj release                   >>"..\output\VS2005.log"
vcbuild /rebuild PropertySheet\ProjectFiles\PropertySheet_2005.vcproj debug         >>"..\output\VS2005.log"
vcbuild /rebuild PropertySheet\ProjectFiles\PropertySheet_2005.vcproj release       >>"..\output\VS2005.log"
vcbuild /rebuild ReBarDemo\ProjectFiles\ReBarDemo_2005.vcproj debug                 >>"..\output\VS2005.log"
vcbuild /rebuild ReBarDemo\ProjectFiles\ReBarDemo_2005.vcproj release               >>"..\output\VS2005.log"
vcbuild /rebuild RibbonFrame\ProjectFiles\RibbonFrame_2005.vcproj debug             >>"..\output\VS2005.log"
vcbuild /rebuild RibbonFrame\ProjectFiles\RibbonFrame_2005.vcproj release           >>"..\output\VS2005.log"
vcbuild /rebuild RibbonSimple\ProjectFiles\SimpleRibbon_2005.vcproj debug           >>"..\output\VS2005.log"
vcbuild /rebuild RibbonSimple\ProjectFiles\SimpleRibbon_2005.vcproj release         >>"..\output\VS2005.log"
vcbuild /rebuild Scribble\ProjectFiles\Scribble_2005.vcproj debug                   >>"..\output\VS2005.log"
vcbuild /rebuild Scribble\ProjectFiles\Scribble_2005.vcproj release                 >>"..\output\VS2005.log"
vcbuild /rebuild Simple\ProjectFiles\Simple_2005.vcproj debug                       >>"..\output\VS2005.log"
vcbuild /rebuild Simple\ProjectFiles\Simple_2005.vcproj release                     >>"..\output\VS2005.log"
vcbuild /rebuild Splitter\ProjectFiles\Splitter_2005.vcproj debug                   >>"..\output\VS2005.log"
vcbuild /rebuild Splitter\ProjectFiles\Splitter_2005.vcproj release                 >>"..\output\VS2005.log"
vcbuild /rebuild StatusBar\ProjectFiles\StatusBar_2005.vcproj debug                 >>"..\output\VS2005.log"
vcbuild /rebuild StatusBar\ProjectFiles\StatusBar_2005.vcproj release               >>"..\output\VS2005.log"
vcbuild /rebuild TabDemo\ProjectFiles\TabDemo_2005.vcproj debug                     >>"..\output\VS2005.log"
vcbuild /rebuild TabDemo\ProjectFiles\TabDemo_2005.vcproj release                   >>"..\output\VS2005.log"
vcbuild /rebuild TaskDialog\ProjectFiles\TaskDialog_2005.vcproj debug               >>"..\output\VS2005.log"
vcbuild /rebuild TaskDialog\ProjectFiles\TaskDialog_2005.vcproj release             >>"..\output\VS2005.log"
vcbuild /rebuild Themes\ProjectFiles\Themes_2005.vcproj debug                       >>"..\output\VS2005.log"
vcbuild /rebuild Themes\ProjectFiles\Themes_2005.vcproj release                     >>"..\output\VS2005.log"
vcbuild /rebuild Threads\ProjectFiles\Threads_2005.vcproj debug                     >>"..\output\VS2005.log"
vcbuild /rebuild Threads\ProjectFiles\Threads_2005.vcproj release                   >>"..\output\VS2005.log"
vcbuild /rebuild ToolBarDemo\ProjectFiles\ToolBarDemo_2005.vcproj debug             >>"..\output\VS2005.log"
vcbuild /rebuild ToolBarDemo\ProjectFiles\ToolBarDemo_2005.vcproj release           >>"..\output\VS2005.log"
vcbuild /rebuild Tray\ProjectFiles\Tray_2005.vcproj debug                           >>"..\output\VS2005.log"
vcbuild /rebuild Tray\ProjectFiles\Tray_2005.vcproj release                         >>"..\output\VS2005.log"

mkdir "..\output\VS2005"
mkdir "..\output\VS2005\Debug"

ECHO "Copying Debug Samples" >>"..\output\VS2005.log"
copy Browser\ProjectFiles\Debug\Browser.exe                   "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy CustomControl\ProjectFiles\Debug\CustomControl.exe       "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy DateTime\ProjectFiles\Debug\DateTime.exe                 "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy Dialog\ProjectFiles\Debug\Dialog.exe                     "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy DialogBars\ProjectFiles\Debug\DialogBars.exe             "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy DialogDemo\ProjectFiles\Debug\DialogDemo.exe             "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy DialogResizing\ProjectFiles\Debug\DialogResizing.exe     "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy DialogTab\ProjectFiles\Debug\DialogTab.exe               "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy DirectX\ProjectFiles\Debug\DirectX.exe                   "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy DLL\ProjectFiles\Debug\MyDLL.dll                         "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy DLL\ProjectFiles\Debug\TestDLL.exe                       "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy Dock\ProjectFiles\Debug\Dock.exe                         "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy DockContainer\ProjectFiles\Debug\DockContainer.exe       "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy DockTabbedMDI\ProjectFiles\Debug\DockTabbedMDI.exe       "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy Explorer\ProjectFiles\Debug\Explorer.exe                 "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy FastGDI\ProjectFiles\Debug\FastGDI.exe                   "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy FormDocView\ProjectFiles\Debug\FormDemo.exe              "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy Frame\ProjectFiles\Debug\Frame.exe                       "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy GDIPlus\ProjectFiles\Debug\GDIPlus.exe                   "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy MDIFrame\ProjectFiles\Debug\MDIFrame.exe                 "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy MDIFrameDemo\ProjectFiles\Debug\MDIDemo.exe              "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy MDIFrameSplitter\ProjectFiles\Debug\MDIFrameSplitter.exe "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy Networking\ClientDlg\Debug\Client.exe                    "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy Networking\ServerDlg\Debug\Server.exe                    "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy NotePad\ProjectFiles\Debug\Notepad.exe                   "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy Performance\ProjectFiles\Debug\Performance.exe           "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy Picture\ProjectFiles\Debug\Picture.exe                   "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy PropertySheet\ProjectFiles\Debug\PropertySheet.exe       "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy ReBarDemo\ProjectFiles\Debug\ReBarDemo.exe               "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy RibbonFrame\ProjectFiles\Debug\RibbonFrame.exe           "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy RibbonSimple\ProjectFiles\Debug\SimpleRibbon.exe         "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy Scribble\ProjectFiles\Debug\Scribble.exe                 "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy Simple\ProjectFiles\Debug\Simple.exe                     "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy Splitter\ProjectFiles\Debug\Splitter.exe                 "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy StatusBar\ProjectFiles\Debug\StatusBar.exe               "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy TabDemo\ProjectFiles\Debug\TabDemo.exe                   "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy TaskDialog\ProjectFiles\Debug\TaskDialog.exe             "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy Themes\ProjectFiles\Debug\Themes.exe                     "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy Threads\ProjectFiles\Debug\Threads.exe                   "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy ToolBarDemo\ProjectFiles\Debug\ToolBarDemo.exe           "..\output\VS2005\Debug"    >>"..\output\VS2005.log"
copy Tray\ProjectFiles\Debug\Tray.exe                         "..\output\VS2005\Debug"    >>"..\output\VS2005.log"

mkdir "..\output\VS2005\Release"

ECHO "Copying Release Samples" >>"..\output\VS2005.log"
copy Browser\ProjectFiles\Release\Browser.exe                   "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy CustomControl\ProjectFiles\Release\CustomControl.exe       "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy DateTime\ProjectFiles\Release\DateTime.exe                 "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy Dialog\ProjectFiles\Release\Dialog.exe                     "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy DialogBars\ProjectFiles\Release\DialogBars.exe             "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy DialogDemo\ProjectFiles\Release\DialogDemo.exe             "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy DialogResizing\ProjectFiles\Release\DialogResizing.exe     "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy DialogTab\ProjectFiles\Release\DialogTab.exe               "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy DirectX\ProjectFiles\Release\DirectX.exe                   "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy DLL\ProjectFiles\Release\MyDLL.dll                         "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy DLL\ProjectFiles\Release\TestDLL.exe                       "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy Dock\ProjectFiles\Release\Dock.exe                         "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy DockContainer\ProjectFiles\Release\DockContainer.exe       "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy DockTabbedMDI\ProjectFiles\Release\DockTabbedMDI.exe       "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy Explorer\ProjectFiles\Release\Explorer.exe                 "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy FastGDI\ProjectFiles\Release\FastGDI.exe                   "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy FormDocView\ProjectFiles\Release\FormDemo.exe              "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy Frame\ProjectFiles\Release\Frame.exe                       "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy GDIPlus\ProjectFiles\Release\GDIPlus.exe                   "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy MDIFrame\ProjectFiles\Release\MDIFrame.exe                 "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy MDIFrameDemo\ProjectFiles\Release\MDIDemo.exe              "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy MDIFrameSplitter\ProjectFiles\Release\MDIFrameSplitter.exe "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy Networking\ClientDlg\Release\Client.exe                    "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy Networking\ServerDlg\Release\Server.exe                    "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy NotePad\ProjectFiles\Release\Notepad.exe                   "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy Performance\ProjectFiles\Release\Performance.exe           "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy Picture\ProjectFiles\Release\Picture.exe                   "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy PropertySheet\ProjectFiles\Release\PropertySheet.exe       "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy ReBarDemo\ProjectFiles\Release\ReBarDemo.exe               "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy RibbonFrame\ProjectFiles\Release\RibbonFrame.exe           "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy RibbonSimple\ProjectFiles\Release\SimpleRibbon.exe         "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy Scribble\ProjectFiles\Release\Scribble.exe                 "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy Simple\ProjectFiles\Release\Simple.exe                     "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy Splitter\ProjectFiles\Release\Splitter.exe                 "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy StatusBar\ProjectFiles\Release\StatusBar.exe               "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy TabDemo\ProjectFiles\Release\TabDemo.exe                   "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy TaskDialog\ProjectFiles\Release\TaskDialog.exe             "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy Themes\ProjectFiles\Release\Themes.exe                     "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy Threads\ProjectFiles\Release\Threads.exe                   "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy ToolBarDemo\ProjectFiles\Release\ToolBarDemo.exe           "..\output\VS2005\Release"    >>"..\output\VS2005.log"
copy Tray\ProjectFiles\Release\Tray.exe                         "..\output\VS2005\Release"    >>"..\output\VS2005.log"

REM: Change the directory to the Tutorials parent
popd
pushd ..\Tutorials

REM: Compile Tutorials
ECHO "Compiling Tutorials" >>"..\output\VS2005.log"
::Compile code
vcbuild /rebuild Tutorial1\Tutorial1_2005.vcproj debug 			>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial1\Tutorial1_2005.vcproj release		>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial2\Tutorial2_2005.vcproj debug			>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial2\Tutorial2_2005.vcproj release		>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial3\Tutorial3_2005.vcproj debug			>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial3\Tutorial3_2005.vcproj release		>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial4\Tutorial4_2005.vcproj debug			>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial4\Tutorial4_2005.vcproj release		>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial5\Tutorial5_2005.vcproj debug			>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial5\Tutorial5_2005.vcproj release		>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial6\Tutorial6_2005.vcproj debug			>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial6\Tutorial6_2005.vcproj release		>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial7\Tutorial7_2005.vcproj debug			>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial7\Tutorial7_2005.vcproj release		>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial8\Tutorial8_2005.vcproj debug			>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial8\Tutorial8_2005.vcproj release		>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial9\Tutorial9_2005.vcproj debug			>>"..\output\VS2005.log"
vcbuild /rebuild Tutorial9\Tutorial9_2005.vcproj release		>>"..\output\VS2005.log"

mkdir "..\output\VS2005\Tutorials"
mkdir "..\output\VS2005\Tutorials\Debug"

ECHO "Copying Debug Tutorials" >>"..\output\VS2005.log"
copy Tutorial1\Debug\Tutorial1.exe         "..\output\VS2005\Tutorials\Debug"    >>"..\output\VS2005.log"
copy Tutorial2\Debug\Tutorial2.exe         "..\output\VS2005\Tutorials\Debug"    >>"..\output\VS2005.log"
copy Tutorial3\Debug\Tutorial3.exe         "..\output\VS2005\Tutorials\Debug"    >>"..\output\VS2005.log"
copy Tutorial4\Debug\Tutorial4.exe         "..\output\VS2005\Tutorials\Debug"    >>"..\output\VS2005.log"
copy Tutorial5\Debug\Tutorial5.exe         "..\output\VS2005\Tutorials\Debug"    >>"..\output\VS2005.log"
copy Tutorial6\Debug\Tutorial6.exe         "..\output\VS2005\Tutorials\Debug"    >>"..\output\VS2005.log"
copy Tutorial7\Debug\Tutorial7.exe         "..\output\VS2005\Tutorials\Debug"    >>"..\output\VS2005.log"
copy Tutorial8\Debug\Tutorial8.exe         "..\output\VS2005\Tutorials\Debug"    >>"..\output\VS2005.log"
copy Tutorial9\Debug\Tutorial9.exe         "..\output\VS2005\Tutorials\Debug"    >>"..\output\VS2005.log"

mkdir "..\output\VS2005\Tutorials\Release"

ECHO "Copying Release Tutorials" >>"..\output\VS2005.log"
copy Tutorial1\Release\Tutorial1.exe       "..\output\VS2005\Tutorials\Release"    >>"..\output\VS2005.log"
copy Tutorial2\Release\Tutorial2.exe       "..\output\VS2005\Tutorials\Release"    >>"..\output\VS2005.log"
copy Tutorial3\Release\Tutorial3.exe       "..\output\VS2005\Tutorials\Release"    >>"..\output\VS2005.log"
copy Tutorial4\Release\Tutorial4.exe       "..\output\VS2005\Tutorials\Release"    >>"..\output\VS2005.log"
copy Tutorial5\Release\Tutorial5.exe       "..\output\VS2005\Tutorials\Release"    >>"..\output\VS2005.log"
copy Tutorial6\Release\Tutorial6.exe       "..\output\VS2005\Tutorials\Release"    >>"..\output\VS2005.log"
copy Tutorial7\Release\Tutorial7.exe       "..\output\VS2005\Tutorials\Release"    >>"..\output\VS2005.log"
copy Tutorial8\Release\Tutorial8.exe       "..\output\VS2005\Tutorials\Release"    >>"..\output\VS2005.log"
copy Tutorial9\Release\Tutorial9.exe       "..\output\VS2005\Tutorials\Release"    >>"..\output\VS2005.log"

REM: Pop the directory change off the stack
popd


