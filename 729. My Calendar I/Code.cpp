class MyCalendar {
    map<int,int>m;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(!(it->first>=end||it->second<=start)) return false ;
        }
        m[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */