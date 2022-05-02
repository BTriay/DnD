export module Logger;

import <string>;

export class Logger {
public:
    static void debug(const std::string& msg) { log(msg, LogLevel::debug); }
    static void info(const std::string& msg) { log(msg, LogLevel::info); }
    static void warning(const std::string& msg) { log(msg, LogLevel::warning); }
    static void error(const std::string& msg) { log(msg, LogLevel::error); }
    static void fatal(const std::string& msg) { log(msg, LogLevel::fatal); }

private:
    static constexpr std::string m_log_filename{"dnd.log"};

    enum class LogLevel { debug, info, warning, error, fatal};
    static void log(const std::string& msg, LogLevel log_level);
};
