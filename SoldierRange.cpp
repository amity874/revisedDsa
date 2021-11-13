#include<bits/stdc++.h>
using namespace std;
class Pair{
    public:
    int x;
    int y;
};
struct comp {
    bool operator()(const Pair &x, const Pair &y) const {
        if (x.y != y.y) {
            return x.y < y.y;
        }
 
        return x.x < y.x;
    }
};
int clac(std::vector<int>&a){
    int n=a.size();
    std::vector<Pair>l(n);
    for(int i=0;i<n;i++){
        if(a[i]>-1){
        l[i].x=(i-a[i]);
        l[i].y=(i+a[i]);
    }
    }
    std::sort(l.begin(),l.end(),comp());
    int maxright=0;
    int count=0;
    int i=0;
    while (maxright<a.size()){
        if(i==l.size()){
            return -1;
        }
        if(l[i].x>maxright){
            return -1;
        }
        int curr_max=l[i].y;
        while (i+1<l.size()&&l[i+1].x<=maxright){
            i+=1;
            curr_max=std::max(curr_max,l[i].y);      
        }
        if(curr_max<maxright){
            return -1;
        }
        count+=1;
        maxright=curr_max+1;
        i+=1;
    }
    return count;
}
int main(int argc, char const *argv[])
{
    std::vector<int>a={-1,2,2,-1,0,0};
    std::cout<<clac(a);
    return 0;
}