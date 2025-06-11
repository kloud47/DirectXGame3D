#pragma once
#include <DX3D/Graphics/GraphicsResource.h>


namespace dx3dEngine
{
	class DeviceContext final: public GraphicsResource 
	{
	public:
		explicit DeviceContext(const GraphicsResourceDesc& gDesc);
		void clearAndSetBackBuffer(const SwapChain& swapChain, const Vec4& color);
	private:
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_context{};

		friend class GraphicsDevice;
	};
}