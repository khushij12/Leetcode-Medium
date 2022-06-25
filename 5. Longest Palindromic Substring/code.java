class Solution {
    public String longestPalindrome(String s) {
        
        int arr[][] = new int[s.length()+2][s.length()+2];
        int mx=1,st=0,end=0;
        for(int i=s.length();i>=1;i--){
            for(int j=s.length();j>=i;j--){
                if(s.charAt(i-1)==s.charAt(j-1) && Math.abs(i-j)==1 || i==j){
                    arr[i][j]=1;
                    if(mx<j-i+1){
                        mx=j-i+1;
                        st=i-1;end=j-1;
                    }
                    
                }else if(s.charAt(i-1)==s.charAt(j-1)){
                    arr[i][j]=arr[i+1][j-1];
                    if(arr[i][j]==1){
                        if(mx<j-i+1){
                        mx=j-i+1;
                        st=i-1;end=j-1;
                    }
                    }
                }
            }
        }
        
        // for(int i=0;i<s.length()+2;i++){
        //     for(int j=0;j<s.length()+2;j++){
        //         System.out.print(arr[i][j]+" ");
        //     }
        //     System.out.println();
        // }
        return s.substring(st,end+1);
            
    }
}