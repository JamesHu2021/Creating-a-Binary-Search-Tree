#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <mutex>

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

class Logger {
private:
    LogLevel minLogLevel;
    std::ostream& output;
    std::mutex mutex;

    std::string getTimestamp() const {
        std::time_t t = std::time(nullptr);
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&t));
        return std::string(buffer);
    }

public:
    Logger(LogLevel minLevel = LogLevel::INFO, std::ostream& output = std::cout)
        : minLogLevel(minLevel), output(output) {}

    template <typename T>
    void log(LogLevel level, const T& message) {
        if (level >= minLogLevel) {
            std::lock_guard<std::mutex> lock(mutex);
            output << getTimestamp() << " [" << static_cast<int>(level) << "] " << message << std::endl;
        }
    }
};


int main() {

    Logger logger(LogLevel::DEBUG);

    logger.log(LogLevel::INFO, "This is an informational message.");
    logger.log(LogLevel::WARNING, "This is a warning message.");
    logger.log(LogLevel::ERROR, "This is an error message.");

    return 0;

}
