class Solution {
public:
    void solve(vector<int>& nums, int s ,vector<int>& subs,vector<vector<int>>&result){

        if(s >= nums.size()){
            result.push_back(subs);
            return ;
        }

        subs.push_back(nums[s]);
        solve(nums, s + 1 ,subs,result);
        subs.pop_back();
        solve(nums, s + 1 ,subs,result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>result;
        vector<int> subs;

        solve(nums, 0,subs,result );

        return result;
    }
};
