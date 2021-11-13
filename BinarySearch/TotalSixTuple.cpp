#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
int getTuple(std::vector<int>&arr){
    int n=arr.size();
    std::vector<int>lhs;
    std::vector<int>rhs;
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            for(int c=0;c<n;c++){
                lhs.push_back((arr[a]*arr[b])+arr[c]);
            }
        }
    }
    for(int d=0;d<n;d++){
        for(int e=0;e<n;e++){
            for(int f=0;f<n;f++){
                if(arr[d]==0){//d==0 0 not alows here given us in question
                    continue;
                }
                rhs.push_back((arr[e]+arr[f])*arr[d]);
            }
        }
    }
    std::sort(lhs.begin(),lhs.end());
    std::sort(rhs.begin(),rhs.end());
//    logarr(lhs,0,lhs.size()-1);
//    logarr(rhs,0,rhs.size()-1);
    int ans=0;
    for(int i=0;i<lhs.size();i++){
       auto upper1 = std::upper_bound(rhs.begin(), rhs.end(), lhs[i]);
       auto upper2=std::lower_bound(rhs.begin(),rhs.end(),lhs[i]);
       int n=std::distance(lhs.begin(), upper1);
       int m=std::distance(lhs.begin(),upper2);
       ans+=(n-m);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    std::vector<int>arr={-1,1};
    cout<<getTuple(arr);
    return 0;
}
