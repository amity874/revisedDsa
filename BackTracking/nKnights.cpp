#include<bits/stdc++.h>
using namespace std;
int ans=0;
void Display(int n,std::vector<std::vector<bool>>&grid){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==true){
              cout<<"K"<<" ";
            }
            else{
                cout<<"."<<" ";
            }
    }
    std::cout<<"\n";
}
}
bool isItsafe(std::vector<vector<bool>> &visited,int row,int col,int n){
    if(row-2>=0 && col-1>=0 && visited[row-2][col-1]==true) return false;
    if(row-1>=0 && col-2>=0 && visited[row-1][col-2]==true) return false;
    if(row-2>=0 && col+1<n && visited[row-2][col+1]==true) return false;
    if(row-1>=0 && col+2<n && visited[row-1][col+2]==true) return false;
    return true;
}
void placeKnightsHelper(std::vector<vector<bool>> &visited,int n,int cr,int cc,int cnt){
if(cnt==n){
    ans++;
    // Display(n,visited);
    // cout<<"\n";
    return;
}
for(int i=cr;i<n;i++){
    for(int j=(i==cr)?cc:0;j<n;j++){
        if(isItsafe(visited,i,j,n)){
            visited[i][j]=true;
            placeKnightsHelper(visited,n,i,j+1,cnt+1);
            visited[i][j]=false;
        }
    }
}
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
     std::vector<vector<bool>> visited(n,std::vector<bool>(n,false));
     placeKnightsHelper(visited,n,0,0,0);
    cout<<ans;
    return 0;
}
