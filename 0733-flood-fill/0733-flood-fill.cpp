class Solution {
public:
    void fill(int i, int j, vector<vector<int>>& image, int& color,
              vector<vector<int>>& vis, int old) {
        vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for (auto [dx, dy] : dir) {
            if (i + dx >= 0 && i + dx < image.size() && j + dy >= 0 &&
                j + dy < image[0].size() && image[i + dx][j + dy] == old &&
                vis[i + dx][j + dy] == 0) {
                image[i + dx][j + dy] = color;
                vis[i + dx][j + dy] = 1;
                fill(i + dx, j + dy, image, color, vis, old);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> vis(image.size(), vector<int>(image[0].size(), 0));
        vector<vector<int>> ans = image;
        int oldColor = image[sr][sc];
        if (oldColor == color) return image;  // optional: avoid infinite loop

        ans[sr][sc] = color;
        vis[sr][sc] = 1;
        fill(sr, sc, ans, color, vis, oldColor);
        return ans;
    }
};
