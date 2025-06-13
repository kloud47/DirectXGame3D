#pragma once
#include <DX3D/Graphics/GraphicsResource.h>


namespace dx3dEngine
{
	class DeviceContext final: public GraphicsResource 
	{
	public:
		explicit DeviceContext(const GraphicsResourceDesc& gDesc);
		void clearAndSetBackBuffer(const SwapChain& swapChain, const Vec4& color);
		void setGraphicsPipelineState(const GraphicsPipelineState& pipeline);
		void setVertexBuffer(const VertexBuffer& buffer);
		void setViewportSize(const Rect& size);
		void drawTriangleList(ui32 vertexCount, ui32 startVertexLocation);

	private:
		// D3D11DeviceContext is an interface in the Direct3D 11 API that provides methods for managing rendering operations
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_context{};

		friend class GraphicsDevice;
	};
}