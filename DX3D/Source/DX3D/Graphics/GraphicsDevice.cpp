#include "DX3D/Graphics/GraphicsDevice.h"
#include "DX3D/Graphics/GraphicsLogUtils.h"
#include "DX3D/Graphics/SwapChain.h"
#include <DX3D/Graphics/DeviceContext.h>

dx3dEngine::GraphicsDevice::GraphicsDevice(const GraphicsDeviceDesc& desc) : Base(desc.base)
{
	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // _DEBUG
	
	DX3DGraphicsLogErrorAndThrow(D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags,
		nullptr, 0, D3D11_SDK_VERSION,
		&m_d3dDevice, &featureLevel, &m_d3dContext), 
		"Direct3D11 initialization failed.");

	// -------- DXGI Interface Chain Retrieval for advanced operations -------------------------------------------
	DX3DGraphicsLogErrorAndThrow(m_d3dDevice->QueryInterface(IID_PPV_ARGS(&m_dxgiDevice)), 
		"QueryInterface failed to retrieve IDXGIDevice.");

	DX3DGraphicsLogErrorAndThrow(m_dxgiDevice->GetParent(IID_PPV_ARGS(&m_dxgiAdapter)),
		"GetParent failed to retrieve IDXGIAdapter.");

	DX3DGraphicsLogErrorAndThrow(m_dxgiAdapter->GetParent(IID_PPV_ARGS(&m_dxgiFactory)),
		"GetParent failed to retrieve IDXGIFactory.");
}

dx3dEngine::GraphicsDevice::~GraphicsDevice()
{
}

dx3dEngine::SwapChainPtr dx3dEngine::GraphicsDevice::createSwapChain(const SwapChainDesc& desc) const
{
	return std::make_shared<SwapChain>(desc, getGraphicsResourseDesc());
}

dx3dEngine::DeviceContextPtr dx3dEngine::GraphicsDevice::createDeviceContext()
{
	return std::make_shared<DeviceContext>(getGraphicsResourseDesc());
}

void dx3dEngine::GraphicsDevice::executeCommandList(DeviceContext& context)
{
	Microsoft::WRL::ComPtr<ID3D11CommandList> list{};
	DX3DGraphicsLogErrorAndThrow(context.m_context->FinishCommandList(false, &list),
		"FinishedCommandList failed.");
	m_d3dContext->ExecuteCommandList(list.Get(), false);
}

dx3dEngine::GraphicsResourceDesc dx3dEngine::GraphicsDevice::getGraphicsResourseDesc() const noexcept
{
	return GraphicsResourceDesc({m_logger}, shared_from_this(), *m_d3dDevice.Get(), *m_dxgiFactory.Get()); // .Get() returns pointer to Microsoft::WRL
}
