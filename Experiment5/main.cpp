
class Solution {
public:
    typedef long long ll;
    bool check(ll time,vector<int>& batteries,int n){
        ll targetmin=n*time;
        ll sum=0;
        for(int i=0;i<batteries.size();i++){
            sum+=min((ll)batteries[i],time);
            if(sum>=targetmin){
                return true;
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll low=1;
        ll high=accumulate(batteries.begin(),batteries.end(),0ll)/n;

        ll res=0; 

        while(low<=high){
            ll mid=(low+high)/2;
            if(check(mid,batteries,n)){
                res=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
};