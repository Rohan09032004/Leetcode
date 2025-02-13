class Solution {
public:
    string clearDigits(string s) {
        int i=0;
        while(i<s.size()){
            if(isdigit(s[i])){
                s.erase(i-1,2);
                i=i-2;
            }
            i++;
        }
        return s;
    }
};