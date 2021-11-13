#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
ll pairOfTopic(std::vector<ll>&teacher,std::vector<ll>&student,int n){
    ll c[n];
    for(int i=0;i<n;i++){
        c[i]=student[i]-teacher[i];
    }
    std::sort(c,c+n);
    ll ans=0;
    for(int i=0;i<n;i++){
        int x=-c[i];
        auto it=std::lower_bound(c+i+1,c+n,x);
        int id=it-c;
        ans+=(id-(i+1));
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    ll n;
    cin>>n;
    std::vector<ll>student(n,0);
    std::vector<ll>teacher(n,0);
    for(int i=0;i<n;i++){
        cin>>teacher[i];
    }
    for(int i=0;i<n;i++){
        cin>>student[i];
    }
    cout<<pairOfTopic(teacher,student,n);
    return 0;
}
