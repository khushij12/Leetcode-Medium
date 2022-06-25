class Solution {
    public int reverse(int x) {
        
        String number;
        boolean isNegative=false;
        if(x<0) isNegative = true;
        
		x = Math.abs(x);
		number = String.valueOf(x);
        
        if(number.charAt(0) == '-')
            number = number.substring(1);
        // System.out.println(number);
		String s1 = "2147483648";
		int s = number.length();
		if(s==10){
			for(int i=9;i>0;i--){
				int c = check(s1,i,number,s-i-1);
				if(c==1) return reverseIt(number,isNegative);
				else if(c==0) continue;
				else return 0;
			}
            
            if(isNegative){
                if(Integer.parseInt(number.charAt(0)+"")<8){
					return reverseIt(number,isNegative);
                }else return 0;
            }else{
                if(Integer.parseInt(number.charAt(0)+"")<7){
					return reverseIt(number,isNegative);
                }else return 0;
            }
		}
		
        return reverseIt(number,isNegative);
		
    }
	
	int check(String s1,int i,String number,int j){
		if(Integer.parseInt(number.charAt(i)+"")<Integer.parseInt(s1.charAt(j)+"")){
			return 1;
		}else if(Integer.parseInt(number.charAt(i)+"")==Integer.parseInt(s1.charAt(j)+"")){
			return 0;
		}else return -1;
	}
	
	int reverseIt(String number,boolean isNegative){
		StringBuilder input1 = new StringBuilder();
 
        input1.append(number);
        input1.reverse();
		
		if(isNegative) 
		return -1*Integer.parseInt(input1.toString());
		return Integer.parseInt(input1.toString());
	}
}