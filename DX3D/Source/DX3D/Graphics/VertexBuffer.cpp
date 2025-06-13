#include "VertexBuffer.h"

dx3dEngine::VertexBuffer::VertexBuffer(const VertexBufferDesc& desc, const GraphicsResourceDesc& gDesc): 
	GraphicsResource(gDesc), m_vertexSize(desc.vertexSize), m_vertexListSize(desc.vertexListSize)
{
	if (!desc.vertexList) DX3DLogThrowInvalidArg("Vertex list not provided.");
	if (!desc.vertexListSize) DX3DLogThrowInvalidArg("Vertex list size not provided.");
	if (!desc.vertexSize) DX3DLogThrowInvalidArg("Vertex size not provided.")

	D3D11_BUFFER_DESC buffDesc{};
	buffDesc.ByteWidth = desc.vertexListSize*desc.vertexSize;
	buffDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER; // means this buffer is used as a Vertex Buffer:

	D3D11_SUBRESOURCE_DATA initData{};
	initData.pSysMem = desc.vertexList;

	DX3DGraphicsLogErrorAndThrow(m_device.CreateBuffer(&buffDesc, &initData, &m_buffer),
		"CreateBuffer failed.");
}

dx3dEngine::ui32 dx3dEngine::VertexBuffer::getVertexListSize() const noexcept
{
	return m_vertexListSize;
}
