class Solution:
    def smallestNumber(self, n: int) -> int:
        if (n&(n+1))==0:
            return n
        else:
            ans=floor(log2(n)+1)
            return (1<<ans)-1

        