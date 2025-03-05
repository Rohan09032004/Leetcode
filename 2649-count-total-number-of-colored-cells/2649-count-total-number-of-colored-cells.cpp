class Solution {
public:
    long long coloredCells(long n) {
        long long int ans=2*(n-1)*(n-1)+(2*n-1);
        return ans;
    }
};