class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            nums[i] = 1LL * nums[i] * nums[i];

        sort(nums.rbegin(), nums.rend());

        long long sum = 0;
        int n = nums.size();

        for (int i = 0; i < (n + 1) / 2; i++)
            sum += nums[i];

        for (int i = (n + 1) / 2; i < n; i++)
            sum -= nums[i];

        return sum;
    }
};