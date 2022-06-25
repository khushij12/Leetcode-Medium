class Solution {
    public String convert(String s, int numRows) {
        
        String str="";
       if(numRows==1 || (s.length()/numRows)==0) return s;
        
            for(int j=0;j<s.length();j+=(2*numRows-2))
                str+=s.charAt(j);
        boolean x=false;
        for(int i=1;i<numRows-1;i++){
            x=false;
            for(int j=i;j<s.length();){
                
                str+=s.charAt(j);
                if(!x)
                {
                    j+=2+(2*(numRows-i-2));
                    x=true;
                    }
                else
                {
                    j+=2+(2*(i-1));
                   x=false; 
                }
            }
                
        }
         for(int j=numRows-1;j<s.length();j+=(2*numRows-2))
                str+=s.charAt(j);
        return str;
    }
}