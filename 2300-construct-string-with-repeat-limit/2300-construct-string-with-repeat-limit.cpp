class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n=s.size();
        vector<int>a(26,0);
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
        }
        priority_queue<pair<char,int>>pq;
        for(int i=0;i<26;i++){
            if(a[i]>0){
                char ch=i+'a';
                pq.push({ch,a[i]});
            }
        }
        string ans;
        while(!pq.empty()){
            char ch=pq.top().first;
            int cnt=pq.top().second;
            pq.pop();
            ans.append(min(repeatLimit,cnt),ch);
            if(pq.empty()){
                break;
            }
            if(cnt>repeatLimit){
                if(!pq.empty()){
            char nextch=pq.top().first;
            int nextcnt=pq.top().second;
            pq.pop();
            ans.append(1,nextch);
            if(nextcnt>=2){
                pq.push({nextch,nextcnt-1});
            }
            }
                pq.push({ch,cnt-repeatLimit});
            }
        }
        return ans;
    }
};