There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int end = 0, start = gas.size() - 1, sum = gas[start] - cost[start];
        while (end < start) {
            if (sum >= 0) {
                sum += gas[end] - cost[end];
                end++;
            }
            else {
                start--;
                sum += gas[start] - cost[start];
            }
        }
        if (sum >= 0) return start;
        else return -1;
    }
};
