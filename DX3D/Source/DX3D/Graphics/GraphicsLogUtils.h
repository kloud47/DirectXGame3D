#pragma once
#include <DX3D/Core/Logger.h>
#include <d3d11.h>

namespace dx3dEngine
{
	namespace GraphicsLogUtils
	{
		inline void CheckShaderCompile(Logger& logger, HRESULT hr, ID3DBlob* errorBlob)
		{
			auto errorMsg = errorBlob ? static_cast<const char*>(errorBlob->GetBufferPointer()) : nullptr;

			if (FAILED(hr))
			{
				DX3DLogThrow(logger, std::runtime_error, Logger::LogLevel::Error, errorMsg ? errorMsg :
					"Shader compilation failed.");
			}
			if (errorMsg) DX3DLog(logger, Logger::LogLevel::Warning, errorMsg);
		}
	}
}

#define DX3DGraphicsLogErrorAndThrow(hr, message) \
{\
	auto res = (hr);\
	if (FAILED(res))\
	{\
			DX3DLogThrowError(message); \
	}\
}

#define DX3DGraphicsCheckShaderCompile(hr, errorBlob)\
{\
	auto res = (hr); \
	dx3dEngine::GraphicsLogUtils::CheckShaderCompile(getLogger(), res, errorBlob); \
}