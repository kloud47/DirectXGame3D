#include "DX3D/Core/Base.h"

dx3dEngine::Base::Base(const BaseDesc& desc) : m_logger(desc.logger)
{
	
}

dx3dEngine::Base::~Base()
{
}

dx3dEngine::Logger& dx3dEngine::Base::getLogger() noexcept
{
	return m_logger;
}
