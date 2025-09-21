class Spreadsheet {
public:
    unordered_map<string,int>mp;
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        mp[cell]=value;
    }
    
    void resetCell(string cell) {
        mp[cell]=0;
    }
    
    int getValue(string s) {
        s=s.substr(1);
        int a=0,b=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+'){
                string x=s.substr(0,i);
                string y=s.substr(i+1);
                a=(x[0]>='A' && x[0]<='Z') ? mp[x] : stoi(x);
                b=(y[0]>='A' && y[0]<='Z') ? mp[y] : stoi(y);
                break;
            }
        }
        return a+b;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */