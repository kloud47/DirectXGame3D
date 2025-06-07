#pragma once
#include <DX3D/Core/Base.h>
#include <DX3D/Core/Core.h>

namespace dx3dEngine 
{
	class Game : public Base
	{
	public:
		Game();
		virtual ~Game() override;

		virtual void run() final;
	private:
		// Order Matters here: during deallocation:
		std::unique_ptr<Logger> m_loggerPtr{};
		std::unique_ptr<GraphicsEngine> m_graphicsEngine{};
		std::unique_ptr<Window> m_display{};
		bool m_isRunning{ true };
	};
}
