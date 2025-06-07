#pragma once
#include <DX3D/Core/Common.h>

namespace dx3dEngine 
{
	class Base
	{
	public:
		Base(const BaseDesc& desc); // Constructor Injection:
		virtual ~Base();
		virtual Logger& getLogger() const noexcept final;

		// The Rule of 5:
	protected:// to make the class and its derivatives non-copyable and non-movable.
		Base(const Base&) = delete;
		Base(Base&&) = delete;
		Base& operator = (const Base&) = delete;
		Base& operator = (Base&&) = delete;
	protected:
		Logger& m_logger;
	};
}
