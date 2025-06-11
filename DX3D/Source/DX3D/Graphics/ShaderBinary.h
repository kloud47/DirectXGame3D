#pragma once
#include "DX3D/Graphics/GraphicsResource.h"

namespace dx3dEngine
{
	class ShaderBinary final: public GraphicsResource
	{
	public:
		ShaderBinary(const ShaderCompileDesc& desc, const GraphicsResourceDesc& gDesc);
	private:
		Microsoft::WRL::ComPtr<ID3DBlob> m_blob{};
	};
}

