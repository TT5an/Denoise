#pragma once

#include "Core/Public/Base.h"
#include "Core/Public/Log.h"
#include <filesystem>

#ifdef DE_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define DE_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { DE##type##ERROR(msg, __VA_ARGS__); DE_DEBUGBREAK(); } }
#define DE_INTERNAL_ASSERT_WITH_MSG(type, check, ...) DE_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define DE_INTERNAL_ASSERT_NO_MSG(type, check) DE_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", DE_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define DE_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define DE_INTERNAL_ASSERT_GET_MACRO(...) DE_EXPAND_MACRO( DE_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, DE_INTERNAL_ASSERT_WITH_MSG, DE_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define DE_ASSERT(...) DE_EXPAND_MACRO( DE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define DE_CORE_ASSERT(...) DE_EXPAND_MACRO( DE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define DE_ASSERT(...)
#define DE_CORE_ASSERT(...)
#endif