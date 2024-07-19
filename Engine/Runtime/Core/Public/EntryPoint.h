#pragma once
#include "Runtime/Core/Public/Base.h"
#include "Runtime/Core/Public/Application.h"

#ifdef DE_PLATFORM_WINDOWS

extern Denoise::Application* Denoise::CreateApplication();

int main(int argc, char** argv)
{
	Denoise::Log::Init();

	auto app = Denoise::CreateApplication();

	app->Run();

	delete app;
}

#endif