class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> fill(capacity.size(), -1);
        for(int i = 0; i<n; i++){
            fill[i] = capacity[i]-rocks[i];
        }
        sort(fill.begin(), fill.end());
        int ans = 0;
        int i = 0;
        while(i<n && additionalRocks>=0){
            additionalRocks -= fill[i];
            if(additionalRocks<0)break;
            ans++;
            i++;
        }
        return ans;


    }
};