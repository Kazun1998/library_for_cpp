#pragma once

#include"../template/template.hpp"

namespace prime {
  class Pseudo_Prime_Generator {
    public:
    struct Iterator {
      long long prime = 1, step = 0;
      long long operator*() const { return prime; }
      Iterator& operator++() {
        if (step) {
          prime += step;
          step = (step == 2) ? 4 : 2;
        }
        else if (prime == 1) { prime = 2; }
        else if (prime == 2) { prime = 3; }
        else if (prime == 3) { prime = 5, step = 2; }
        return *this;
      }
      bool operator!=(const Iterator&) const { return true; }
    };

    Iterator begin() const { return ++Iterator(); }
    Iterator end() const { return {}; }
    const Pseudo_Prime_Generator& get() const { return *this; }
  };

  // n は素数?
  bool is_prime(long long n) {
    if (n <= 3) { return n >= 2; }
    else if (n == 5) { return true; }
    else if ((n % 2 == 0) || (n % 3 == 0) || (n % 5 == 0)) { return false; }

    for (long long p : Pseudo_Prime_Generator()) {
      if (p * p > n) { break; }
      if (n % p == 0) { return false; }
    }

    return true;
  }

  pair<uint64_t, long long> exponents(uint64_t n, long long p) {
    long long e = 0;
    while (n % p == 0) { e++, n /= p; }
    return {e, n};
  }

  // 素因数分解
  vector<pair<long long, long long>> prime_factorization (long long n) {
    if (n == 0) { return { make_pair(0, 0) }; } 

    vector<pair<long long, long long>> factors;
    if (n < 0) {
      factors.emplace_back(make_pair(-1, 1));
      n = abs(n);
    }

    for (long long p : Pseudo_Prime_Generator()) {
      if (p * p > n) { break; }
      long long e;
      tie(e, n) = exponents(n, p); 
      if (e) { factors.emplace_back(make_pair(p, e)); }
    }

    if (n > 1) { factors.emplace_back(make_pair(n, 1)); }
  
    return factors;
  }

  // n 以下の素数のリストを作成する.
  vector<long long> prime_list(long long n) {
    if (n == 0 || n == 1) { return {}; }
    else if (n == 2) { return {2}; }

    if (n % 2 == 0) { n--; }

    long long m = (n + 1) / 2;

    // prime_flag[k] := (2k+1) は素数か?
    vector<bool> prime_flag(m, true);
    prime_flag[0] = false;

    // 9 以上の 3 の倍数を消す.
    for (long long x = 4; x < m; x += 3) { prime_flag[x] = false; }

    for (auto p : Pseudo_Prime_Generator()) {
      if (p * p > n) { break; }
      if (p <= 3) { continue; }

      if (!prime_flag[(p - 1) / 2]) { continue; }

      for (auto j = (p * p - 1) / 2; j < m; j += p) { prime_flag[j] = false; }
    }

    vector<long long> primes{2};

    for (long long k = 0; k < m; k++) {
      if (prime_flag[k]) { primes.emplace_back(2 * k + 1); }
    }

    return primes;
  }
}
