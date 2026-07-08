#include <chrono>
#include <algorithm>

class Timer {
    private:
    std::chrono::steady_clock::time_point start_time;
    double time_limit; // 秒単位

    public:
    Timer(double limit_sec) : time_limit(limit_sec) {
        reset();
    }

    /// @brief タイマーの経過時間を 0 にする.
    void reset() {
        start_time = std::chrono::steady_clock::now();
    }

    /// @brief 経過時間 (s) を求める.
    /// @return 経過時間 (s)
    double elapsed() const {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration<double>(now - start_time).count();
    }

    /// @brief 制限時間までのうちの進行時間の割合を 0.0 ~ 1.0 で求める
    /// @return 制限時間までのうちの進行時間の割合
    double progress() const {
        return std::min(1.0, elapsed() / time_limit);
    }

    /// @brief 終了判定
    /// @param margin_sec 終了判定に余裕を持たせるためのマージン (s)
    /// @return 終了すべきならば true.
    bool is_time_up(double margin_sec = 0.005) const {
        return elapsed() > (time_limit - margin_sec);
    }
};
