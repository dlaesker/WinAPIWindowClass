#include "WindowProc.h"
#include "W32WIN.h"

/************************
* Author: Denis Laesker *   
* ***********************
* Filename: WindowProc.cpp
* Description: I found it more practical to define the window procedure function separate from the W32WIN class. 
* This allows for the implementation of code more tailored to the specific app.
*/

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	switch(uMsg){
		case WM_DESTROY: {PostQuitMessage(0); break;}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}