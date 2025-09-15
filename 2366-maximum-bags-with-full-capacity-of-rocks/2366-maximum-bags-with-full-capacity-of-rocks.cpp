class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int fill[50100];
        for(int i = 0; i<n; i++){
            fill[i] = capacity[i]-rocks[i];
        }
        sort(fill, fill + n);
        int ans = 0;
        int i = 0;
        while(i<n){
            additionalRocks -= fill[i];
            if(additionalRocks<0)break;
            ans++;
            i++;
        }
        return ans;


    }
};
