class Solution {
public:
//2,147,483,647 to 2,147,483,647
    int reverse(int x) {
        vector<int> arr;
        int ans = 0;
        while (x != 0) {
            arr.push_back(x % 10);
            x /= 10;
        }
        for (int i = 0; i < arr.size(); i++) {
            if(ans>INT_MAX/10 || ans<INT_MIN/10){
                return 0;
            }
            ans *= 10;
            ans += arr[i];
            cout << ans << " ";
        }
        return ans;
    }
};