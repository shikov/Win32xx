REM: A batch program to rebuild the Win32++ samples using VS2010.
REM: The contents of the log file is erased 

REM: Set the paths and environment variables
call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" x86

::Cleanup
call clean
call CleanTutorials
pushd "..\..\Networking"
call clean
popd

@echo on

REM: Change the directory to the parent
pushd ..\..
if exist "Win32++\output\VS2010\Debug" rmdir /s /q "Win32++\output\VS2010\Debug"
if exist "Win32++\output\VS2010\Release" rmdir /s /q "Win32++\output\VS2010\Release"
if exist "Win32++\output\VS2010\Tutorials" rmdir /s /q "Win32++\output\VS2010\Tutorials"


::Compile code
devenv /build Debug Browser\ProjectFiles\Browser_2010.sln               > "Win32++\output\VS2010.log"
devenv /build Release Browser\ProjectFiles\Browser_2010.sln             >>"Win32++\output\VS2010.log"
devenv /build Debug Dialog\ProjectFiles\Dialog_2010.sln                 >>"Win32++\output\VS2010.log"
devenv /build Release Dialog\ProjectFiles\Dialog_2010.sln               >>"Win32++\output\VS2010.log"
devenv /build Debug DialogBars\ProjectFiles\DialogBars_2010.sln         >>"Win32++\output\VS2010.log"
devenv /build Release DialogBars\ProjectFiles\DialogBars_2010.sln       >>"Win32++\output\VS2010.log"
devenv /build Debug DialogDemo\ProjectFiles\DialogDemo_2010.sln         >>"Win32++\output\VS2010.log"
devenv /build Release DialogDemo\ProjectFiles\DialogDemo_2010.sln       >>"Win32++\output\VS2010.log"
devenv /build Debug DialogTab\ProjectFiles\DialogTab_2010.sln           >>"Win32++\output\VS2010.log"
devenv /build Release DialogTab\ProjectFiles\DialogTab_2010.sln         >>"Win32++\output\VS2010.log"
REM devenv /build Debug DirectX\ProjectFiles\DirectX_2010.sln           >>"Win32++\output\VS2010.log"
REM devenv /build Release DirectX\ProjectFiles\DirectX_2010.sln         >>"Win32++\output\VS2010.log"
devenv /build Debug Dock\ProjectFiles\Dock_2010.sln                     >>"Win32++\output\VS2010.log"
devenv /build Release Dock\ProjectFiles\Dock_2010.sln                   >>"Win32++\output\VS2010.log"
devenv /build Debug DockContainer\ProjectFiles\DockContainer_2010.sln   >>"Win32++\output\VS2010.log"
devenv /build Release DockContainer\ProjectFiles\DockContainer_2010.sln >>"Win32++\output\VS2010.log"
devenv /build Debug DockTabbedMDI\ProjectFiles\DockTabbedMDI_2010.sln   >>"Win32++\output\VS2010.log"
devenv /build Release DockTabbedMDI\ProjectFiles\DockTabbedMDI_2010.sln >>"Win32++\output\VS2010.log"
devenv /build Debug Explorer\ProjectFiles\Explorer_2010.sln             >>"Win32++\output\VS2010.log"
devenv /build Release Explorer\ProjectFiles\Explorer_2010.sln           >>"Win32++\output\VS2010.log"
devenv /build Debug FastGDI\ProjectFiles\FastGDI_2010.sln               >>"Win32++\output\VS2010.log"
devenv /build Release FastGDI\ProjectFiles\FastGDI_2010.sln             >>"Win32++\output\VS2010.log"
devenv /build Debug FormDemo\ProjectFiles\FormDemo_2010.sln             >>"Win32++\output\VS2010.log"
devenv /build Release FormDemo\ProjectFiles\FormDemo_2010.sln           >>"Win32++\output\VS2010.log"
devenv /build Debug Frame\ProjectFiles\Frame_2010.sln                   >>"Win32++\output\VS2010.log"
devenv /build Release Frame\ProjectFiles\Frame_2010.sln                 >>"Win32++\output\VS2010.log"
devenv /build Debug MDIFrame\ProjectFiles\MDIFrame_2010.sln             >>"Win32++\output\VS2010.log"
devenv /build Release MDIFrame\ProjectFiles\MDIFrame_2010.sln           >>"Win32++\output\VS2010.log"
devenv /build Debug MDIFrameDemo\ProjectFiles\MDIDemo_2010.sln          >>"Win32++\output\VS2010.log"
devenv /build Release MDIFrameDemo\ProjectFiles\MDIDemo_2010.sln        >>"Win32++\output\VS2010.log"
devenv /build Debug MDIFrameSplitter\ProjectFiles\MDIFrameSplitter_2010.sln >>"Win32++\output\VS2010.log"
devenv /build Release MDIFrameSplitter\ProjectFiles\MDIFrameSplitter_2010.sln >>"Win32++\output\VS2010.log"
devenv /build Debug Networking\ClientDlg\Client_2010.sln                >>"Win32++\output\VS2010.log"
devenv /build Release Networking\ClientDlg\Client_2010.sln              >>"Win32++\output\VS2010.log"
devenv /build Debug Networking\ServerDlg\Server_2010.sln                >>"Win32++\output\VS2010.log"
devenv /build Release Networking\ServerDlg\Server_2010.sln              >>"Win32++\output\VS2010.log"
devenv /build Debug NotePad\ProjectFiles\Notepad_2010.sln               >>"Win32++\output\VS2010.log"
devenv /build Release NotePad\ProjectFiles\Notepad_2010.sln             >>"Win32++\output\VS2010.log"
devenv /build Debug Performance\ProjectFiles\Performance_2010.sln       >>"Win32++\output\VS2010.log"
devenv /build Release Performance\ProjectFiles\Performance_2010.sln     >>"Win32++\output\VS2010.log"
devenv /build Debug Picture\ProjectFiles\Picture_2010.sln               >>"Win32++\output\VS2010.log"
devenv /build Release Picture\ProjectFiles\Picture_2010.sln             >>"Win32++\output\VS2010.log"
devenv /build Debug PropertySheet\ProjectFiles\PropertySheet_2010.sln   >>"Win32++\output\VS2010.log"
devenv /build Release PropertySheet\ProjectFiles\PropertySheet_2010.sln >>"Win32++\output\VS2010.log"
devenv /build Debug RibbonFrame\ProjectFiles\RibbonFrame_2010.sln       >>"Win32++\output\VS2010.log"
devenv /build Release RibbonFrame\ProjectFiles\RibbonFrame_2010.sln     >>"Win32++\output\VS2010.log"
devenv /build Debug RibbonSimple\ProjectFiles\SimpleRibbon_2010.sln     >>"Win32++\output\VS2010.log"
devenv /build Release RibbonSimple\ProjectFiles\SimpleRibbon_2010.sln   >>"Win32++\output\VS2010.log"
devenv /build Debug Scribble\ProjectFiles\Scribble_2010.sln             >>"Win32++\output\VS2010.log"
devenv /build Release Scribble\ProjectFiles\Scribble_2010.sln           >>"Win32++\output\VS2010.log"
devenv /build Debug Simple\ProjectFiles\Simple_2010.sln                 >>"Win32++\output\VS2010.log"
devenv /build Release Simple\ProjectFiles\Simple_2010.sln               >>"Win32++\output\VS2010.log"
devenv /build Debug Splitter\ProjectFiles\Splitter_2010.sln             >>"Win32++\output\VS2010.log"
devenv /build Release Splitter\ProjectFiles\Splitter_2010.sln           >>"Win32++\output\VS2010.log"
devenv /build Debug TabDemo\ProjectFiles\TabDemo_2010.sln               >>"Win32++\output\VS2010.log"
devenv /build Release TabDemo\ProjectFiles\TabDemo_2010.sln             >>"Win32++\output\VS2010.log"
devenv /build Debug Themes\ProjectFiles\Themes_2010.sln                 >>"Win32++\output\VS2010.log"
devenv /build Release Themes\ProjectFiles\Themes_2010.sln               >>"Win32++\output\VS2010.log"
devenv /build Debug Threads\ProjectFiles\Threads_2010.sln               >>"Win32++\output\VS2010.log"
devenv /build Release Threads\ProjectFiles\Threads_2010.sln             >>"Win32++\output\VS2010.log"
devenv /build Debug Tray\ProjectFiles\Tray_2010.sln                     >>"Win32++\output\VS2010.log"
devenv /build Release Tray\ProjectFiles\Tray_2010.sln                   >>"Win32++\output\VS2010.log"

