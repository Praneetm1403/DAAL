#include<bits/stdc++.h>
using namespace std;
int main()  
{
    vector<int> arr(5);
    cout <<"Enter numbers in array"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }

    cout<<"Array is "<<endl;
      for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int n;
    cout<<"Enter number to search"<<endl;
    cin >> n;

     for(int i=0;i<5;i++)
    {
        if(arr[i]==n)
        {   
            
            cout<<"Number is in "<<i <<"th"<<" "<<"position"<<endl;
            break;
        }

    }
    
    


}