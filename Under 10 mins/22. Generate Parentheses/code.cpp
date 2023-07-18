class Solution {
public:
    set<string> st;
    vector<string> generateParenthesis(int n) {
        fun("", 0, 0, n);

        return vector<string>(st.begin(), st.end());
    }

    void fun(string s, int sa, int e, int n){
        if(e==n) {
            st.insert(s);
            return;}

        if(sa<n)
        fun(s+"(", sa+1, e, n);
        
        if(e<sa)
        fun(s+")", sa, e+1, n);
    }
};
