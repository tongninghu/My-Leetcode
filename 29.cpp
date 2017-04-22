Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)  return INT_MAX;
        if (divisor == 0) return INT_MAX;
        if (dividend == 0) return 0;
        bool sign = ((dividend > 0 && divisor > 0 ) || (dividend < 0 && divisor < 0 ))? true : false;
        unsigned long long dd = abs((long long)dividend), ds = abs((long long)divisor);  // in case the pow(ds, i) exceeds the max range
        if (ds == 1) return (divisor == 1)? dividend : (0 - dividend);
        if (ds > dd) return 0;
        int i = 1, j;
        while (pow(ds, i) < dd) {
            i++;
        }
        if (pow(ds, i) == dd) j = pow(ds, i - 1);
        else {
            j = pow(ds, i - 2);
            int sum = pow(ds, i - 1);
            while (sum < dd) {
               sum += ds;
               j++;
            }
            if (sum > dd) j--;
        }
        return (sign)? j : (0 - j);
    }
};
