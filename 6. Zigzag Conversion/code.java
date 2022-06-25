class Solution {
    public String convert(String s, int n) {
        
        String s1[] = new String[n];
        for(int i=0;i<n;i++) s1[i]="";
        int i=0;
        while(i<s.length()){
            for(int j=0;j<n && i<s.length();j++){
                s1[j]+=s.charAt(i++);
            }
            
            for(int j=n-2;j>=1 && i<s.length();j--){
                s1[j]+=s.charAt(i++);
            }
        }
        
        String ans="";
        
        for(i=0;i<n;i++){
            ans+=s1[i];
            // System.out.println(s1[i]);
        }
        
        return ans;
    }
}