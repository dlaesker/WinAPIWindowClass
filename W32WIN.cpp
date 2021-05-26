#include "W32WIN.h"

/************************
* Author: Denis Laesker *   
* ***********************
* Filename: W32WIN.cpp
* Description: The W32WIN class encapsulates the Win32 API window creation functionality into a less cunbersome process. Not all options provided by the * Win32 API are currently supported. 
*
* For those interested in learning more about the Win32 API -> https://docs.microsoft.com/en-us/windows/win32/learnwin32/learn-to-program-for-windows
*/

W32WIN::W32WIN(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
	this->hInstance 		= hInstance;
	this->hPrevInstance 	= hPrevInstance;
	this->lpCmdLine			= lpCmdLine;
	this->nShowCmd			= nShowCmd;

	Gdiplus::GdiplusStartup(   // Initialize GDI
		&this->m_gdiplusToken, &this->gdiPlusStartUpInput, NULL
	);
}

W32WIN::~W32WIN(){
	Gdiplus::GdiplusShutdown(this->m_gdiplusToken);    // Release GDI
}

void W32WIN::wCreateWindow(
		DWORD   			dwExStyle,
	  	LPCSTR    			lpClassName,
	  	LPCSTR    			lpW32WINName,
	  	DWORD     			dwStyle,
	  	int       			X,
	  	int       			Y,
	  	int       			wWidth,
	  	int       			wHeight,
	  	WNDPROC				wProc){
		this->wc = {0};

	this->wc.lpfnWndProc   = wProc;
    this->wc.hInstance     = this->hInstance;
    this->wc.lpszClassName = lpClassName;

    this->winClassInfo = RegisterClassA(&this->wc);

    if(this->winClassInfo == 0){
    	printf("Registering class failed\n");
    	exit(EXIT_FAILURE);
    }

    this->wWidth 	= wWidth;
    this->wHeight 	= wHeight;

    RECT rect;
    rect.left 	= 0;
    rect.right 	= wWidth;
    rect.bottom = wHeight;
    rect.top 	= 0;

    AdjustWindowRect(&rect, dwStyle, 0);

	int w = rect.right - rect.left;
	int h = rect.bottom - rect.top;

	this->mWin = CreateWindowEx(
        dwExStyle, 				// Optional Window styles.
        lpClassName, 			// Window class
        lpW32WINName, 			// Window text
        dwStyle, 				// Window style
    	X, Y, w, h, 			// Size and position
        NULL,       			// Parent Window. Not using it at the moment.
        NULL,       			// Menu. Not using it at the moment.
        this->hInstance, 		// Instance handle
        NULL);      			// Additional application data. Not using it at the moment.

	if(this->mWin == NULL){
		printf("Creating W32WIN failed\n");
    	exit(EXIT_FAILURE);
	}
}

void W32WIN::wShowWindow(){
	ShowWindow(this->mWin, this->nShowCmd);
}

int W32WIN::wIsOpen(){
	MSG msg = { };
    int res = GetMessage(&msg, NULL, 0, 0);
    
    if(res){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return res;
}

// void W32WIN::wDraw(HDC hdc){}