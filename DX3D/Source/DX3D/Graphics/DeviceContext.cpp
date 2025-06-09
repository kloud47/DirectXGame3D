#include "DX3D/Graphics/DeviceContext.h"

dx3dEngine::DeviceContext::DeviceContext(const GraphicsResourceDesc& gDesc): GraphicsResource(gDesc)
{
	DX3DGraphicsLogErrorAndThrow(m_device.CreateDeferredContext(0, &m_context),
		"CreateDefferedContext failed.");
}
