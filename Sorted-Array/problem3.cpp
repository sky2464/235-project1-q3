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
//Search Function prototype
int search(int arr[], int size, int x);
// Sort Function prototype , Insertion Sort
void sort(int arr[], int size);
// PrintArray Function prototype
void printArray(int arr[], int searchnum, int start, int end);

int main() {
	int x, value, size;

	cout << "Enter a number (n) for the size of array: " << endl;
	cin >> size;

	if (size <= 0) {
		cerr << "Enter a value greater than 0." << endl;
		cin >> size;
	}
	int arr[size];
	cout << "Please enter "<<size<<" SORTED numbers,\n"
			"and each time press enter to submit the input: \n";

	for (int i = 0; i <= size; i++) {
		cin >> value;
		arr[i] = value;
	}
	sort(arr, size); //Sorts the array in order, using an Insertion Sort.
	cout << "Enter a number to search for: " << endl;
	cin >> x;
	int output = 0;
	output = search(arr, size, x);
	cout << "The number " << x << " was found in index " << output << "."
			<< endl;
	int end = output - 5;
	printArray(arr, x, output, end);

	return 0;
}
// Search Function implementation
int search(int arr[], int size, int x) {
	int high = size - 1;
	int low = 0;
	int mid = 0;
	while (low < high) {
		mid = low + (high - low) / 2;

		if (arr[mid] == x) {
			return mid;
		}
		if (arr[mid] < x) {
			low = mid + 1;
		} else

			high = mid - 1;
	}
	return mid;

}
// Sort Function implementation
void sort(int arr[], int size) //Insertion Sort
		{
	int temp, j;
	for (int i = 0; i <= size; i++) {
		j = i;

		while (j > 0 && arr[j] < arr[j - 1]) {
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}
// PrintArray Function implementation
void printArray(int arr[], int searchnum, int start, int end) {
	if (arr[start] <= searchnum && arr[start] > 0) {
		if (start < 0) {
			return;
		}
		cout << arr[start] << endl;
		printArray(arr, searchnum, start - 1, end);
	} else if (arr[start] > searchnum) {
		int newstart = start - 1;
		if (newstart < 0) {
			return;
		}
		cout << arr[newstart] << endl;
		printArray(arr, searchnum, newstart - 1, end);
	} else {
	}

}
