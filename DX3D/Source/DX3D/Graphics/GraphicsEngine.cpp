#include "DX3D/Graphics/GraphicsEngine.h"
#include "DX3D/Graphics/RenderSystem.h"

dx3dEngine::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base)
{
	m_renderSystem = std::make_shared<RenderSystem>(RenderSystemDesc{m_logger});

	DX3DLogInfo("GraphicsEngine Initialized.");
}

dx3dEngine::GraphicsEngine::~GraphicsEngine()
{
}

dx3dEngine::RenderSystem& dx3dEngine::GraphicsEngine::getRenderSystem() const noexcept
{
	return *m_renderSystem;
}
