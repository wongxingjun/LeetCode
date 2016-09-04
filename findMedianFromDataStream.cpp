class MedianFinder {
public:
    priority_queue<int> maxhp;
    priority_queue<int,vector<int>,greater<int>> minhp;
    // Adds a number into the data structure.
    void addNum(int num) {
        if((maxhp.size()+minhp.size())%2==0){
            if(maxhp.size()>0&&num<maxhp.top()){
                maxhp.push(num);
                num=maxhp.top();
                maxhp.pop();
                //minhp.push(num);
            }
            minhp.push(num);
        }
        else{
            if(minhp.size()>0&&num>minhp.top()){
                minhp.push(num);
                num=minhp.top();
                minhp.pop();
                //maxhp.push(num);
            }
            maxhp.push(num);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int size=maxhp.size()+minhp.size();
        double mid=0.0;
        if(size%2==0)
            mid=(maxhp.top()+minhp.top())/2.0;
        else
            mid=minhp.top();
        return mid;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
