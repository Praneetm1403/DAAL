#include <iostream>
using namespace std;
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        //printArray(arr,5);
        mergeSort(arr, mid + 1, right);
        //printArray(arr,5);
        merge(arr, left, mid, right);
        //printArray(arr,5);

    }
    else return;
}

int main() {
   
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
    printArray(arr,n); 
    cout<<endl;
    cout<<"Passes Of MS are"<<endl;
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array: ";
   printArray(arr,n);
    return 0;
}
