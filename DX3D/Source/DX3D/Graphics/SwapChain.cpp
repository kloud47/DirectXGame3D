#include "SwapChain.h"

dx3dEngine::SwapChain::SwapChain(const SwapChainDesc& desc, const GraphicsResourceDesc& gDesc) :
	GraphicsResource(gDesc)
{
	DXGI_SWAP_CHAIN_DESC dxgiDesc{};

	dxgiDesc.BufferDesc.Width = std::max(1, desc.winSize.width);
	dxgiDesc.BufferDesc.Height = std::max(1, desc.winSize.height);
	// enum that represents a pixel format with 8 bits each for red, green, blue, and alpha channels,
	// commonly used in graphics programming for unnormalized color representation.
	dxgiDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

	m_factory.CreateSwapChain(&m_device, );
}
