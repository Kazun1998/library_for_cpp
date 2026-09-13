#pragma once
#include <random>

// 競技プログラミング（マラソンマッチ）用の乱数生成クラス
class Random {
public:
    // シードを指定して初期化（デフォルトは固定値で再現性を担保）
    explicit Random(uint32_t seed = 42) : engine(seed) {}

    // [min_val, max_val] の範囲の整数をランダムに生成する（両端含む）
    // @param min_val 最小値
    // @param max_val 最大値
    // @return 生成された乱数
    int next_int(int min_val, int max_val) {
        std::uniform_int_distribution<int> dist(min_val, max_val);
        return dist(engine);
    }

    // [0.0, 1.0) の範囲の浮動小数点数をランダムに生成する
    // @return 生成された乱数
    double next_double() {
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        return dist(engine);
    }

    // [min_val, max_val) の範囲の浮動小数点数をランダムに生成する
    // @param min_val 最小値
    // @param max_val 最大値
    // @return 生成された乱数
    double next_double(double min_val, double max_val) {
        std::uniform_real_distribution<double> dist(min_val, max_val);
        return dist(engine);
    }

private:
    std::mt19937 engine;
};
