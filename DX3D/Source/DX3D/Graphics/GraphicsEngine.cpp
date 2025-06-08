#include "DX3D/Graphics/GraphicsEngine.h"
#include "DX3D/Graphics/RenderSystem.h"

dx3dEngine::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base)
{
	m_renderSystem = std::make_unique<RenderSystem>(RenderSystemDesc{m_logger});

	DX3DLogInfo("GraphicsEngine Initialized.");
}

dx3dEngine::GraphicsEngine::~GraphicsEngine()
{
}
