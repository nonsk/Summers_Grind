class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        vector<pair<int,int>> units(n);
        for(int i =0; i<n; i++){
            units[i] = {boxTypes[i][1],i};
        }
        sort(units.begin(), units.end(), greater<pair<int,int>>());

        int ans = 0;
        int cap = 0;
        for(auto it : units){
            int index = it.second;
            if(cap + boxTypes[index][0]<=truckSize){
                cap += boxTypes[index][0];
                ans += boxTypes[index][0]*boxTypes[index][1];
            }
            else if (truckSize - cap>0){
                ans += (truckSize - cap)*boxTypes[index][1];
                cap += truckSize - cap;
            }
            else{
                break;
            }
        }
        return ans;
        
    }
};
