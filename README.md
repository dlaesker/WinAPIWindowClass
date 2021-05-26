# W32WIN Class: Encapsulating Win32 API Window Creation
After working with the C++ Win32 API, I found the process of creating just a simple window to be too cunbersome and perhaps unfriendly to beginners. Thus, I wrote a wrapper class to make the process a bit easier. Not all options are yet supported, but I am hoping to add as time allows it. 

## Compiling The Example Program
Despite the availability of various IDEs out there, I still prefer to use the Terminal, or the Window's equivalent CMD or Powershell. Thus, I am using [MinGW](http://mingw-w64.org/doku.php) to compile the code as:

[g++ Example.cpp W32WIN.cpp WindowProc.cpp -lgdi32 -lgdiplus -o W32WIN]

[g++ *.cpp -lgdi32 -lgdiplus -o W32WIN]


