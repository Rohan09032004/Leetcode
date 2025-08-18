class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int roya=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(j<players.size() && players[j]<=trainers[i]){
                roya++;
                j++;
            }
        }
        return roya;
    }
};