class Solution {
public:
    bool canJump(vector<int>& n) {
        if(n.size()==1) return true;
        int i=0;
        long mx=0;
        long k = 1;
        while(i<n.size()){
            if(i>mx) return false;
            mx=max(mx, (i+n[i])*k);
            i++;
        }

        return true;
    }
};
