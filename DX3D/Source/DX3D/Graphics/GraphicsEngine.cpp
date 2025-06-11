#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Graphics/GraphicsDevice.h>
#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>

dx3dEngine::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base)
{
	m_graphicsDevice = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc{m_logger});

	auto& device = *m_graphicsDevice;
	m_deviceContext = device.createDeviceContext();// Created the deffered device Context:

	DX3DLogInfo("GraphicsEngine Initialized.");
}

dx3dEngine::GraphicsEngine::~GraphicsEngine()
{
}

dx3dEngine::GraphicsDevice& dx3dEngine::GraphicsEngine::getGraphicsDevice() noexcept
{
	return *m_graphicsDevice;
}

void dx3dEngine::GraphicsEngine::render(SwapChain& swapChain)
{
	auto& context = *m_deviceContext;
	context.clearAndSetBackBuffer(swapChain, { 1,0,0,1 });

	auto& device = *m_graphicsDevice;
	device.executeCommandList(context);

	swapChain.present();
}