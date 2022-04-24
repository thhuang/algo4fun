class UndergroundSystem {
    unordered_map<int, tuple<string, int>> passenger_data_;
    unordered_map<string, int> station_time_sum_;
    unordered_map<string, int> station_time_count_;

    string getStationStationKey(string startStation, string endStation) {
        return startStation + ":" + endStation;
    }

   public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        if (passenger_data_.count(id)) return;
        passenger_data_.insert({id, {stationName, t}});
    }

    void checkOut(int id, string stationName, int t) {
        auto it = passenger_data_.find(id);
        if (it == passenger_data_.end()) return;
        auto [startStation, timeCheckIn] = it->second;
        string key = getStationStationKey(startStation, stationName);

        station_time_sum_[key] += t - timeCheckIn;
        ++station_time_count_[key];

        passenger_data_.erase(it);
    }

    double getAverageTime(string startStation, string endStation) {
        string key = getStationStationKey(startStation, endStation);
        return (double)station_time_sum_[key] / station_time_count_[key];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
