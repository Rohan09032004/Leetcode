class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int final=0;
        int nsize=sqrt(n);
        int size=(nsize+n-1)/nsize;
        vector<int>a(size,0);
        for(int i=0;i<n;i++){
            a[i/size]=max(a[i/size],baskets[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<size;j++){
            if(fruits[i]<=a[j]){
                     for (int k = j * size; k < min(n, j * size + size); k++) {
                        if (fruits[i] <= baskets[k]) {
                            final++;
                            baskets[k] = 0;
                            int maxi = 0;
                            for (int t = j * size; t < min(n, j * size + size); t++) {
                                maxi = max(maxi, baskets[t]);
                            }
                            a[j] = maxi;
                            
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return n-final;
    }
};