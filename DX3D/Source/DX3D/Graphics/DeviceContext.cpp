#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Graphics/GraphicsPipelineState.h>
#include <DX3D/Graphics/VertexBuffer.h>

dx3dEngine::DeviceContext::DeviceContext(const GraphicsResourceDesc& gDesc): GraphicsResource(gDesc)
{
	DX3DGraphicsLogErrorAndThrow(m_device.CreateDeferredContext(0, &m_context),
		"CreateDefferedContext failed.");
}

void dx3dEngine::DeviceContext::clearAndSetBackBuffer(const SwapChain& swapChain, const Vec4& color)
{
	f32 fColor[] = { color.x, color.y, color.z, color.w };
	auto rtv = swapChain.m_rtv.Get();
	m_context->ClearRenderTargetView(rtv, fColor); // clears a render target view to a specified color:
	m_context->OMSetRenderTargets(1, &rtv, nullptr);
}

void dx3dEngine::DeviceContext::setGraphicsPipelineState(const GraphicsPipelineState& pipeline)
{
	m_context->IASetInputLayout(pipeline.m_layout.Get());
	m_context->VSSetShader(pipeline.m_vs.Get(), nullptr, 0);
	m_context->PSSetShader(pipeline.m_ps.Get(), nullptr, 0);
}

void dx3dEngine::DeviceContext::setVertexBuffer(const VertexBuffer& buffer)
{
	//  This interface is used to bind an array of vertex buffers to the input-assembler stage
	auto stride = buffer.m_vertexSize;
	auto buf = buffer.m_buffer.Get();
	auto offset = 0u;
	m_context->IASetVertexBuffers(0, 1, &buf, &stride, &offset);
}

void dx3dEngine::DeviceContext::setViewportSize(const Rect& size)
{
	D3D11_VIEWPORT vp{};
	vp.Width = static_cast<f32>(size.width);
	vp.Height = static_cast<f32>(size.height);
	vp.MinDepth = 0.f;
	vp.MaxDepth = 1.f;
	m_context->RSSetViewports(1, &vp);
}

void dx3dEngine::DeviceContext::drawTriangleList(ui32 vertexCount, ui32 startVertexLocation)
{
	// specifying how the graphics pipeline interprets the vertex data.
	m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	m_context->Draw(vertexCount, startVertexLocation);
}
