#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h" // 支持颜色输出
//#include "spdlog/sinks/stdout_sinks.h" // 无颜色输出
#include "spdlog/version.h"
// 基础文件输出 Basic file logger
#include "spdlog/sinks/basic_file_sink.h"
// 支持日志切换
#include "spdlog/sinks/rotating_file_sink.h"

void console_log() {
    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");

    // change log pattern
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    // Compile time log levels
    // define SPDLOG_ACTIVE_LEVEL to desired level
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");
}
//标准输出/控制台打印
void console_color_log(){
    auto console = spdlog::stdout_color_mt("console");
    auto err_logger = spdlog::stderr_color_mt("stderr");
    spdlog::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)");
}
void file_output() {
    auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
    logger->info("hell world");
}

void rotating_logger_file() {
    auto rotating_logger = spdlog::rotating_logger_mt("file_logger", "logs/rotating_file.txt", 1048576 * 5, 3);
    rotating_logger->set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %! %v");
    rotating_logger->enable_backtrace(20);
    rotating_logger->set_level(spdlog::level::trace);
    rotating_logger->debug("rotating-debug-try {} {} {}", 2024, 05, "20");
    rotating_logger->info("rotating-info-try {} {} {}", 2024, 05, "20");
}
int main()
{
    spdlog::info("Welcome to spdlog version {}.{}.{} !", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
    console_log();
    console_color_log();
    file_output();
    rotating_logger_file();

    return 0;
}