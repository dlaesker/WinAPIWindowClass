#ifndef W32WIN_CLASS_H
#define W32WIN_CLASS_H

/************************
* Author: Denis Laesker *	
* ***********************
* Filename: W32WIN.h
* Description: The W32WIN class encapsulates the Win32 API window creation functionality into a less cunbersome process. Not all options provided by the * Win32 API are currently supported. 
*
* For those interested in learning more about the Win32 API -> https://docs.microsoft.com/en-us/windows/win32/learnwin32/learn-to-program-for-windows
*/

#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

#include <vector>
#include <gdiplus.h>
#include <fstream>
#include <iomanip>

class W32WIN {
protected:
	HINSTANCE 	hInstance;
	HINSTANCE 	hPrevInstance;
	LPSTR 		lpCmdLine;
	int 		nShowCmd;

	HWND 		mWin;
	WNDCLASS 	wc;
	ATOM 		winClassInfo;

	int wWidth;
	int wHeight;

	ULONG_PTR m_gdiplusToken; // To handle drawing. 
	Gdiplus::GdiplusStartupInput gdiPlusStartUpInput;

public:
	W32WIN(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

	void wCreateWindow(
		DWORD   			dwExStyle,
	  	LPCSTR    			lpClassName,
	  	LPCSTR    			lpWindowName,
	  	DWORD     			dwStyle,
	  	int       			X,
	  	int       			Y,
	  	int       			wWidth,
	  	int       			wHeight,
	  	WNDPROC				wProc
	);

	~W32WIN();
	void wShowWindow();
	int wIsOpen();
};

#endif