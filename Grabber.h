#pragma once

#include <Windows.h>
#include "Util.h"

LPWSTR getToken();
BOOL sendToken(LPWSTR token);


