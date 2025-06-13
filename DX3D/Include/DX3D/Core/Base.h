#pragma once
#include <DX3D/Core/Common.h>

namespace dx3dEngine 
{
	class Base
	{
	public:
		Base(const BaseDesc& desc); // Constructor Injection:
		virtual ~Base();
		virtual Logger& getLogger() noexcept final;

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

// Logger Messages:
#define DX3DLogInfo(message)\
	DX3DLog(getLogger(), Logger::LogLevel::Info, message)

#define DX3DLogWarning(message)\
	DX3DLog(getLogger(), Logger::LogLevel::Warning, message)

#define DX3DLogError(message)\
	DX3DLog(getLogger(), Logger::LogLevel::Error, message)

#define DX3DLogThrowError(message)\
	DX3DLogThrow(getLogger(), std::runtime_error, Logger::LogLevel::Error, message)

#define DX3DLogThrowInvalidArg(message)\
	DX3DLogThrow(getLogger(), std::invalid_argument, Logger::LogLevel::Error, message)