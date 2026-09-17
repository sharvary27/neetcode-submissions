class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for(int j = 0; j < n; j++){

            int diff = target - nums[j];
          
            if(mp.find(diff) != mp.end()){
               
                return {mp[diff], j};

            }

            mp[nums[j]] = j;
        }

        return {};
    }
};
