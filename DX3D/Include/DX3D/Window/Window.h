#pragma once
#include <DX3D/Core/Base.h>

namespace dx3dEngine
{
	class Window : public Base
	{
	public:
		Window();
	private:
		void* m_handle{};
		virtual ~Window() override;
	};
}
