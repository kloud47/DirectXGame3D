#pragma once
#include <DX3D/Core/Common.h>

// namespace are a standard for utility classes:
namespace dx3dEngine
{
	namespace GraphicsUtils
	{
		inline const char* GetShaderModelTarget(ShaderType type)
		{
			switch (type)
			{
			case ShaderType::VertexShader: return "v5_5_0";
			case ShaderType::PixelShader: return "ps_5_0";
			default: return "";
			}
		}
	}
}