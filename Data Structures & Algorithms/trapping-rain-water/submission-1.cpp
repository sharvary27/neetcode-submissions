class Solution {
public:
    int trap(vector<int>& height) {
        
        int l = 0; int n = height.size(); int r = n -1;
        int maxAmt = 0;
        int leftMax = height[0];
        int rightMax = height[n-1];

        while(l<r){

            if(height[l] <= height[r]){

                l++;
                leftMax = max(leftMax, height[l]);
                maxAmt += leftMax - height[l];
            }else{

                r--;
                rightMax = max(rightMax, height[r]);
                maxAmt += rightMax - height[r];
            }
        }

        return maxAmt;
    }
};
