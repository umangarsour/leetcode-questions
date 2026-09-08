class Solution {
public:
    int countCommas(int n) {
        long long total = 0;
        long long lower = 1;
        int digits = 1;
        while(lower <= n){
            long long upper = min((long long)n, lower * 10 - 1);
            int commas = (digits - 1) / 3;
            long long count = upper - lower + 1;
            total += count * commas;
            lower *= 10;
            digits++;
        }
        return (int)total;
    }
};