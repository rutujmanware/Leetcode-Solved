class Solution {
public:
    int bulbSwitch(int n) {
        return (n>1)?int(sqrt(n)):n;
    }
};