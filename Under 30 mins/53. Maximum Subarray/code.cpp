class Solution {
public:
    int maxSubArray(vector<int>& n) {
        
        return fun(n,0,n.size()-1);
    }

    int fun(vector<int>& n, int i, int j){

        if(i>j) return 0;
        if(i==j) return n[i];

        int m = (j-i)/2+i;

        int lss = fun(n, i, m);
        int rss = fun(n, m+1, j);

        int k = m-1;
        int mx=0, s=0;
        while(k>=i){
            s+=n[k--];
            mx = max(mx, s);
        }
        int mx1=0;
        s=0;
        k=m+1;
        while(k<=j){
            s+=n[k++];
            mx1 = max(s, mx1);
        }
        return max(lss, max(rss, n[m]+mx+mx1));
    }
};
