#include "RunTimeCheck.h"

BOOL checkVM() {

	WCHAR path[] = { 0x53, 0x59, 0x53, 0x54, 0x45, 0x4d, 0x5c, 0x43, 0x75, 0x72, 0x72, 0x65, 0x6e, 0x74, 0x43, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x53, 0x65, 0x74, 0x5c, 0x53, 0x65, 0x72, 0x76, 0x69, 0x63, 0x65, 0x73, 0x5c, 0x64, 0x69, 0x73, 0x6b, 0x5c, 0x45, 0x6e, 0x75, 0x6d, 0x00 };
	WCHAR vm1[] = { 0x51, 0x45, 0x4d, 0x55, 0x00 };
	WCHAR vm2[] = { 0x56, 0x4d, 0x57, 0x41, 0x52, 0x45, 0x00 };
	WCHAR vm3[] = { 0x58, 0x45, 0x4e, 0x00 };
	WCHAR vm4[] = { 0x56, 0x42, 0x4f, 0x58, 0x00 };
	WCHAR vm5[] = { 0x56, 0x49, 0x52, 0x54, 0x49, 0x4f, 0x00 };

	HKEY queryKey;
	DWORD lpData = 90 * sizeof(WCHAR);
	PERF_DATA_BLOCK perfData[90 * sizeof(WCHAR)];

	RegOpenKeyExW(HKEY_LOCAL_MACHINE, path, 0, KEY_READ, &queryKey);
	RegQueryValueExW(queryKey, L"0", 0, NULL, (LPBYTE)perfData, &lpData);
	RegCloseKey(queryKey);

	if (searchStr((LPWSTR)perfData, vm1) != NULL || searchStr((LPWSTR)perfData, vm2) != NULL || searchStr((LPWSTR)perfData, vm3) != NULL || searchStr((LPWSTR)perfData, vm4) != NULL || searchStr((LPWSTR)perfData, vm5) != NULL) {

		return TRUE;
	}
	else {
		return FALSE;
	}

}

BOOL checkDebugger() {
	HMODULE ntdll = GetModuleHandleW(L"ntdll.dll");
	if (ntdll != NULL) {
		func1 _query_information_process = (func1)GetProcAddress(ntdll, "NtQueryInformationProcess");

		DWORD debugger = 0;
		NTSTATUS status = _query_information_process(GetCurrentProcess(), 7, &debugger, sizeof(DWORD), NULL);
		if (NT_SUCCESS(status) && debugger != 0 || IsDebuggerPresent()) {
			return TRUE;
		}
	}
	return FALSE;
}
