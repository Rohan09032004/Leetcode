class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        int ans=0;
        int area=0;
        for(int i=0;i<n;i++){
            int dia=dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1];
            if(dia>=ans){
                ans=dia;
            }
        }
        for(int i=0;i<n;i++){
            int dia=dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1];
            if(dia==ans){
                area=max(area,dimensions[i][0]*dimensions[i][1]);
            }
        }
        return area;
    }
};