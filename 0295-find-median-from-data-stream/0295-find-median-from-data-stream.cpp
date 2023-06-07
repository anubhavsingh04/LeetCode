class MedianFinder {
public:
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxi.empty()||maxi.top()>num){
            maxi.push(num);
        }else {
            mini.push(num);
        }
        
        int n=maxi.size();
        int m=mini.size();
        if(n-m==2||n-m==-2)
        {
            if(n>m){
                mini.push(maxi.top());
                maxi.pop();
            }
            else {
                maxi.push(mini.top());
                mini.pop();
            }
        }
    }
    
    double findMedian() {
        int n=maxi.size();
        int m=mini.size();
        if((n+m)%2==0) {
            return (maxi.top()+mini.top())/2.0;
        }
        else  {
            return n>m?maxi.top():mini.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */