class UndergroundSystem {
    unordered_map<int,pair<string,int>>checkin; // stores id and {station name and time }
    unordered_map<string,pair<int,int>>routetiming;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string starttoend=checkin[id].first + '-' + stationName;
        // store route total time and count
        routetiming[starttoend]={routetiming[starttoend].first+
            (t-checkin[id].second),routetiming[starttoend].second+1};
                                 checkin.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int,int>p=routetiming[startStation+'-'+endStation];
        return (double)p.first/p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */