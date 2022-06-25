class Solution {
    public int divide(int dividend, int divisor) {
        if(divisor == 1 || divisor == -1){
            if(dividend==Integer.MIN_VALUE && divisor==-1) return Integer.MAX_VALUE;
            return divisor*dividend;
        } 
        
        if(divisor==0) return Integer.MAX_VALUE;
        if(dividend==0 || Math.abs((long) dividend)< Math.abs((long) divisor)) return 0;

        
        long lans = ldivide(Math.abs((long) dividend) , Math.abs((long) divisor));
        
        if(dividend<0 ^ divisor<0) {
            if(lans>Integer.MAX_VALUE) return Integer.MIN_VALUE;
            int ans = (int)lans;
            return -1*ans;
        }else return (int)lans;
            
    }
    
    long ldivide(long dividend,long divisor){
        if(dividend<divisor) return 0;
        long sum = divisor;
        long multiple = 1;
        
        while(sum+sum<=dividend){
            sum+=sum;
            multiple+=multiple;
        }
        
        return multiple + ldivide(dividend-sum,divisor);
    }
}