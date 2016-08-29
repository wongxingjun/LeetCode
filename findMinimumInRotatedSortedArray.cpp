class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        for(int i=0; i<nums.size(); i++)
            if(nums[i]<min)
                min=nums[i];
        return min;
    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[l]<nums[r])
                return nums[l];
            int m=l+(r-l)/2;
            if(nums[m]>=nums[l])
                l=m+1;
            else
                r=m;
        }
        return nums[l];
    }
};
