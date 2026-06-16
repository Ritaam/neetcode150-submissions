class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n  = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int lp = i + 1;
            int rp = n - 1;

            while(lp < rp) {
                int sum = nums[i] + nums[lp] + nums[rp];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[lp], nums[rp]});
                    lp++;
                    rp--;
                    while(lp < rp && nums[lp] == nums[lp - 1]) lp++;
                    while(lp < rp && nums[rp] == nums[rp + 1]) rp--;
                }else if(sum < 0) {
                    lp++;
                }else {
                    rp--;
                }
            }
        }
        return ans;
    }
};
