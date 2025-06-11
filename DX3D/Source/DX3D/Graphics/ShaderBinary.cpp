#include <DX3D/Graphics/ShaderBinary.h>
#include <DX3D/Graphics/GraphicsUtils.h>
#include <d3dCompiler.h>

// This code is creating a ShaderBinary object that compiles HLSL shader source code into bytecode that can be used by DirectX.

dx3dEngine::ShaderBinary::ShaderBinary(const ShaderCompileDesc& desc, const GraphicsResourceDesc& gDesc): 
	GraphicsResource(gDesc)
{
	UINT compileFlags{};

#ifdef _DEBUG
	compileFlags |= D3DCOMPILE_DEBUG;
#endif // _DEBUG

	Microsoft::WRL::ComPtr<ID3DBlob> errorMessage{};
	D3DCompile(
		desc.shaderSourceCode, // The actual HLSL code as a string
		desc.shaderSourceCodeSize,
		desc.shaderSourceName,
		nullptr,
		nullptr,
		desc.shaderEntryPoint, // typically "main" or "VSMain", "PSMain", etc.
		dx3dEngine::GraphicsUtils::GetShaderModelTarget(desc.shaderType),
		compileFlags,
		0,
		&m_blob,
		&errorMessage
	);
}
