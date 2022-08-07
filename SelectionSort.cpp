//Selection Sort Algorithm Implementation in C++

#include <iostream>
using namespace std;
int main() {
    int size,temp,i,j;
    cout<<"Enter the array size: ";
    cin>>size;
    int arr[size];
    //Array user input
    for(i=1;i<=size;i++)
    {
        cout<<"Enter array index of "<<i<<" is: ";
        cin>>arr[i];
    }
    //start selection sort algorithm
    for(i=1;i<=size-1;i++)//Parent loop
    {
        int min=i;
        int loc=i;
        for(j=i+1;j<=size;j++)//Child loop
        {
            //arr[j]<arr[min] that means array 2index value lessthan array 1 index. When if condition is become true
            // and min replace by j that means min=2 index.
            //otherwise if condition is false and j is increment and again check condition and repte previous step.
            if(arr[j]<arr[min])
            {

                min=j;
                loc=j;

            }

        }
        //if min!=i that means update min=j is not equals to index of 1. When if condition becomes true.
        //And swap two index. Swap index 1 and index min=j .
        //otherwise if condition is becomes false. That means if body is not executed and parent loop i is increment
        // and condition check and previous operation is executed.
        if(min!=i){
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }

    }

    //Display sorted array
    for(i=1;i<=size;i++)
    {
        cout<<"Enter sorted array index of "<<i<<" is: "<<arr[i]<<endl;

    }
    return 0;
}
