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

using namespace std;
int main(int argc, char* argv[]){
	// basic bailout if there are anything else than 3 arguments
	if(argc !=3){
		cout << "Usage: sorter [sorterTemplateFile]." << endl;
		return 1;
	}// end if
	if(argv[1] != "bubble" || "heap" || "bucket" || "Bubble" || "Heap" || "Bucket"){
		cout << "You have entered and invalid type of sort." << endl;
		return 1;
	}// end if
	if(argv[2] < '0' || argv[2] > '1000000'){
		cout << "Your numbers are either to below 0 or above 1000000" << endl;
		return 1;
	}









}// end the main function
