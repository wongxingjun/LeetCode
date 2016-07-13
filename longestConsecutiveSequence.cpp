class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int maxlen=1;
        vector<int> tmp;
        int i=0;
        while(i<n-1)
        {
            if(tmp.size()==0)
                tmp.push_back(nums[i]);
            if(nums[i]+1==nums[i+1])
            {
                tmp.push_back(nums[i+1]);
                i++;
            }
            else if(nums[i]==nums[i+1])
            {
                tmp.pop_back();
                tmp.push_back(nums[i+1]);
                i++;
            }
            else
            {
                i++;
                int len = tmp.size();
                maxlen=len>maxlen?len:maxlen;
                tmp.erase(tmp.begin(),tmp.end());
            }
        }
        int len = tmp.size();
        maxlen=len>maxlen?len:maxlen;
        tmp.erase(tmp.begin(),tmp.end());
        return maxlen;
    }
};