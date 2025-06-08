#pragma once
#include <DX3D/Core/Core.h>
#include <DX3D/Core/Logger.h>
#include <DX3D/Math/Rect.h>

// Used to define the structure of various descriptors used in the engine.
// These are used for dpendency injection and configuration of different components in the DX3D engine.
namespace dx3dEngine
{
	struct BaseDesc {
		Logger& logger;
	};

	struct WindowDesc {
		BaseDesc base;
	};

	struct GraphicsEngineDesc {
		BaseDesc base;
	};

	struct RenderSystemDesc {
		BaseDesc base;
	};

	struct SwapChainDesc {
		void* winHandle{};
		Rect winSize{};
	};

	struct GameDesc {
		Logger::LogLevel logLevel = Logger::LogLevel::Error;
	};
}