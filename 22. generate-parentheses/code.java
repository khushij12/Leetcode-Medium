class Solution {
    List<String> ans = new ArrayList<String>();
    public List<String> generateParenthesis(int n) {
        
        
        rec(n,2*n,0,0,0,"");
        return ans;
    }
    
    void rec(int n,int n1,int i,int open,int close,String s){
        if(i==n1){
            ans.add(s);
            return;
        }
        
        if((open>=close && open+1<=n)){
              s+="(" ;
            rec(n,n1,i+1,open+1,close,s);
            s=s.substring(0,s.length()-1);
        }
        
        if(open>close){
            s+=")";
            rec(n,n1,i+1,open,close+1,s);
        }
        
        return;
    }
}