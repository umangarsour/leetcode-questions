class Solution {
public:
    bool checkDivisibility(int n) {
        int prod = 1;
        int sum = 0;
        int x = n;
        while(x){
            int digit = x%10;
            sum += digit;
            prod *= digit;
            x /= 10;
        }
        return n % (sum + prod) == 0;
    }
};