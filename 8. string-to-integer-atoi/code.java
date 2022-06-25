class Solution {
    public int myAtoi(String s) {
        
        int sign=1;
        long x=0;
        boolean f=false;
        
        for(int i=0;i<s.length();i++){
            if(!f && s.charAt(i)=='-') {sign=-1; f=true;}
            else if(!f && s.charAt(i)=='+') {sign=1; f=true;}
            else if(s.charAt(i)>='0' && s.charAt(i)<='9'){
                x*=10;
                x+=Integer.parseInt(s.charAt(i)+"");
                
                if(sign==1 && x>Integer.MAX_VALUE)
                    return Integer.MAX_VALUE;
                else if(sign==-1 && x<Integer.MIN_VALUE)
                    return Integer.MIN_VALUE;
                
                f=true;
            }else if(!f && !(s.charAt(i)>='0' && s.charAt(i)<='9') && s.charAt(i)!=' ') return 0;
            else if(f==true) break;

            
        }
        x = sign*x;
        if(x>Integer.MAX_VALUE)
            return Integer.MAX_VALUE;
        else if(x<Integer.MIN_VALUE)
            return Integer.MIN_VALUE;
        return (int)x;
    }
}