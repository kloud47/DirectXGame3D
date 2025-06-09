#include "DX3D/Game/Display.h"
#include <DX3D/Graphics/GraphicsDevice.h>

dx3dEngine::Display::Display(const DisplayDesc& desc): Window(desc.window)
{
	m_swapChain = desc.GraphicsDevice.createSwapChain({ m_handle, m_size });
}
