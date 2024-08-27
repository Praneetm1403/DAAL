#include<iostream>
using namespace std;
void printarr(int arr[],int l,int r)
{
	for(int i = l;i<r;i++)
	cout<<arr[i]<<" ";
cout<<endl;
}
void qsl(int arr[],int low,int high){
	int pivot,temp,i,j;
	if(low<high){
		cout<<"Before:";
		printarr(arr,low,high+1);
		pivot=high;
		cout<<"Pivot is:"<<arr[pivot]<<endl;
		i=low;
		j=high-1;
		while(i<j){
			
		while(arr[i]<arr[pivot] && i<=high){
			i++;
		}
		while(arr[j]>arr[pivot] && j>=low){
			j--;
		}
		if(i<j){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	if(i>j){
		temp=arr[i];
		arr[i]=arr[pivot];
		arr[pivot]=temp;
	}
	cout<<"After:";
	printarr(arr,low,high+1);
	qsl(arr,low,i-1);
	qsl(arr,i+1,high);
}
}
int main(){
	
	int n;
	cout<<"Enter size of array:";
	cin>>n;
	int arr[n];
	cout<<"Enter elements of array:";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
     cout<<"Unsorted array is:"<<endl;
    printarr(arr,0,n); 
	cout<<endl;
	cout<<"Passes Of The QS are:"<<endl;
	qsl(arr,0,n-1);
	cout<<endl;
	cout<<"Sorted array is"<<endl;
	printarr(arr,0,n);
}
