class Solution {
public:
    string multiply(string num1, string num2) {
        vector<vector<int>> roya(num2.size());
        int zero = 0;
        for (int i = num2.size() - 1; i >= 0; i--) {
            int carry = 0;
            for (int k = 0; k < zero; k++) {
                roya[i].push_back(0);
            }

            for (int j = num1.size() - 1; j >= 0; j--) {
                int val = ((num2[i] - '0') * (num1[j] - '0') + carry) % 10;
                carry = ((num2[i] - '0') * (num1[j] - '0') + carry) / 10;
                roya[i].push_back(val);
            }

            if (carry > 0) roya[i].push_back(carry);  
            reverse(roya[i].begin(), roya[i].end());
            zero++;
        }
    int carry=0;
    string ans;
    int c=210;
    while(c){
        int val=carry;
    for(int i=0;i<num2.size();i++){
        if(roya[i].size()>0){
            val+=roya[i].back();
            roya[i].pop_back();
        }
    }
    ans+=(val%10+'0');
    carry=val/10;
    c--;
    }
      while (carry) {
            ans += (carry % 10 + '0');
            carry /= 10;
        }

        // Remove leading zeros and reverse answer
        while (ans.size() > 1 && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(),ans.end());
    return ans;
    }
};

