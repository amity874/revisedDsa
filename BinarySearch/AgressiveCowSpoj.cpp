#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool possible(std::vector<ll>&position,ll mid,ll cows){
    ll allocate_cow=1;
    ll LastBarn=position[0];
    for(int i=1;i<position.size();i++){
        if(position[i]-LastBarn>=mid){
            allocate_cow++;
            LastBarn=position[i];
        }
        if(allocate_cow==cows){
            return true;
        }
    }
    return false;
}
ll BinarySerach(std::vector<ll>&position,int cows){
 std::sort(position.begin(),position.end());
    int n=position.size();
    ll lo=1;
    ll hi=position[n-1];
    ll ans=-1;
    while (lo<=hi){
        ll mid=lo+(hi-lo)/2;
        if(possible(position,mid,cows)){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return ans;
}
int main(int argc, char const *argv[]){
 ll t;
 cin>>t;
 while (t--){
     /* code */
     ll n;
     ll c;
     cin>>n>>c;
     std::vector<ll>position(n,0);
     for(int i=0;i<n;i++){
         cin>>position[i];
      }
 cout<<BinarySerach(position,c);
 }
    return 0;
}
