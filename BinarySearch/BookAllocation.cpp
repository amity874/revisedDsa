#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool possible(std::vector<int>&arr,int mid,int student){
    int allocate_student=1;
    int current_page=arr[0];
    for(int i=1;i<arr.size();i++){
        if(current_page+arr[i]>mid){
            current_page=arr[i];
            allocate_student+=1;
        }
        if(allocate_student>student){
            return false;
        }
        else{
            current_page+=arr[i];
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    std::vector<int>books={12,34,67,90};
    int student=2;
     std::vector<int>::iterator result;
    result = std::max_element(books.begin(), books.end());
    int n= std::distance(books.begin(), result);
    int m=books[0];
    for(int i=1;i<books.size();i++){
        m+=books[i];
    }
    int lo=n;
    int hi=m;
    int ans=INT_MAX;
    while (lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(possible(books,mid,student)){
            hi=mid-1;
            ans=mid;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
