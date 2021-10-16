//
// Created by Emanuel on 16.10.2021.
//

#include <string>
#include <vector>
#include <unordered_map>

class UndergroundSystem {
private:
    struct pair_hash {
        inline std::size_t operator()(const std::pair<std::string, std::string>& v) const {
            return std::hash<std::string>{}(v.first + v.second);
        }
    };

    std::unordered_map<int, std::pair<std::string, int>> pending;
    std::unordered_map<std::pair<std::string, std::string>, std::pair<double, int>, pair_hash> average;
public:
    UndergroundSystem() {
    }

    void checkIn(int id, std::string stationName, int t) {
        pending[id] = std::pair<std::string, int> {stationName, t};
    }

    void checkOut(int id, std::string stationName, int t) {
        if (pending.find(id) != pending.end()) {
            if (average.find({pending[id].first, stationName}) != average.end()) {
                double avg = average[{pending[id].first, stationName}].first;
                int cnt = average[{pending[id].first, stationName}].second;
                // std::cout << avg << ' ' << t << ' ' << pending[id].second << ' // ';
                avg = avg * cnt + t - pending[id].second;
                cnt++;
                avg /= cnt;
                average[{pending[id].first, stationName}] = {avg, cnt};
            }
            else average[{pending[id].first, stationName}] = {t - (double)pending[id].second, 1};

            // std::cout << id << ' ' << pending[id].first << ' ' << stationName << ' ' << average[{pending[id].first, stationName}].first << ' ' << average[{pending[id].first, stationName}].second << '\n';
            pending.erase(id);
        }
    }

    double getAverageTime(std::string startStation, std::string endStation) {
        return average[{startStation, endStation}].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */