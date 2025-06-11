#include "DX3D/Game/Display.h"
#include <DX3D/Graphics/GraphicsDevice.h>

dx3dEngine::Display::Display(const DisplayDesc& desc): Window(desc.window)
{
	m_swapChain = desc.GraphicsDevice.createSwapChain({ m_handle, m_size });

	m_logger.log(Logger::LogLevel::Info, "Game Display Initialized.");
}

dx3dEngine::SwapChain& dx3dEngine::Display::getSwapChain() noexcept
{
	return *m_swapChain;
}
