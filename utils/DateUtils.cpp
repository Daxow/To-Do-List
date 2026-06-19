#include "DateUtils.hpp"
#include <ctime>
#include <sstream>
#include <iomanip>

std::string DateUtils::getCurrentDate() {
    time_t t = time(nullptr);
    tm local{};
#ifdef _WIN32
    localtime_s(&local, &t);
#else
    localtime_r(&t, &local);
#endif
    std::ostringstream oss;
    oss << std::put_time(&local, "%Y-%m-%d");
    return oss.str();
}
