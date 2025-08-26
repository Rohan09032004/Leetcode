class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(e==a && c==a && (d-b)*(d-f)<0){
            return 2;
        }
        if(f==b && d==b && (c-a)*(c-e)<0){
            return 2;
        }
        if(e==a || f==b){
            return 1;
        }
        if(abs(e-c)==abs(f-d) && abs(e-a)==abs(f-b) && (a-e)*(a-c)<0 && (b-f)*(b-d)<0){
            return 2;
        }
        if(abs(e-c)==abs(f-d)){
            return 1;
        }
        else{
            return 2;
        }
    }
};