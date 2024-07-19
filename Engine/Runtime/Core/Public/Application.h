#pragma once

#include "Core/Public/Base.h"

int main(int argc, char** argv);

namespace Denoise {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		void Close();
		static Application& Get() { return *s_Instance; }

	private:
		void Run();

	private:

		bool m_Running = true;
		bool m_Minimized = false;
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}