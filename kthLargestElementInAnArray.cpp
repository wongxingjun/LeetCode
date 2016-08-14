//The most silly method
class Solution {
    public:
    int findKthLargest(vector<int>& nums, int k) {
            sort(nums.begin(),nums.end());
            reverse(nums.begin(), nums.end());
            return nums[k-1];
        }
};

/*Other solutions:
    Max heap
    Set a window of k ints
*/

//max heap
class Solution {
    public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end());
        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        return pq.top();
    }
}
