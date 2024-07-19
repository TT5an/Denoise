#pragma once

#include <memory>

#include "Core/Public/PlatformDetection.h"


#ifdef DE_DEBUG
#if defined(DE_PLATFORM_WINDOWS)
#define DE_DEBUGBREAK() __debugbreak()
#elif defined(DE_PLATFORM_LINUX)
#include <signal.h>
#define DE_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define DE_ENABLE_ASSERTS
#else
#define DE_DEBUGBREAK()
#endif

#define DE_EXPAND_MACRO(x) x
#define DE_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define DE_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Denoise {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Core/Public/Log.h"
