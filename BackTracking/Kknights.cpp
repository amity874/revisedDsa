#include<bits/stdc++.h>
using namespace std;
void Display(int n,std::vector<std::vector<int>>&grid){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
    }
    std::cout<<"\n";
}
}
bool isItSafe(std::vector<std::vector<bool>> visited,int i,int j,int n){
    return (i>=0 && j>=0 && i<n && j<n && visited[i][j]==false);
}
void CalculatePath(std::vector<std::vector<bool>> &visited,std::vector<std::vector<int>>& grid,int n,int i,int j,int count){
if(count==n*n-1){
    grid[i][j]=count;
    Display(n,grid);
    cout<<"\n";
    return;
}
if(count>=n*n){
    return;
}
int xdir[8]={-2,-2,-1,-1,2,2,1,1};
int ydir[8]={1,-1,2,-2,1,-1,2,-2};
visited[i][j]=true;
grid[i][j]=count;
for(int k=0;k<8;k++){
    if(isItSafe(visited,i+xdir[k],j+ydir[k],n)){
        CalculatePath(visited,grid,n,i+xdir[k],j+ydir[k],count+1);
    }
}
grid[i][j]=-1;
visited[i][j]=false;
}
void permutation(int n){
    std::vector<std::vector<bool>> visited(n,std::vector<bool>(n,false));
    std::vector<std::vector<int>> grid(n,std::vector<int>(n,-1));
    CalculatePath(visited,grid,n,0,0,0);
}
int main(int argc, char const *argv[])
{
    int k;
    cin>>k;
    permutation(k);
    return 0;
}
