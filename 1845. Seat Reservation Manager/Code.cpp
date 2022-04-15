class SeatManager {
public:
    priority_queue<int ,vector<int>,greater<int>>pq;
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
            pq.push(i);
    }
    
    int reserve() {
        int curr=pq.top();
        pq.pop();
        return curr;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

// USING SET
// class SeatManager {
// public:
//     set<int>s;
//     SeatManager(int n) {
//         for(int i=1;i<=n;i++)
//             //inserting at the end to reduce time complexity
//             s.insert(s.end(),i);
//     }
    
//     int reserve() {
//         int curr=*s.begin();
//         s.erase(s.begin());
//         return curr;
//     }
    
//     void unreserve(int seatNumber) {
//         s.insert(seatNumber);
//     }
// };

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */