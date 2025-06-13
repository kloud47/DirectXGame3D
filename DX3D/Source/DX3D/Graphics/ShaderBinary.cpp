#include <DX3D/Graphics/ShaderBinary.h>
#include <DX3D/Graphics/GraphicsUtils.h>
#include <d3dCompiler.h>

// This code is creating a ShaderBinary object that compiles HLSL shader source code into bytecode that can be used by DirectX.

dx3dEngine::ShaderBinary::ShaderBinary(const ShaderCompileDesc& desc, const GraphicsResourceDesc& gDesc): 
	GraphicsResource(gDesc),
	m_type(desc.shaderType)
{
	if (!desc.shaderSourceName) DX3DLogThrowInvalidArg("No shader source name provided.");
	if (!desc.shaderSourceCode) DX3DLogThrowInvalidArg("No shader source code provided.");
	if (!desc.shaderSourceCodeSize) DX3DLogThrowInvalidArg("No shader source code size provided.");
	if (!desc.shaderEntryPoint) DX3DLogThrowInvalidArg("No shader entry point provided.");


	UINT compileFlags{};

#ifdef _DEBUG
	compileFlags |= D3DCOMPILE_DEBUG;
#endif // _DEBUG

	Microsoft::WRL::ComPtr<ID3DBlob> errorMessageBlob{};
	DX3DGraphicsCheckShaderCompile(
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
			&errorMessageBlob
		),
		errorMessageBlob.Get()
	);
}

dx3dEngine::ShaderBinaryData dx3dEngine::ShaderBinary::getData() const noexcept
{
	return {
		m_blob->GetBufferPointer(),
		m_blob->GetBufferSize()
	};
}

dx3dEngine::ShaderType dx3dEngine::ShaderBinary::getType() const noexcept
{
	return m_type;
}
