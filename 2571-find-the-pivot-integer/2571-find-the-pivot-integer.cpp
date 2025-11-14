class Solution {
public:
    int pivotInteger(int n) {
        int leftsum=0;
        int rightsum=0;
        int start=1;
        int end=n;
        int mid=start+ (end-start)/2;
        while(start<=end){
            leftsum=mid*(mid-1)/2;
            rightsum=n*(n+1)/2-mid*(mid+1)/2;
            if(leftsum==rightsum){
                return mid;
            }
            else if(leftsum>rightsum){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=start+ (end-start)/2;
        }
        return -1;
    }
};