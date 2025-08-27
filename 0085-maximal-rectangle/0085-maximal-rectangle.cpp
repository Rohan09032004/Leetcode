class Solution {
public:
int hist(vector<vector<int>>&matrix , int j){
    long long int n=matrix[j].size();
        stack<pair<long long int,long long int>>st1,st2;
        vector<long int>ansl(n,-1),ansr(n,n);
        long long int ans=0;
        for(long long int i=n-1;i>=0;i--){
            while(!st1.empty()  &&  matrix[j][i]<=st1.top().first){
                st1.pop();
            }
            if(!st1.empty()){
                ansr[i]=st1.top().second;
            }
            st1.push({matrix[j][i],i});
        }
        for(long long int i=0;i<n;i++){
            while(!st2.empty()  &&  matrix[j][i]<=st2.top().first){
                st2.pop();
            }
            if(!st2.empty()){
                ansl[i]=st2.top().second;
            }
            st2.push({matrix[j][i],i});
        }
        for(long long int i=0;i<n;i++){
            long long int currar=(matrix[j][i]*(ansr[i]-ansl[i]-1));
            ans=max(currar,ans);
        }
        return ans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>m(n,vector<int>(matrix[0].size()));
        for(int i=0;i<n;i++){
            for(int j=0;j<matrix[i].size();j++){
                m[i][j]=matrix[i][j]-'0';
                if(i>0 && m[i][j]==1){
                    m[i][j]+=m[i-1][j];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,hist(m,i));
        }
        return ans;
    }
};