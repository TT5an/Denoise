#pragma once

#include "DEPCH.h"
#include "Core/Public/Base.h"

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Denoise {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}





// Core log macros
#define DE_CORE_TRACE(...)    ::Denoise::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DE_CORE_INFO(...)     ::Denoise::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DE_CORE_WARN(...)     ::Denoise::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DE_CORE_ERROR(...)    ::Denoise::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DE_CORE_CRITICAL(...) ::Denoise::Log::GetCoreLogger()->critical(__VA_ARGS__)
								
// Client log macros			
#define DE_TRACE(...)         ::Denoise::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DE_INFO(...)          ::Denoise::Log::GetClientLogger()->info(__VA_ARGS__)
#define DE_WARN(...)          ::Denoise::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DE_ERROR(...)         ::Denoise::Log::GetClientLogger()->error(__VA_ARGS__)
#define DE_CRITICAL(...)      ::Denoise::Log::GetClientLogger()->critical(__VA_ARGS__)