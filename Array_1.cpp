#include <iostream>
using namespace std;
void printa(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    int arr[6] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // code to add at given index
    int index;
    cout << "Enter the index at which you want to add.";
    cin >> index;
    int element;
    cout << "Enter the element: " << endl;
    cin >> element;
    cout<<size;
    for (int i = size-1; i > -1; i--)
    {
        if (index == (i))
        {

            arr[i+1] = arr[i];
            arr[i] = element;
            break;
        }
        else
        {
            arr[i+1] = arr[i];
        }
    }
    size = sizeof(arr) / sizeof(arr[0]);
    cout<<size<<"size"<<endl;
    printa(arr, size);
    // code to delete the element
    int index,element;
    size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Enter the index"<<endl;
    cin>>index;
    cout<<"Enter the element"<<endl; 
    cin>>element;
    for(int i=index;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
    size = sizeof(arr) / sizeof(arr[0]);
    printa(arr,size);
    return 0;
}
