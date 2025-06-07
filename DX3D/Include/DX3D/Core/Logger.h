#pragma once

namespace dx3dEngine {
	class Logger final
	{
	public:
		enum class LogLevel // Types of Log messages:
		{
			Error = 0,
			Warning,
			Info
		};
		// Rule of Zero:
		explicit Logger(LogLevel logLevel = LogLevel::Error); // Default Error
		void log(LogLevel level, const char* message) const;
	private:
		LogLevel m_logLevel = LogLevel::Error;
	};
}

