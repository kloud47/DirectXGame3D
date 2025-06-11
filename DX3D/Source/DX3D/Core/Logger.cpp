#include <DX3D/Core/Logger.h>
#include <iostream>

dx3dEngine::Logger::Logger(LogLevel logLevel) : m_logLevel(logLevel)
{
	std::clog << "Kloud47 | C++ 3D Game using directX 11" << "\n";
	std::clog << "--------------------------------------" << "\n";
}

dx3dEngine::Logger::~Logger()
{
}

void dx3dEngine::Logger::log(LogLevel level, const char* message)
{
	auto loglevelToString = [](LogLevel level) { // Lambda function to convert enum to string
		switch (level)
		{
		case LogLevel::Info: return "Info";
		case LogLevel::Warning: return "Warning";
		case LogLevel::Error: return "Error";
		default: return "Unknown";
		}
	};

	if (level > m_logLevel) return;
	std::clog << "[DX3D" << loglevelToString(level) << "]" << message << "\n";
}
