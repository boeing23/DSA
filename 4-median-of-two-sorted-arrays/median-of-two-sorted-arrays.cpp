class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        int k=0;

        vector<int>m;

        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                m.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]==nums2[j])
            {
                m.push_back(nums2[j]);
                m.push_back(nums1[i]);
                i++;
                j++;
            }
            else
            {
                m.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) {
        m.push_back(nums1[i]);
        i++;
    }

    // Copy remaining elements of B (if any)
    while (j < nums2.size()) {
        m.push_back(nums2[j]);
        j++;
    }

if(m.size()%2==0)
{
    int a=m.size()/2;
    return (m[a] + m[a-1]) / 2.0;

}
else
{
    return m[m.size() / 2];

}

    
        
    }
};