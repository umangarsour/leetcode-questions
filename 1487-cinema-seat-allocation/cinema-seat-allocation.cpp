class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> rowSeats;
        for(auto& r : reservedSeats){
            rowSeats[r[0]].insert(r[1]);
        }

        long long total = (long long)(n - rowSeats.size()) * 2;

        auto isFree = [](unordered_set<int>& seats, int a, int b, int c, int d){
            return !seats.count(a) && !seats.count(b) && !seats.count(c) && !seats.count(d);
        };

        for(auto& [row, seats] : rowSeats){
            bool left = isFree(seats, 2, 3, 4, 5);
            bool right = isFree(seats, 6, 7, 8, 9);
            bool middle = isFree(seats, 4, 5, 6, 7);

            if(left && right) total += 2;
            else if(left || middle || right) total += 1;
        }

        return (int)total;
    }
};