// This class Exposes Core C++ Features and Engine Classes:
#pragma once
#include <stdexcept>
#include <memory>


namespace dx3dEngine
{
	class Base;
	class Window;
	class Game;
	class GraphicsDevice;
	class GraphicsEngine;
	class Logger;
	class SwapChain;
	class Display;
	class DeviceContext;

	using i32 = int;
	using ui32 = unsigned int;
	using f32 = float;
	using d64 = double;

	using SwapChainPtr = std::shared_ptr<SwapChain>;
	using DeviceContextPtr = std::shared_ptr<DeviceContext>;

}