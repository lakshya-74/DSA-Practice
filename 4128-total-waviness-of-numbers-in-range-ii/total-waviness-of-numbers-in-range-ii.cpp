class Solution {
public:
    #define ll long long
    vector<int> patterns;

    Solution() {
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 10; b++) {
                for (int c = 0; c < 10; c++) {
                    if ((b > a && b > c) || (b < a && b < c)) {
                        patterns.push_back(a * 100 + b * 10 + c);
                    }
                }
            }
        }
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }

    ll solve(ll x) {
        if (x < 100) return 0;

        ll ans = 0;

        for (int pat : patterns) {
            ans += countPattern(x, pat);
        }

        return ans;
    }

    ll countPattern(ll x, int pat) {
        ll ans = 0;
        ll p10 = 1;

        while (p10 * 100 <= x) {

            ll left = x / (p10 * 1000);
            ll cur = (x / p10) % 1000;
            ll right = x % p10;

            if (cur > pat) {
                ans += (left + 1) * p10;
            }
            else if (cur == pat) {
                ans += left * p10 + right + 1;
            }
            else {
                ans += left * p10;
            }
            if (pat < 100) {
                ans -= p10;
            }

            p10 *= 10;
        }

        return ans;
    }
};