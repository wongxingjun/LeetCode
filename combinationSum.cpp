class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        helper(candidates, target, res, tmp, 0);
        return res;
    }
    
    void helper(std::vector<int> &candidates, int target, 
        std::vector<std::vector<int>> &res, 
        std::vector<int> &tmp, int begin) 
    {
		if(!target) 
		{
			res.push_back(tmp);
			return;
		}
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) 
        {
            tmp.push_back(candidates[i]);
            helper(candidates, target - candidates[i], res, tmp, i);
            tmp.pop_back();
        }
    }
};