class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> memo(group.size() + 1, vector<vector<int>>(G + 1, vector<int>(P + 1, INT_MIN)));
        return helper(group.size(), G, P, group, profit, memo);
    }
    int helper(int k, int i, int j, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>& memo) {
    	if (k == 0) return j <= 0;
    	if (j < 0) j = 0;
    	if (memo[k][i][j] != INT_MIN) return memo[k][i][j];
    	int g = group[k - 1], p = profit[k - 1], M = 1e9 + 7;
    	int res = helper(k - 1, i, j, group, profit, memo);
    	if (i >= group[k - 1]) {
    		res = (res + helper(k - 1, i - g, j - p, group, profit, memo)) % M;
    	}
    	return memo[k][i][j] = res;
    }
};
