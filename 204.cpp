Description:

Count the number of prime numbers less than a non-negative number, n.

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> noPrime(n, false);
        int counter = 0;
        for (int i = 2; i < n; i++) {
            if (noPrime[i] == false) {
                counter++;
                for (int j = 2; j * i < n; j++) {
                    noPrime[j * i] = true;
                }
            }
        }
        return counter;
    }
};
