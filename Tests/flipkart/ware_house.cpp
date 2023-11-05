#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxGoodsPicked(int numrows, int numcols, vector<vector<int>>& grid) {
    vector<vector<vector<bool>>> picked(numrows, vector<vector<bool>>(numcols, vector<bool>(numcols, false)));
    vector<vector<vector<int>>> dp(numrows, vector<vector<int>>(numcols, vector<int>(numcols, 0)));

    for (int i = 0; i < numrows; ++i) {
        for (int j = 0; j < numcols; ++j) {
            for (int k = 0; k < numcols; ++k) {
                if (j != k) {
                    dp[i][j][k] = grid[i][j] + grid[i][k];
                }
            }
        }
    }

    for (int i = 1; i < numrows; ++i) {
        for (int j = 0; j < numcols; ++j) {
            for (int k = 0; k < numcols; ++k) {
                if (!picked[i - 1][j][k]) {
                    int maxGoods = 0;
                    for (int prev_k = max(0, k - 1); prev_k < min(numcols, k + 2); ++prev_k) {
                        maxGoods = max(maxGoods, dp[i - 1][j][prev_k]);
                    }
                    dp[i][j][k] += maxGoods;
                }
            }
        }
    }

    int result = 0;
    for (int j = 0; j < numcols; ++j) {
        for (int k = 0; k < numcols; ++k) {
            result = max(result, dp[numrows - 1][j][k]);
        }
    }

    return result;
}

int main() {
    int numrows, numcols;
    cin >> numrows >> numcols;

    vector<vector<int>> grid(numrows, vector<int>(numcols, 0));
    for (int i = 0; i < numrows; ++i) {
        for (int j = 0; j < numcols; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = maxGoodsPicked(numrows, numcols, grid);
    cout << result << endl;

    return 0;
}
