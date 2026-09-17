class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int maxP = 0;
        int minP = prices[0];

        for(int i = 1; i < n; i++){
            
            minP = min(minP, prices[i]);
            maxP = max(maxP, prices[i] - minP);           
        }

        return maxP;
    }
};
