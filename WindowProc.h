#ifndef WIN32PROC_H
#define WIN32PROC_H

#include <windows.h>

/************************
* Author: Denis Laesker *   
* ***********************
* Filename: WindowProc.h
* Description: I found it more practical to define the window procedure function separate from the W32WIN class. 
* This allows for the implementation of code more tailored to the specific app.
*/

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif