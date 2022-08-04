class ParkingSystem {
    array<int, 4> spots;

   public:
    ParkingSystem(int big, int medium, int small) {
        spots = {0, big, medium, small};
    }

    bool addCar(int carType) { return --spots[carType] >= 0; }
};

class ParkingSystem {
    array<int, 3> quota;

   public:
    ParkingSystem(int big, int medium, int small)
        : quota({big, medium, small}) {}

    bool addCar(int carType) {
        int& q = quota[carType - 1];
        if (q == 0) return false;
        --q;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
