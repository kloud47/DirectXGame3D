#pragma once
#include <DX3D/Core/Core.h>
#include <DX3D/Core/Logger.h>
#include <DX3D/Math/Rect.h>
#include <DX3D/Math/Vec4.h>

// Used to define the structure of various descriptors used in the engine.
// These are used for dpendency injection and configuration of different components in the DX3D engine.
namespace dx3dEngine
{
	struct BaseDesc {
		Logger& logger;
	};

	struct WindowDesc {
		BaseDesc base;
		Rect size{};
	};

	struct DisplayDesc {
		WindowDesc window;
		GraphicsDevice& GraphicsDevice;
	};

	struct GraphicsEngineDesc {
		BaseDesc base;
	};

	struct GraphicsDeviceDesc {
		BaseDesc base;
	};

	struct SwapChainDesc {
		void* winHandle{};
		Rect winSize{};
	};

	enum class ShaderType
	{
		VertexShader = 0,
		PixelShader
	};

	struct ShaderCompileDesc
	{
		const char* shaderSourceName{};
		const void* shaderSourceCode{};
		size_t shaderSourceCodeSize{};
		const char* shaderEntryPoint{};
		ShaderType shaderType{};
	};


	struct GameDesc {
		Rect WindowSize{ 1280, 720 };
		Logger::LogLevel logLevel = Logger::LogLevel::Error;
	};
}