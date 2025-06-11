#include "DX3D/Graphics/SwapChain.h"

dx3dEngine::SwapChain::SwapChain(const SwapChainDesc& desc, const GraphicsResourceDesc& gDesc) :
	GraphicsResource(gDesc)
{
	// Swap Chain Description:
	DXGI_SWAP_CHAIN_DESC dxgiDesc{};

	// Buffer Description:
	dxgiDesc.BufferDesc.Width = std::max(1, desc.winSize.width);
	dxgiDesc.BufferDesc.Height = std::max(1, desc.winSize.height);
	// enum that represents a pixel format 32 bit with 8 bits each for red, green, blue, and alpha channels,
	// commonly used in graphics programming for unnormalized color representation.
	dxgiDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	dxgiDesc.BufferCount = 2; // Double buffering (front buffer + back buffer)
	dxgiDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	dxgiDesc.OutputWindow = static_cast<HWND>(desc.winHandle);
	dxgiDesc.SampleDesc.Count = 1;
	dxgiDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	dxgiDesc.Windowed = true;

	DX3DGraphicsLogErrorAndThrow(m_factory.CreateSwapChain(&m_device, &dxgiDesc, &m_swapChain), "CreateSwapChain failed.")

	reloadBuffer(); // to ensure that we have the render target view of the back buffer ready
}

void dx3dEngine::SwapChain::present(bool vsync)
{
	DX3DGraphicsLogErrorAndThrow(m_swapChain->Present(vsync, 0), "Present failed.");
}

void dx3dEngine::SwapChain::reloadBuffer()
{
	Microsoft::WRL::ComPtr<ID3D11Texture2D> buffer{};
	DX3DGraphicsLogErrorAndThrow(m_swapChain->GetBuffer(0, IID_PPV_ARGS(&buffer)),
		"GetBuffer Failed");

	DX3DGraphicsLogErrorAndThrow(m_device.CreateRenderTargetView(buffer.Get(), nullptr, &m_rtv),
		"CreateRenderTargetView failed.");
}	
