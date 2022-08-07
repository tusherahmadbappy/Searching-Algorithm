#include <iostream>
using namespace std;

// function to swap elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}



// function to rearrange array (find the partition point)
int partition(int array[], int low, int high) {

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j <high; j++) {
        if (array[j] <= pivot) {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // swap pivot with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
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
    // perform quicksort on data
    quickSort(arr, 1, size);

    for (i = 1; i <= size; i++) {
        cout << "Array elements of index " << i << " is: " << arr[i] << endl;


    }
    binarysearch(arr, size);

}