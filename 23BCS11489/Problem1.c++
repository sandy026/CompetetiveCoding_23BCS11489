class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        while(l<r){
            int mid=l+(r-l)/2;
            long long ops=0;
            for(int x:nums){
                ops+=(x-1)/mid;
            }
            if(ops<=maxOperations){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};