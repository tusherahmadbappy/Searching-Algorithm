#include <iostream>
#include <vector>
using namespace std;
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



using namespace std;
int main() {
    int size,i,j,temp,v;
    cout<<"Enter the array size: ";
    cin>>size;

    int arr[size];
    for(i=1;i<=size;i++)
    {
        cout<<"Array elements of index "<<i<<" is: ";
        cin>>arr[i];

    }



    //insertion sort algorithm implementation
    for (int step = 1; step <=size; step++) {
        int key = arr[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key <=arr[j] && j >= 1) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }

    cout<<endl<<"After swapping array elements are: "<<endl;
    for( i=1;i<=size;i++)
    {
        cout<<"Array elements index of "<<i<<" is: "<<arr[i]<<endl;
    }

    binarysearch(arr,size);



    return 0;
}
