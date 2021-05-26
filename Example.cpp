#include "W32WIN.h"
#include "WindowProc.h"

/************************
* Author: Denis Laesker *	
* ***********************
* Filename: Example.cpp
* Description: Simple example illustrating how to use the W32WIN class to create a blank window. 
* Compiled using MinGw as g++ Example.cpp W32WIN.cpp WindowProc.cpp -lgdi32 -lgdiplus -o WIN
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	srand(time(NULL));

	const char* CLASS_NAME = "ExampleWindow";

	// Initiatialize W32WIN object with 
	W32WIN win(hInstance, hPrevInstance, lpCmdLine, nShowCmd);

	int WIN_SIZE = 256;

	/* 
	Overlapped window with no minimize nor maximize buttons.  
	For information on window-styles: https://docs.microsoft.com/en-us/windows/win32/winmsg/window-styles 	
	*/
	DWORD STYLE = WS_OVERLAPPEDWINDOW & (WS_SYSMENU & ~WS_MINIMIZEBOX & ~WS_MAXIMIZEBOX); 

	win.wCreateWindow(	
		0, 					// Extended window styles https://docs.microsoft.com/en-us/windows/win32/winmsg/extended-window-styles
		CLASS_NAME, 	
		"EXMAPLE WINDOW", 	// Name of the window.
		STYLE,				// Window style.
		0, 					// X-coordinate of the window.
		0, 					// Y-coordinate of the window.
		WIN_SIZE, 			// Window width.
		WIN_SIZE, 			// Window height.
		WindowProc			// Pointer to the window's procedure (Check out WindowProc.cpp)
	);

	win.wShowWindow();

	while(win.wIsOpen())	// Run until window is closed
		;

	return 0;
}