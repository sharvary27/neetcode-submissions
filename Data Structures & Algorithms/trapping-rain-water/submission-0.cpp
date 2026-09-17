class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.empty()){
            return 0;
        }
        int n = height.size();
        int l= 0; int r= n-1;
        int total = 0;
        int leftMax = height[0]; int rightMax = height[n-1];

        while( l < r){

            if( leftMax <= rightMax ){

                l++;
                leftMax = max(leftMax,height[l]);

                if(leftMax > height[l]){

                    total += leftMax - height[l];
                }   
            }else{
                r--;
                
                rightMax = max(rightMax,height[r]);
                if(rightMax > height[r]){

                    total += rightMax - height[r];
                }
                

            }
        }
            return total;
    }
};
