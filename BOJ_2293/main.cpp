#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, k;
vi vals;

vl dp;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> k;
	vals = vi(n);
	for (auto&& x : vals) {
		cin >> x;
	}

	dp = vl(k + 1, 0);
	dp[0] = 1;

	for (auto i = 0; i < n; ++i) {
		for (auto j = vals[i]; j <= k; ++j) {
			dp[j] += dp[j - vals[i]];
		}
	}

	cout << dp[k];

	return 0;
}