mkdir "Win32++\output\VS2010"
mkdir "Win32++\output\VS2010\Debug"

ECHO "Copying Debug Samples" >>"Win32++\output\VS2010.log"
copy Browser\ProjectFiles\Debug\Browser.exe                   "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy Dialog\ProjectFiles\Debug\Dialog.exe                     "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy DialogBars\ProjectFiles\Debug\DialogBars.exe             "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy DialogDemo\ProjectFiles\Debug\DialogDemo.exe             "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy DialogTab\ProjectFiles\Debug\DialogTab.exe               "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
REM copy DirectX\ProjectFiles\Debug\DirectX.exe               "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy Dock\ProjectFiles\Debug\Dock.exe                         "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy DockContainer\ProjectFiles\Debug\DockContainer.exe       "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy DockTabbedMDI\ProjectFiles\Debug\DockTabbedMDI.exe       "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy Explorer\ProjectFiles\Debug\Explorer.exe                 "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy FastGDI\ProjectFiles\Debug\FastGDI.exe                   "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy FormDemo\ProjectFiles\Debug\FormDemo.exe                 "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy Frame\ProjectFiles\Debug\Frame.exe                       "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy MDIFrame\ProjectFiles\Debug\MDIFrame.exe                 "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy MDIFrameDemo\ProjectFiles\Debug\MDIDemo.exe              "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy MDIFrameSplitter\ProjectFiles\Debug\MDIFrameSplitter.exe "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy Networking\ClientDlg\Debug\Client.exe                    "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy Networking\ServerDlg\Debug\Server.exe                    "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy NotePad\ProjectFiles\Debug\Notepad.exe                   "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy Performance\ProjectFiles\Debug\Performance.exe           "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy Picture\ProjectFiles\Debug\Picture.exe                   "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy PropertySheet\ProjectFiles\Debug\PropertySheet.exe       "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy RibbonFrame\ProjectFiles\Debug\RibbonFrame.exe           "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy RibbonSimple\ProjectFiles\Debug\SimpleRibbon.exe         "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy Scribble\ProjectFiles\Debug\Scribble.exe                 "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy Simple\ProjectFiles\Debug\Simple.exe                     "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy Splitter\ProjectFiles\Debug\Splitter.exe                 "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy TabDemo\ProjectFiles\Debug\TabDemo.exe                   "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy Themes\ProjectFiles\Debug\Themes.exe                     "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy Threads\ProjectFiles\Debug\Threads.exe                   "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"
copy Tray\ProjectFiles\Debug\Tray.exe                         "Win32++\output\VS2010\Debug"    >>"Win32++\output\VS2010.log"

