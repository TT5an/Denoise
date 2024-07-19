#include "Runtime/Core/Public/Application.h"

#include <thread>

namespace Denoise {
	Application* Application::s_Instance = nullptr;

	Application::Application() 
	{

	}
	Application::~Application() 
	{

	}

	void Application::Close()
	{
		m_Running = false;
	}

	void Application::Run()
	{
		while (m_Running) {
			DE_CORE_INFO("Running");
			Sleep(1000);
			//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}
}