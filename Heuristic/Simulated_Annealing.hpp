#pragma once
#include <cmath>
#include "Timer.hpp"
#include "Random.hpp"

// 焼きなまし法 (Simulated Annealing) の遷移制御・状態管理を司るクラス
class Simulated_Annealing {
public:
    // 温度の減衰スケジュール
    enum class Schedule { Linear, Exponential };

    // @param t_start 開始温度
    // @param t_end 終了温度
    // @param timer タイマー（コピーして保持する）
    // @param schedule 温度の減衰スケジュール（既定は線形）
    Simulated_Annealing(double t_start, double t_end, Timer timer, Schedule schedule = Schedule::Linear)
        : t_start(t_start), t_end(t_end), timer(timer), schedule(schedule) {}

    // 現在の温度を取得する
    // @return 現在の温度
    double get_temp() const {
        double progress = timer.progress();
        if (schedule == Schedule::Exponential) {
            return t_start * std::pow(t_end / t_start, progress);
        }
        return t_start + (t_end - t_start) * progress;
    }

    // 遷移を受け入れるかどうか判定する (Metropolis Criterion)
    // @param score_diff スコアの変化量 (new_score - old_score)
    // @param rnd 乱数生成器のインスタンス
    // @return 受け入れるなら true, そうでなければ false
    bool accept(double score_diff, Random& rnd) const {
        if (score_diff >= 0.0) {
            return true;
        }
        double temp = get_temp();
        if (temp <= 1e-9) return false;

        double prob = std::exp(score_diff / temp);
        return rnd.next_double() < prob;
    }

    private:
    double t_start;
    double t_end;
    Timer timer;
    Schedule schedule;
};
