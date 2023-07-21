/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        // int levels = 1+floor(log2(n));
        // vector<vector<TreeNode*>> dp(level, vector<TreeNode*>(n,0));
        vector<TreeNode*> ans;
        // vector<int> nums;
        // for(int i=0;i<n;i++) nums.push_back(i+1);

        // dfs(0,dp,ans,nums);

        for(int i=1;i<=n;i++){
            map<int,int> nums;
            nums[i]=true;
            vector<TreeNode*> leftSubtree = dfs(nums,n,1,i-1);
            vector<TreeNode*> rightSubtree = dfs(nums,n,i+1,n);
            
            for (auto left: leftSubtree) {
                if(rightSubtree.empty()){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    ans.push_back(root);
                }
                else
                for (auto right: rightSubtree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);    
                }
            }

            if(leftSubtree.empty()){
                
                for (auto right: rightSubtree) {
                    TreeNode* root = new TreeNode(i);
                    if(right)
                    cout<<i<<" "<<right->val<<endl;
                    root->right = right;
                    ans.push_back(root);
                }
            } 

            nums[i]=false;
        }
        return ans;
    }

    vector<TreeNode*> dfs(map<int,int> nums,int n, int st, int end){
        vector<TreeNode*> ans;
        if(st==end){
            ans.push_back(new TreeNode(st)); return ans;
        }
        if(st>end)
        {ans.push_back(nullptr); return ans;}
        
        for(int i=st;i<=end;i++){
            if(nums[i]==true) continue;

            nums[i]=true;
            
            vector<TreeNode*> leftSubtree = dfs(nums,n,st,i-1);
            vector<TreeNode*> rightSubtree = dfs(nums,n,i+1,end);

            for (auto left: leftSubtree) {
                if(rightSubtree.empty()){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    ans.push_back(root);
                }
                else
                for (auto right: rightSubtree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
            if(leftSubtree.empty()){
                for (auto right: rightSubtree) 
                {
                    TreeNode* root = new TreeNode(i);
                    root->right = right;
                    ans.push_back(root);
                }
            }
            nums[i]=false;
            
        }
        return ans;
    }
};
