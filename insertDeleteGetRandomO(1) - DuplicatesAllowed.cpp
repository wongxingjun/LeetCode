class RandomizedCollection {
public:
    vector<int> nums;
    map<int,vector<int>> mp;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool flag = false;
        if(mp.find(val)==mp.end())
            flag = true;
        nums.push_back(val);
        mp[val].push_back(nums.size()-1);
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;
        int pos=mp[val].back();
        mp[val].pop_back();
        if(mp[val].size()==0)
            mp.erase(val);
        nums[pos]=nums.back();
        if(mp.find(nums.back())!=mp.end())
        {
            for(int i=0;i<mp[nums.back()].size();i++)
            {
                if(mp[nums.back()][i]==nums.size()-1)
                    mp[nums.back()][i]=pos;
            }
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
