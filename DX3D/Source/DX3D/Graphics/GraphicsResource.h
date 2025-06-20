#pragma once
#include <DX3D/Core/Base.h>
#include <DX3D/Graphics/GraphicsLogUtils.h>

#include <d3d11.h>
#include <wrl.h>

namespace dx3dEngine
{
	struct GraphicsResourceDesc 
	{
		BaseDesc base;
		std::shared_ptr<const GraphicsDevice> GraphicsDevice;
		ID3D11Device& device;
		IDXGIFactory& factory;
	};

	class GraphicsResource : public Base
	{
	public:
		explicit GraphicsResource(const GraphicsResourceDesc& desc) : 
			Base(desc.base),
			m_GraphicsDevice(desc.GraphicsDevice),
			m_device(desc.device),
			m_factory(desc.factory) {}
	protected:
		std::shared_ptr<const GraphicsDevice> m_GraphicsDevice;
		ID3D11Device& m_device;
		IDXGIFactory& m_factory;
	};
}
