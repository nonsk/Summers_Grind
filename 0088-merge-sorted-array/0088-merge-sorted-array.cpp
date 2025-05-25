class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int one = 0;
        int two = 0;
        while (two < n && one < m + n) {
            if (nums1[one] > nums2[two]) {
                nums1.insert(nums1.begin() + one, nums2[two]);
                two++;
            } else {
                one++;
            }
        }
        if (two < n) {
            one = m + two;
            while (two < n) {
                nums1.insert(nums1.begin() + one, nums2[two]);
                two++;
                one++;
            }
        }
        nums1 = vector<int>(nums1.begin(),nums1.begin()+m+n);
    }
};