#include "RenderSystem.h"

dx3dEngine::RenderSystem::RenderSystem()
{
	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // _DEBUG

	auto hr = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags, NULL, 0,
		D3D11_SDK_VERSION, &m_d3dDevice,&featureLevel, &m_d3dContext);
	
	if (FAILED(hr)) throw std::runtime_error("Direct3D11 initialization failed.");
}

dx3dEngine::RenderSystem::~RenderSystem()
{
}
