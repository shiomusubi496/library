#pragma once

#include "../other/template.hpp"

class Timer {
private:
    std::chrono::system_clock::time_point start_time;

public:
    Timer() : start_time(std::chrono::system_clock::now()) {}
    void restart() { start_time = std::chrono::system_clock::now(); }
    // return the time in milliseconds
    double elapsed() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
                   std::chrono::system_clock::now() - start_time)
            .count();
    }
    auto get_start_time() const { return start_time; }
    auto get_now_time() const { return std::chrono::system_clock::now(); }
} timer;

/**
 * @brief Timer
 * @docs docs/random/Timer.md
 */
