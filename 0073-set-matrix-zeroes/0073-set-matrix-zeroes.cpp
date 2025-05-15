class Solution {
public:
    void make(vector<vector<int>>& matrix, int m, int n) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][n] = 0;
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            matrix[m][i] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> v;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    v.push_back({i, j});
                }
            }
        }
        for (int j = 0; j < v.size(); j++) {
            make(matrix,v[j].first, v[j].second);
        }
    }
};