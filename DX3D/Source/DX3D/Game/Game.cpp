#include <DX3D/Game/Game.h>
#include <DX3D/Window/Window.h>
#include <DX3D/Core/Logger.h>
#include <DX3D/Graphics/GraphicsEngine.h>

dx3dEngine::Game::Game():
	Base({ *std::make_unique<Logger>(Logger::LogLevel::Info).release()}),
	m_loggerPtr(&m_logger)
{
	m_graphicsEngine = std::make_unique<GraphicsEngine>();
	m_display = std::make_unique<Window>();

	m_loggerPtr->log(Logger::LogLevel::Info, "Game initialized.");
}

dx3dEngine::Game::~Game()
{
	m_loggerPtr->log(Logger::LogLevel::Info, "Game deallocation started.");
}