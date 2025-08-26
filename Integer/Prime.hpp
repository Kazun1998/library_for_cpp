#pragma once

namespace Prime {
  class Pseudo_Prime_Generator {
    private:
    long long prime = 1, step = 0;

    public:
    long long get() {
      if (step) {
        prime += step;
        step = 6 - step;
      }
      else if (prime == 1) { prime = 2; }
      else if (prime == 2) { prime = 3; }
      else if (prime == 3) { prime = 5, step = 2; }

      return prime;
    }
  };

  // n は素数?
  bool is_prime(long long n) {
    if (n <= 3) { return n >= 2; }
    else if (n == 5) { return true; }
    else if ((n % 2 == 0) || (n % 3 == 0) || (n % 5 == 0)) { return false; }

    Pseudo_Prime_Generator generator;
    for (long long p = generator.get(); p * p <= n; p = generator.get()) {
      if (n % p == 0) { return false; }
    }

    return true;
  }

  pair<long long, long long> exponents(long long n, long long p) {
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

    Pseudo_Prime_Generator generator;
    for (long long p =generator.get(); p * p <= n; p = generator.get()) {
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

    auto generator = Pseudo_Prime_Generator();
    for (auto p = generator.get(); p * p <= n; p = generator.get()) {
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
