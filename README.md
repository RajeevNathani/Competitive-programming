# Competitive-programming
A learning project which involved the implementation of various algorithms and Data Structures in C++

Problem Description

Given a binary matrix A of size N x M.

 Cells which contain 1 are called filled cell and cell that contain 0 are called empty cell.

Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.

If one or more filled cells are also connected, they form a region. Find the length of the largest region.

Problem Constraints
 1 <= N, M <= 102

 A[i][j]=0 or A[i][j]=1

Code- 

bool valid(int i, int j, int n, int m)
{   
    return (i >= 0 and j >= 0 and i < n and j < m);
}


void dfs(vector<vector<int>> &visited, int i, int j, vector<vector<int>> &A, 
         int n, int m, int &cnt, vector<vector<int>> &movements)
{
    visited[i][j] = 1;
    cnt++;
    for(auto child : movements)
    {
        int x = child[0] + i, y = j + child[1];
        if(valid(x, y, n, m) and !visited[x][y] and A[x][y] == 1)
        {
            dfs(visited, x, y, A, n, m, cnt, move);
        }
    }
}




int solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    vector<vector<int>> visited(n+1, vector<int>(m+1, false));
    int ans = 0, cnt = 0;
    vector<vector<int>> movements = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}
                                , {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j] and A[i][j] == 1)
            {
                cnt = 0;
                dfs(visited, i, j, A, n, m, cnt, movements); 
                ans = max(ans, cnt);
            }
        }
    }
    return ans;
}
                                                                                                                                              
  
 
  
Problem Description
  
Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right..
  
Code-
  
 #include<bits/stdc++.h>
int findMedian(vector<vector<int> > &A) {
    int rows = A.size(), col = A[0].size(),mini = A[0][0],maxi = A[0][col-1];
    for(int i=1;i<rows;i++){
        mini = min(mini,A[i][0]);
    }
        for(int i=1;i<rows;i++){
        maxi = max(maxi,A[i][col-1]);
    }
    // performing binary search from range mini to maxi
    while(mini<maxi){
        int mid = mini + (-mini+maxi)/2;
        int cnt = 0;
        for(int i=0;i<rows;i++){
            cnt = cnt + (upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin());
        }
        if(cnt<(rows*col+1)/2) mini = mid+1;
        else maxi = mid;
    }
    return mini;
}
                               
                               
                               

                               
                               
Problem Description-

 Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

                                               
 1 ≤ Number of nodes in the tree ≤ 10000
1 ≤ Value of each node ≤ 100000

 class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    unordered_map<Node*, int> dp;
    int getMaxSum(Node *root) 
    {
        // Add your code here
        
        if(!root) return 0;
        int choice1 = root->data, choice2;
        if(dp[root]) return dp[root]; 
        if(root->left) choice1 += getMaxSum(root->left->left) + getMaxSum(root->left->right);
        if(root->right) choice1 += getMaxSum(root->right->left) + getMaxSum(root->right->right);
        choice2 = getMaxSum(root->left) + getMaxSum(root->right);
        return dp[root] = max(choice1, choice2);
    }
};

                               
                               
                               
                               
  
  