mkdir "Win32++\output\VS2010\Release"

ECHO "Copying Release Samples" >>"Win32++\output\VS2010.log"
copy Browser\ProjectFiles\Release\Browser.exe                   "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy Dialog\ProjectFiles\Release\Dialog.exe                     "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy DialogBars\ProjectFiles\Release\DialogBars.exe             "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy DialogDemo\ProjectFiles\Release\DialogDemo.exe             "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy DialogTab\ProjectFiles\Release\DialogTab.exe               "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
REM copy DirectX\ProjectFiles\Release\DirectX.exe               "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy Dock\ProjectFiles\Release\Dock.exe                         "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy DockContainer\ProjectFiles\Release\DockContainer.exe       "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy DockTabbedMDI\ProjectFiles\Release\DockTabbedMDI.exe       "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy Explorer\ProjectFiles\Release\Explorer.exe                 "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy FastGDI\ProjectFiles\Release\FastGDI.exe                   "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy FormDemo\ProjectFiles\Release\FormDemo.exe                 "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy Frame\ProjectFiles\Release\Frame.exe                       "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy MDIFrame\ProjectFiles\Release\MDIFrame.exe                 "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy MDIFrameDemo\ProjectFiles\Release\MDIDemo.exe              "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy MDIFrameSplitter\ProjectFiles\Release\MDIFrameSplitter.exe "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy Networking\ClientDlg\Release\Client.exe                    "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy Networking\ServerDlg\Release\Server.exe                    "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy NotePad\ProjectFiles\Release\Notepad.exe                   "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy Performance\ProjectFiles\Release\Performance.exe           "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy Picture\ProjectFiles\Release\Picture.exe                   "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy PropertySheet\ProjectFiles\Release\PropertySheet.exe       "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy RibbonFrame\ProjectFiles\Release\RibbonFrame.exe           "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy RibbonSimple\ProjectFiles\Release\SimpleRibbon.exe         "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy Scribble\ProjectFiles\Release\Scribble.exe                 "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy Simple\ProjectFiles\Release\Simple.exe                     "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy Splitter\ProjectFiles\Release\Splitter.exe                 "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy TabDemo\ProjectFiles\Release\TabDemo.exe                   "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy Themes\ProjectFiles\Release\Themes.exe                     "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy Threads\ProjectFiles\Release\Threads.exe                   "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"
copy Tray\ProjectFiles\Release\Tray.exe                         "Win32++\output\VS2010\Release"    >>"Win32++\output\VS2010.log"


