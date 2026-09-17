class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int n = heights.size();
        int maxDiff = INT_MIN;

        int i = 0, j = n - 1;

        while(i < j){

            int w = j - i;
            int h = min(heights[i], heights[j]);

            maxDiff = max(maxDiff, w * h);

            if(heights[i] >= heights[j]){
                j--;
            }else{
                i++;
            }
        }

        return maxDiff;
    }
};
