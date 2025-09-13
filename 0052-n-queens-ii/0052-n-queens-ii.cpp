class Solution {
public:
    int ans;
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
    void recur(int row, int &n) {
        if(row==n){
            ans++;
        }
        for (int i = 0; i < n; i++) {
            if (check(row, i)) {
                queens[row] = i;
                recur(row + 1,n);
            }
        }
    }
    int totalNQueens(int n) {
        ans = 0;
        queens.resize(n);
        recur(0,n);
        return ans;
    }
};