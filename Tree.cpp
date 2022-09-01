class Solution{ 
  public: //Function to return the maximum sum of non-adjacent nodes. 
  
   unordered_map<Node*, int> dp; 
  
    int getMaxSum(Node *root) { 

    if(!root) return 0;
    int choice1 = root->data, choice2;
    if(dp[root]) return dp[root]; 
    if(root->left) choice1 += getMaxSum(root->left->left) + getMaxSum(root->left->right);
    if(root->right) choice1 += getMaxSum(root->right->left) + getMaxSum(root->right->right);
    choice2 = getMaxSum(root->left) + getMaxSum(root->right);
    return dp[root] = max(choice1, choice2);
}
};
