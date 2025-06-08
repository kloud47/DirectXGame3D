#pragma once
#include <DX3D/Core/Core.h>
#include <DX3D/Core/Base.h>

namespace dx3dEngine {
	class GraphicsEngine final : public Base
	{
	public:
		GraphicsEngine(const GraphicsEngineDesc& desc);
		virtual ~GraphicsEngine() override;
	private:
		std::unique_ptr<RenderSystem> m_renderSystem{};
	};
}

