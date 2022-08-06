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

void bubblesort(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;

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

    //Parrent loop
    for(i=1;i<=size-1;i++)
    {
        for(j=1;j<=size-i;j++)//child loop
        {
            //arr[j]>arr[j+1] that means if condition becomes
            // true and if body is executed
            //otherwise j increment  and condition check
            //and previous step is check.
            if(arr[j]>arr[j+1])//Swapping logic
                swap(arr[j],arr[j+1]);
        }
    }

    cout<<endl<<"After swapping array elements are: "<<endl;
    for(int i=1;i<=size;i++)
    {
        cout<<"Array elements index of "<<i<<" is: "<<arr[i]<<endl;
    }

    binarysearch(arr,size);



    return 0;
}
