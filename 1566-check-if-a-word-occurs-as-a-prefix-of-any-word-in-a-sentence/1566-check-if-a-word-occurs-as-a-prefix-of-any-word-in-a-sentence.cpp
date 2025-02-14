class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=sentence.size();
        int j=0;
        int ans=1;
        for(int i=0;i<n;i++){
            while (i < n && sentence[i] == ' ') {
                i++;
            }
            while(i<n && sentence[i]==searchWord[j]){
                j++;
                i++;
                if(j==searchWord.size()){
                    return ans;
                }
            }
            while(i<n && sentence[i]!=' '){
                i++;
            }
            ans++;
            j=0;
        }
        return -1;
    }
};

