#include <DX3D/Graphics/GraphicsEngine.h>
#include <DX3D/Graphics/GraphicsDevice.h>
#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Graphics/VertexBuffer.h>

#include <DX3D/Math/Vec3.h>

dx3dEngine::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.base)
{
	m_graphicsDevice = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc{m_logger});

	auto& device = *m_graphicsDevice;
	m_deviceContext = device.createDeviceContext();// Created the deffered device Context:

	// Creating Shaders ---------------------------
	constexpr char shaderSourceCode[] =
R"(
float4 VSMain(float3 pos: POSITION): SV_Position
{	
return float4(pos.xyz , 1.0);
}
float4 PSMain(): SV_Target
{
return float4(1.0, 1.0, 1.0, 1.0);
}
)";
	constexpr char shaderSourceName[] = "Basic";
	constexpr auto shaderSourceCodeSize = std::size(shaderSourceCode);

	auto vs = device.compileShader({ shaderSourceName, shaderSourceCode, shaderSourceCodeSize,
		"VSMain", ShaderType::VertexShader });

	auto ps = device.compileShader({ shaderSourceName, shaderSourceCode, shaderSourceCodeSize,
		"PSMain", ShaderType::PixelShader });

	m_pipeline = device.createGraphicsPipelineState({ *vs, *ps });

	const Vec3 vertexList[] = {
		{-0.5f, -0.5f, 0.0f},
		{0.0f, 0.5f, 0.0f},
		{0.5f, -0.5f, 0.0f}
	};

	m_vb = device.createVertexBuffer({vertexList, std::size(vertexList), sizeof(Vec3)});

	DX3DLogInfo("GraphicsEngine Initialized.");
}

dx3dEngine::GraphicsEngine::~GraphicsEngine()
{
}

dx3dEngine::GraphicsDevice& dx3dEngine::GraphicsEngine::getGraphicsDevice() noexcept
{
	return *m_graphicsDevice;
}

void dx3dEngine::GraphicsEngine::render(SwapChain& swapChain)// render in the game run loop:
{
	auto& context = *m_deviceContext;
	context.clearAndSetBackBuffer(swapChain, { 1,0,1,1 });
	context.setGraphicsPipelineState(*m_pipeline);

	context.setViewportSize(swapChain.getSize());
	auto& vb = *m_vb;
	context.setVertexBuffer(vb);

	context.drawTriangleList(vb.getVertexListSize(), 0u);

	auto& device = *m_graphicsDevice;
	device.executeCommandList(context);

	swapChain.present();
}