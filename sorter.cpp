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


bool isSorted(int [], int);
void bubbleSort(int [], int);
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
	cout << unsortedArray[i] << ", ";
	}//end for
	


	string whatSort = argv[1];
	if((whatSort == "bubble") || (whatSort == "Bubble")){
		cout << "You have entered " << whatSort << " 3" << endl;
		bubbleSort(unsortedArray, arraySize);
		//return 1;
	}// end if
	else if((whatSort == "bucket") || (whatSort == "Bucket")){
		cout << "You have entered " << whatSort << " 2" << endl;
		//return 1;
	}// end if
	else if((whatSort == "heap") || (whatSort == "Heap")){
		cout << "You have entered " << whatSort << endl;
		//return 1;
	}// end if
	else cout << "You have entered an invalid type of sort" << endl;

	if(isSorted(unsortedArray, arraySize)){
		cout << "the array is sorted" << endl;
		for(int i =0; i<arraySize; i++){
			cout << unsortedArray[i] << endl;
		}
	}// end if

	if(!isSorted(unsortedArray, arraySize)){
		cout << "the array is not sorted" << endl;
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
