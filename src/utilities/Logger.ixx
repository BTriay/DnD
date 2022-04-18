export module Logger;

import <string>;

export class Logger {
public:
    Logger(const std::string log_filename): m_log_filename(log_filename) {}

    void debug(const std::string& msg) { log(msg, LogLevel::debug); }
    void info(const std::string& msg) { log(msg, LogLevel::info); }
    void warning(const std::string& msg) { log(msg, LogLevel::warning); }
    void error(const std::string& msg) { log(msg, LogLevel::error); }
    void fatal(const std::string& msg) { log(msg, LogLevel::fatal); }

private:
    const std::string m_log_filename;

    enum class LogLevel { debug, info, warning, error, fatal};
    void log(const std::string& msg, LogLevel log_level);
};
