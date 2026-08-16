class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == divisor) return 1;

        bool sign = true;
        if(dividend <= 0 && divisor > 0) sign = false;
        else if(dividend >= 0 && divisor < 0) sign = false;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long q = 0;

        while(n >= d){
            long long cnt = 0;
            while(n >= (d << (cnt+1))){
                cnt++;
            }
            q += 1LL << cnt;
            n -= (d << cnt);
        }

        if(!sign) q = -q;
        if(q > INT_MAX) return INT_MAX;
        if(q < INT_MIN) return INT_MIN;
        return (int)q;
    }
};