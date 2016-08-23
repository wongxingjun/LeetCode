class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> res;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        int n1=nums1.size(),n2=nums2.size();
        if(n1*n2==0||k<=0)
            return res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        pq.emplace(0, 0);
        while(k-- > 0 && pq.size())
        {
            auto idx_pair = pq.top(); 
            pq.pop();
            res.emplace_back(nums1[idx_pair.first], nums2[idx_pair.second]);
            if (idx_pair.first + 1 < nums1.size())
                pq.emplace(idx_pair.first + 1, idx_pair.second);
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
                pq.emplace(idx_pair.first, idx_pair.second + 1);
        }
        return res;
    }
};
