#pragma once

#include "Core/Public/PlatformDetection.h"

#ifdef DE_PLATFORM_WINDOWS
#ifndef NOMINMAX
#define NOMINMAX
#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Core/Public/Base.h"
#include "Core/Public/Log.h"


#ifdef DE_PLATFORM_WINDOWS
#include <Windows.h>
#endif