#pragma once

#include "Longest_Common_Prefix.hpp"

ll Number_of_Substrings(const string &S) {
    ll n = S.length();
    auto lcp = Longest_Common_Prefix(S);
    ll lcp_sum = accumulate(lcp.begin(), lcp.end(), 0LL);
    return n * (n + 1) / 2 - lcp_sum;
}
