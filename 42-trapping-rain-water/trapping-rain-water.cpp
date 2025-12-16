class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int leftmax=height[0];
        int rightmax=height[r];
        int area=0;

        while(l<r)
        {

            if(height[l]<height[r])
            {
                l++;
                if(leftmax>height[l])
                {
                    area+=leftmax-height[l];
                }
                else
                {
                    leftmax=max(leftmax,height[l]);
                    
                }
                
                
            }
            else
            {
                r--;
                if(rightmax>height[r])
                {
                    area+=rightmax-height[r];
                }
                else
                {
                    rightmax=max(rightmax,height[r]);
                }
            }

        }

        return area;
        
    }
};