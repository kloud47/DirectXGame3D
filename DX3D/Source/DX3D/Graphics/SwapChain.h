#pragma once
#include <DX3D/Graphics/GraphicsResource.h>

namespace dx3dEngine {
	class SwapChain final : public GraphicsResource
	{
	public:
		// SwapChainDesc pass winHandle, winSize
		SwapChain(const SwapChainDesc& desc, const GraphicsResourceDesc& gDesc);
	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain;
	};
}

