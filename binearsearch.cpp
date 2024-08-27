#include<iostream>
using namespace std;

int recursivebs(int nums[],int l,int r,int n){
    int m = (l+r)/2;
    if(l>r) return -1;

    if(n==nums[m]) return m;

    if(n>nums[m])
    {
        return recursivebs(nums,m+1, r, n);
    }
    else return  recursivebs(nums,l, m-1, n);

};


int main()
{
    int n;
    cout<<"enter size of array:"<<endl;
    cin>>n;
  int nums[n];

  cout<<"Enter elements in array:";
   for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<endl;
    
    int x;
    cout<<"Enter number to search:"<<endl;
    cin >> x;

    int ans = recursivebs(nums,0,n-1,x);
    cout<<"Position of number is "<<ans<<"th"<<endl;

}