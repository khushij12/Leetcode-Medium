class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        HashMap<Character,Integer> map = new HashMap<>();
        int mx=0,cnt=0,k=0;
        for(int i=0;i<=s.length();i++){
            if(i==s.length()) {
                mx = Math.max(mx,cnt);
                break;
            }
            if(map.containsKey(s.charAt(i))){
                mx = Math.max(mx,cnt);
                
                cnt=i-map.get(s.charAt(i));
                // System.out.println(i+" "+mx+" "+cnt);
                for(int j=k;j<map.get(s.charAt(i));j++)
                    map.remove(s.charAt(j));
                k=map.get(s.charAt(i))+1;
                map.put(s.charAt(i),i);
                
            }else{
                map.put(s.charAt(i),i);
                cnt++;
            }
        }
        // System.out.println("==========");
        return mx;
    }
}