REM: Compile Tutorials
ECHO "Compliling Tutorials" >>"Win32++\output\VS2010.log"
::Compile code
devenv /build Debug Tutorials\Tutorial1\Tutorial1_2010.sln      >>"Win32++\output\VS2010.log"
devenv /build Release Tutorials\Tutorial1\Tutorial1_2010.sln    >>"Win32++\output\VS2010.log"
devenv /build Debug Tutorials\Tutorial2\Tutorial2_2010.sln      >>"Win32++\output\VS2010.log"
devenv /build Release Tutorials\Tutorial2\Tutorial2_2010.sln    >>"Win32++\output\VS2010.log"
devenv /build Debug Tutorials\Tutorial3\Tutorial3_2010.sln      >>"Win32++\output\VS2010.log"
devenv /build Release Tutorials\Tutorial3\Tutorial3_2010.sln    >>"Win32++\output\VS2010.log"
devenv /build Debug Tutorials\Tutorial4\Tutorial4_2010.sln      >>"Win32++\output\VS2010.log"
devenv /build Release Tutorials\Tutorial4\Tutorial4_2010.sln    >>"Win32++\output\VS2010.log"
devenv /build Debug Tutorials\Tutorial5\Tutorial5_2010.sln      >>"Win32++\output\VS2010.log"
devenv /build Release Tutorials\Tutorial5\Tutorial5_2010.sln    >>"Win32++\output\VS2010.log"
devenv /build Debug Tutorials\Tutorial6\Tutorial6_2010.sln      >>"Win32++\output\VS2010.log"
devenv /build Release Tutorials\Tutorial6\Tutorial6_2010.sln    >>"Win32++\output\VS2010.log"
devenv /build Debug Tutorials\Tutorial7\Tutorial7_2010.sln      >>"Win32++\output\VS2010.log"
devenv /build Release Tutorials\Tutorial7\Tutorial7_2010.sln    >>"Win32++\output\VS2010.log"
devenv /build Debug Tutorials\Tutorial8\Tutorial8_2010.sln      >>"Win32++\output\VS2010.log"
devenv /build Release Tutorials\Tutorial8\Tutorial8_2010.sln    >>"Win32++\output\VS2010.log"
devenv /build Debug Tutorials\Tutorial9\Tutorial9_2010.sln      >>"Win32++\output\VS2010.log"
devenv /build Release Tutorials\Tutorial9\Tutorial9_2010.sln    >>"Win32++\output\VS2010.log"

mkdir "Win32++\output\VS2010\Tutorials"
mkdir "Win32++\output\VS2010\Tutorials\Debug"

ECHO "Copying Debug Tutorials" >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial1\Debug\Tutorial1.exe         "Win32++\output\VS2010\Tutorials\Debug"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial2\Debug\Tutorial2.exe         "Win32++\output\VS2010\Tutorials\Debug"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial3\Debug\Tutorial3.exe         "Win32++\output\VS2010\Tutorials\Debug"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial4\Debug\Tutorial4.exe         "Win32++\output\VS2010\Tutorials\Debug"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial5\Debug\Tutorial5.exe         "Win32++\output\VS2010\Tutorials\Debug"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial6\Debug\Tutorial6.exe         "Win32++\output\VS2010\Tutorials\Debug"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial7\Debug\Tutorial7.exe         "Win32++\output\VS2010\Tutorials\Debug"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial8\Debug\Tutorial8.exe         "Win32++\output\VS2010\Tutorials\Debug"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial9\Debug\Tutorial9.exe         "Win32++\output\VS2010\Tutorials\Debug"    >>"Win32++\output\VS2010.log"

mkdir "Win32++\output\VS2010\Tutorials\Release"

ECHO "Copying Release Tutorials" >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial1\Release\Tutorial1.exe       "Win32++\output\VS2010\Tutorials\Release"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial2\Release\Tutorial2.exe       "Win32++\output\VS2010\Tutorials\Release"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial3\Release\Tutorial3.exe       "Win32++\output\VS2010\Tutorials\Release"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial4\Release\Tutorial4.exe       "Win32++\output\VS2010\Tutorials\Release"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial5\Release\Tutorial5.exe       "Win32++\output\VS2010\Tutorials\Release"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial6\Release\Tutorial6.exe       "Win32++\output\VS2010\Tutorials\Release"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial7\Release\Tutorial7.exe       "Win32++\output\VS2010\Tutorials\Release"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial8\Release\Tutorial8.exe       "Win32++\output\VS2010\Tutorials\Release"    >>"Win32++\output\VS2010.log"
copy Tutorials\Tutorial9\Release\Tutorial9.exe       "Win32++\output\VS2010\Tutorials\Release"    >>"Win32++\output\VS2010.log"

REM: Pop the directory change off the stack
popd


