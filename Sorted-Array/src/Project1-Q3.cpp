//============================================================================
// Name        : Project1-Q3.cpp
// Author      : Navid Saboori., Usman
// Version     : 3.0
// Professor   : Elaheh Vahdani
// Copyright   : CSCI 235, SPRING 2018
// Description : Sorted Array C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;
// The search function takes the array and uses the divide and separate method to search for the number user is looking for. it takes the middle number of array and compares whether that number is smaller or greater than what he user is looking for and updates the low and high variable accordingly.
int search(int arr[], int size, int x)
{
    int high = size;
    int low = 0;
    int mid=0;
    while (low <= high)
    {
        mid = low +(high-low)/2;
        
        if(arr[mid] == x)
        {
            return mid;
        }
        if(arr[mid] < x)
        {
            low = mid+1;
        }
        else
            
            high = mid-1 ;
    }
    return mid;
    
    
}


void sort(int arr[], int size) //Insertion Sort
{
    int temp, j;
    for (int i = 0; i <= size; i++)
    {
        j = i;
        
        while (j > 0 && arr[j] < arr[j - 1])
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}
//This printArray function uses the parameter to determine whether the searchnumber is smaller, bigger or equal to the number that was returned by the Search function and it uses recursion to print 5 numbers that are smaller than the search number. For example if there are only 3 numbers in the array that are smaller than the searchnumber then it will print those 3 numbers only.

void printArray(int arr[],int searchnum, int start, int end)
{
    if(start == end )
    {
        return;
    }
    else if(arr[start] == searchnum)
    {
        start = start-1;
        cout<< arr[start]<<endl;
        printArray(arr,searchnum,start-1,end);
    }
    else if(searchnum > arr[start])
    {
        if(start < 0)
        {
            return;
        }
        cout<< arr[start]<<endl;
        printArray(arr,searchnum,start-1,end);
    }
  else if(arr[start] > searchnum)
    {
        int newstart = start-1;
        if(newstart < 0)
        {
            return;
        }
        cout<< arr[newstart]<<endl;
        printArray(arr, searchnum, newstart-1, end);
    }
    else
    {
        
    }
    
}
//  This is the main programme which asks the user to enter the number of elements and save the number in the variable size. It then creates an array of than size and asks the user to enter values for each element. Once the user is finished entering all elements, it then sorts the array in ascending order. Next, it asks the user to input a search number which can or cannot be in array and calls on function Search to do binary search and return the value and store it in variable called "output"
int main()
{
    int x, value, size;
    
    cout << "Enter the number of elements you would like: " << endl;
    cin >> size;
    
    if (size <= 0)
    {
        cerr << "Enter a value greater than 0." << endl;
        cin >> size;
    }
    int arr[size];
    cout << "Begin entering your element values: " << endl;
    
    for (int i = 0; i <size; i++)
    {
        cin >> value;
        arr[i] = value;
    }
    sort(arr, size);
    cout << "Enter a number to search for: " << endl;
    cin >> x;
    int output = 0;
    output = search(arr, size, x);
   // cout<<"the return index is "<< output << " and the value is "<<arr[output]<<"."<<endl;
    if(output == 0)
    {
        cout<<"There are no numbers in the set that are smaller than "<< x<<"."<<endl;
    }
    else
    {
    cout<<"The elements that are smaller than number "<< x <<" in the set are :"<<endl;
    int end = output - 5;
    if(arr[output] > x)
           {
               end = output -6;
           }
    printArray(arr,x,output,end);
    }
    return 0;
}
