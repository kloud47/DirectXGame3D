#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>

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
