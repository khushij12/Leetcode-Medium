class Solution {
    public int maxArea(int[] height) {
        
        int p=0,q=height.length-1;
        int area = 0;
        while(p<q){
            area = Math.max(area,Math.min(height[p],height[q])*(q-p));
            
            if(height[p] < height[q]) p++;
            else q--;
        }
        
        return area;
    }
}