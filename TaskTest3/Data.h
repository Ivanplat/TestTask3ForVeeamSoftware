#pragma once
enum class LoggingType // Enum for better logging
{
	ERR,
	WARNING,
	OK
};

#define LERR LoggingType::ERR // Just a define for better code-looking
#define LWARN LoggingType::WARNING // Just a define for better code-looking
#define LOK LoggingType::OK // Just a define for better code-looking