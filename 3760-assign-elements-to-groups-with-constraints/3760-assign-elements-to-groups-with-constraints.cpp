class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n=groups.size();
        vector<int>sieve(100001,-1);
        for(int i=0;i<elements.size();i++){
            if(sieve[elements[i]]==-1){
                for(int jk=elements[i];jk<=100000;jk+=elements[i]){
                    if(sieve[jk]==-1){
                    sieve[jk]=i;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            groups[i]=sieve[groups[i]];
        }
        return groups;
    }
};