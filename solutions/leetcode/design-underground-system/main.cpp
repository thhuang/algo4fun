class UndergroundSystem {
    unordered_map<string, unordered_map<string, int>> sum;
    unordered_map<string, unordered_map<string, int>> count;
    unordered_map<int, pair<string, int>> customer;

   public:
    void checkIn(int id, string stationName, int t) {
        customer[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto it = customer.find(id);
        sum[it->second.first][stationName] += t - it->second.second;
        ++count[it->second.first][stationName];
        customer.erase(it);
    }

    double getAverageTime(string startStation, string endStation) {
        return (double)sum[startStation][endStation] /
               count[startStation][endStation];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
