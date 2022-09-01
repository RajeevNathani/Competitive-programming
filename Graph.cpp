bool valid(int i, int j, int n, int m) {
return (i >= 0 and j >= 0 and i < n and j < m); 
}

void dfs(vector<vector> &visited, int i, int j, vector<vector> &A, int n, int m, int &cnt, vector<vector> &movements) 
{
  visited[i][j] = 1; 
   cnt++; 
   for(auto child : movements) { 
     int x = child[0] + i, y = j + child[1]; 
     if(valid(x, y, n, m) and !visited[x][y] and A[x][y] == 1) { 
       dfs(visited, x, y, A, n, m, cnt, move); 
     }
   }
}                                                                                                                

int solve(vector<vector > &A) 
{ 
  int n = A.size(), m = A[0].size(); 
  vector<vector> visited(n+1, vector(m+1, false)); 
  int ans = 0, cnt = 0; 
  vector<vector> movements = {{1, 0}, {-1, 0}, {0, 1}, {0, -1} , {1, 1}, {1, -1}, {-1, -1}, {-1, 1}}; 
  for(int i = 0; i < n; i++) { for(int j = 0; j < m; j++) { 
    if(!visited[i][j] and A[i][j] == 1) { 
      cnt = 0; 
      dfs(visited, i, j, A, n, m, cnt, movements); 
      ans = max(ans, cnt); 
    } 
  } 
  } 
  return ans; 
}

