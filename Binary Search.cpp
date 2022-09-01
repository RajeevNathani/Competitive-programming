#include<bits/stdc++.h> 
int findMedian(vector<vector > &A) 
{ 
  int rows = A.size(), col = A[0].size(),mini = A[0][0],maxi = A[0][col-1]; 
  for(int i=1;i<rows;i++)
  { 
    mini = min(mini,A[i][0]); 
  } 
  for(int i=1;i<rows;i++)
  { 
    maxi = max(maxi,A[i][col-1]); 
  } 
  // performing binary search from range mini to maxi 
  while(mini<maxi)
  { 
    int mid = mini + (-mini+maxi)/2; 
    int cnt = 0; 
    for(int i=0;i<rows;i++)
    { 
      cnt = cnt + (upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin()); 
    } 
    if(cnt<(rows*col+1)/2) mini = mid+1; 
    else maxi = mid; 
  } 
  return mini; 
}
