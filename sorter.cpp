// James Moore
// Homeword #6 
// Davies
// start date 11/19/14
// this program takes two command line agrumments. the first will be what type
// of sort. the second will be how many numbers in the array. It will then sort
// using the sort random numbers that are generated then sorted by the 
// requested sort


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>

// delcaring all the function 
bool isSorted(int [], int);
void bubbleSort(int [], int);
void heapify(int *, int, int);
void heapsort(int *, int);
void buildheap(int *, int);
void swap(int&, int&);
void bucketsort(int *, int);

using namespace std;
int main(int argc, char* argv[]){
	// basic bailout if there are anything else than 3 arguments
	if(argc !=3){
		cout << "Usage: sorter [sorterTemplateFile]." << endl;
		return 1;
	}// end if
	int arraySize = atoi(argv[2]);
	// test to make sure the array size is between 0 and 1,000,000
	if(arraySize < 0){
		cout << "Your numbers are either to below 0 or above 1000000" << endl;
		return 1;
	}//end if
	if(arraySize > 1000000){
		cout << "Your numbers are either to below 0 or above 1000000" << endl;
		return 1;
	}//end if
	int unsortedArray[arraySize];
	for(int i= 0; i < arraySize; i++){
		int randomNum = rand() %999999;
		unsortedArray[i] = randomNum;
	}//end for
	


	string whatSort = argv[1];
	if((whatSort == "bubble") || (whatSort == "Bubble")){
		bubbleSort(unsortedArray, arraySize);
	}// end if
	else if((whatSort == "bucket") || (whatSort == "Bucket")){
		bucketsort(unsortedArray, arraySize);
	}// end if
	else if((whatSort == "heap") || (whatSort == "Heap")){
		heapsort(unsortedArray, arraySize);
	}// end if
	else{
		cout << "You have entered an invalid type of sort" << endl;
		return 1;
	}//end else
	if(isSorted(unsortedArray, arraySize)){
		cout << "yea" << endl;
	}// end if

	if(!isSorted(unsortedArray, arraySize)){
		cout << "nay" << endl;
	}// end if





}// end the main function

//this function is used to check to see if the list is sorted.
bool isSorted(int *array, int size){
	for(int i = 0; i<size-1; i++){
		if(array[i] > array[i+1]){
			return false;
		}// end if
	}// end for
	return true;
}// end function

// THis is the bubble sort function
void bubbleSort(int *array, int size){
	int temp; // used for the swap
	for(int i = size; i >1; i--){
		for(int j =0; j < i-1; j++){
			if(array[j]>array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}// end if
		}// end for j
	}// end for i
}// end function

//this sorts the heap
void heapsort(int *array, int size){
	int heapsize = size;
	buildheap(array, size);
	for(int i = size-1; i >=1; i--){
		swap(array[0], array[i]);
		heapsize--;
		heapify(array, heapsize, 0);
	}// end for
}// end function

// this builds the heap
void buildheap(int *array, int size){
	for(int i = floor((size)/2); i >= 0; i--){
		heapify(array, size, i);
	}// end for
}// end function

// heapify
void heapify( int *array, int size, int root){
	int left = 2*root+1;
	int right = 2*root+2;
	int largest;
	if((left < size) && (array[left] > array[root])){
		largest = left;
	}// end if
	else 
		largest = root;
	if((right < size) && (array[right] > array[largest])){
		largest = right;
	} // end if
	if(largest != root){
		swap(array[root], array[largest]);
		heapify(array, size, largest);
	}// end if
} // end function

// this just swaps
void swap( int& x, int& y){
	int temp;
	temp = x;
	x=y;
	y = temp;
}// end function


// this is the bucket sort
void bucketsort(int *array, int size){
	int min;
	int max;
	int buckets;
	int index = 0;
	min = max = array[0];
	for(int i = 1; i < size; i++){
		min = (array[i] < min) ? array[i] : min;
		max = (array[i] > max) ? array[i] : max;
	} // end for
	buckets = max - min + 1;
	int * B = new int[buckets];
	for(int i = 0; i < buckets; i++){
		B[i] = 0;
	}// end for
	for(int i = 0; i <size; i++){
		B[array[i] - min]++;
	}// end for
	for(int i = min; i <= max; i++){
		for(int j = 0; j <B[i-min]; j++){
			array[index++] = i;
		}// end for
	}// end for
}   // end function
