class ParkingSystem {
public:
    int big1,medium1,small1;
    ParkingSystem(int big, int medium, int small) {
        big1=big;
        medium1=medium;
        small1=small;
    }
    
    bool addCar(int cartype) {
        if(cartype==1 && big1>0) {
            big1--;
            return true;
        }
        if(cartype==2 && medium1>0) {
            medium1--;
            return true;
        }
        if(cartype==3 && small1>0) {
            small1--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */