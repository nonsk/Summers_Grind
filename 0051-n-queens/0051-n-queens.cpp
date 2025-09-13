class Solution {
public:
    int n;
    vector<vector<string>> ans;
    vector<int> queens;
    int check(int row, int col) {
        if (row == 0)
            return 1;
        for (int i = 0; i < row; i++) {
            int pcol = queens[i];
            if (pcol == col || abs(row - i) == abs(pcol - col)) {
                return 0;
            }
        }
        return 1;
    }
    void recur(int row) {
        if(row==n){
            vector<string> temp;
            for(int i =0; i<n; i++){
                string s(n,'.');
                s[queens[i]] = 'Q';
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        for (int i = 0; i < n; i++) {
            if (check(row, i)) {
                queens[row] = i;
                recur(row + 1);
            }
        }
    }
    vector<vector<string>> solveNQueens(int N) {
        n = N;
        queens.resize(n);
        recur(0);
        return ans;
    }
};