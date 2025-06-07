#include "DX3D/Graphics/GraphicsEngine.h"
#include "DX3D/Graphics/RenderSystem.h"

dx3dEngine::GraphicsEngine::GraphicsEngine()
{
	m_renderSystem = std::make_unique<RenderSystem>();
}

dx3dEngine::GraphicsEngine::~GraphicsEngine()
{
}
