#pragma once

#include <windows.h>
#include <winternl.h>
#include "Util.h"

typedef NTSTATUS(NTAPI* func1)(HANDLE ProcessHandle, UINT ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength, PULONG ReturnLength);

BOOL checkDebugger();
BOOL checkVM();

