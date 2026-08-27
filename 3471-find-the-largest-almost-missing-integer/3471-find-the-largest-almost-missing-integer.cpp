class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int, int> cnt;

        // Check every subarray of size k
        for (int i = 0; i + k <= n; i++) {

            unordered_set<int> st;

            // Elements present in this subarray
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // x appears in this subarray
            for (int x : st) {
                cnt[x]++;
            }
        }

        int ans = -1;

        // Find largest number appearing in exactly one subarray
        for (auto &[x, frequency] : cnt) {
            if (frequency == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};