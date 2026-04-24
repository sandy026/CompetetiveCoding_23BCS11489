class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
    const int MOD=1e9+7;
    vector<int>bitcount(31,0);
    for(int num:nums){
        for(int i=0;i<31;i++){
            if(num&(1<<i)){
                bitcount[i]++;
            }
        }
    }      
    long long ans=0;
    for(int j=0;j<k;++j){
        int x=0;
        for(int i=0;i<31;++i){
            if(bitcount[i]>0){
                x|=(1<<i);
                bitcount[i]--;
            }
        }
        ans=(ans+1LL*x*x)%MOD;
    }
    return ans;
    }
};