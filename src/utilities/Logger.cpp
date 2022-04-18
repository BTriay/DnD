module Logger;

import <string>;
import <fstream>;
import <sstream>;
import <chrono>;

void Logger::log(const std::string& msg, LogLevel log_level)
{		
	std::stringstream msg_stream;

	switch (log_level) {
		case LogLevel::debug:
			msg_stream << "DEBUG - ";
			break;
		case LogLevel::info:
			msg_stream << "INFO - ";
			break;
		case LogLevel::warning:
			msg_stream << "WARNING - ";
			break;
		case LogLevel::error:
			msg_stream << "ERROR - ";
			break;
		case LogLevel::fatal:
			msg_stream << "FATAL - ";
			break;
	}

	msg_stream << std::chrono::system_clock::now() << " - " << msg << '\n';

	std::fstream file_handle{ m_log_filename, std::ios::app };
	file_handle << msg_stream.str();
}