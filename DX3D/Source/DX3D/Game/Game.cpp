#include <DX3D/Game/Game.h>
#include <DX3D/Window/Window.h>
#include <DX3D/Core/Logger.h>
#include <DX3D/Graphics/GraphicsEngine.h>

dx3dEngine::Game::Game(const GameDesc& desc) :
	// calling the base class constructor with a unique pointer to Logger
	Base({ *std::make_unique<Logger>(desc.logLevel).release()}),// Understand This more -----------------------------------------
	m_loggerPtr(&m_logger)
{
	m_graphicsEngine = std::make_unique<GraphicsEngine>(GraphicsEngineDesc{m_logger});
	m_display = std::make_unique<Window>(WindowDesc{m_logger});

	DX3DLogInfo("Game initialized.");
}

dx3dEngine::Game::~Game()
{
	DX3DLogInfo("Game deallocation started.");
}