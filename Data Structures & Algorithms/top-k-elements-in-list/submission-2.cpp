class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        unordered_map<int , int> mp;

        for(int num : nums){
            mp[num]++;
        }

        for(auto &i : mp){
            pq.push({i.second, i.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        for(int i = 0; i < k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
