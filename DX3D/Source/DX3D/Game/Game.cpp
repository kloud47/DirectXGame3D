#include <DX3D/Game/Game.h>
#include <DX3D/Window/Window.h>

dx3dEngine::Game::Game()
{
	m_display = new Window();
}

dx3dEngine::Game::~Game()
{
	delete m_display;
}