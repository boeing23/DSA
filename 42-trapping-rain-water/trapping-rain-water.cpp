class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax=height[0];
       

        int l=0;
        int r=height.size()-1;
        int rightmax=height[r];
        int area=0;

        while(l<r)
        {
            if(height[l]<=height[r])
            {
                l++;
                
                
                leftmax=max(height[l],leftmax);
                area+=leftmax-height[l];
                
            }
            else
            {
                 r--;

                rightmax=max(rightmax,height[r]);
                area+=rightmax-height[r];

               
            }
        }
        return area;
    }
};