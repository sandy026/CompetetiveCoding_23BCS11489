class Solution {
public:
    long long gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }

    long long count(long long mid, long long lcm,
                    long long a, long long b){
        return mid/a+mid/b-mid/lcm;
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        long long mod=1e9+7;
        long long low=min(a,b);
        long long high=(long long)n*(low);
   
        long long lcm=(long long)(a*b)/gcd(a,b);

        while(low<high){
            long long mid=(low+high)/2;
            if(count(mid,lcm,a,b)>=n){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low%mod;
    }
};