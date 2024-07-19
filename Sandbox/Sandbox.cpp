#include <Core/Public/EntryPoint.h>


class Sandbox : public Denoise::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{
	}
};

Denoise::Application* Denoise::CreateApplication()
{

	return new Sandbox();
}