#include <iostream>

using namespace std;

void merge(int arr[], int p, int q, int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

int binarysearch(int arr[],int size)
{
    int l=1,SearchValue;
    cout<<"Enter searching value is: ";
    cin>>SearchValue;
    int h=size;

    while(l<=h)//5
    {
        int mid = (l + h) / 2;

        if(arr[mid]==SearchValue)
        {
            cout<<"SearchValue is found and location is: "<<mid<<" Low: "<<l<<endl;
            if(mid<=h) {
                mid++;
                if (arr[mid] == SearchValue)
                    cout << "SearchValue is found and location is: " << mid << " Low: " << l << endl;
                mid--;
                if(arr[mid]==SearchValue){
                    mid--;
                    if (arr[mid] == SearchValue)
                        cout << "SearchValue is found and location is: " << mid << " Low: " << l << endl;
                }
            }

            break;

        }
        else if(arr[mid]<SearchValue)
        {
            l=mid+1;//4,6

        }
        else
            h = mid - 1;//2

        //mid = (l + h) / 2;

    }
    if(l>h)
        cout<<"\"Not found! isn't present in the array: "<<SearchValue<<endl;

}


int main() {
    int size, i, j, temp, v;
    cout << "Enter the array size: ";
    cin >> size;

    int arr[size];
    for (i = 1; i <= size; i++) {
        cout << "Array elements of index " << i << " is: ";
        cin >> arr[i];

    }

    mergeSort(arr, 1, size);
    for (i = 1; i <= size; i++) {
        cout << "Array elements of index " << i << " is: "<<arr[i]<<endl;


    }
    binarysearch(arr,size);


}