#pragma once
#include <DX3D/Graphics/GraphicsResource.h>

namespace dx3dEngine {
	class SwapChain final : public GraphicsResource
	{
	public:
		// SwapChainDesc pass winHandle, winSize
		SwapChain(const SwapChainDesc& desc, const GraphicsResourceDesc& gDesc);
		Rect getSize() const noexcept;
		void present(bool vsync = false);
	private:
		void reloadBuffer();
	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_rtv{};
		Rect m_size{};

		friend class DeviceContext;
	};
}

