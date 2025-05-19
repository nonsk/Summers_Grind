#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dist(string s1, string s2) {
        int count = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                count++;
            }
        }
        return count;
    }

    int bfs(int start, string end, vector<string>& wordList,
            vector<vector<int>>& adj) {
        queue<int> q;
        q.push(start);
        int count = 1;
        vector<int> vis(wordList.size(), 0);
        vis[start] = 1;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int node = q.front();
                q.pop();
                if (wordList[node] == end) {
                    return count;
                }
                for (int j = 0; j < adj[node].size(); j++) {
                    int neighbor = adj[node][j];
                    if (!vis[neighbor]) {
                        q.push(neighbor);
                        vis[neighbor] = 1;
                    }
                }
            }
            count++;
        }

        return INT_MAX;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        vector<vector<int>> adj(wordList.size());
        vector<int> indices;

        for (int i = 0; i < wordList.size(); i++) {
            if (dist(wordList[i], beginWord) == 1) {
                indices.push_back(i);
            }
            for (int j = i + 1; j < wordList.size(); j++) {
                if (dist(wordList[i], wordList[j]) == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < indices.size(); i++) {
            ans = min(ans, bfs(indices[i], endWord, wordList, adj));
        }

        return (ans == INT_MAX) ? 0 : ans + 1;
    }
};
