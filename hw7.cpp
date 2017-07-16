// Programmer: * Sasha Morgan*
// Homework 7
// Date: * 12/1*                  


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

// Function Prototypes

// Reads the first line in the file for the maximum quiz score
// Precondition: fin stream is initialized with a open file containing scores
// Postcondition: returns the maximum score for the quiz or -1 if 
// an error occurred
int get_max_score(ifstream &fin);

// Initializes the counter for each score to zero
// Precondition: "scores" must be declared and allocated with length of "size"
// Postcondition: all indices of "scores" initialized to zero
void init_score_count(int scores[], int size);

// Counts the occurrence of each score in the file and stores them in "scores"
// Precondition: indices of "scores" must be initialized to zero,
// and "scores" must have a length of "size", "fin" must be initialized 
// Postcondition: each index is equal to the number of occurrences for that 
// particular score. i.e. if the score 89 appeared 3 times index 89 would
// be equal to 3
void count_scores(int scores[], int size, ifstream &fin);

// Prints the count for each score if greater than zero and then prints the
// average score 
// Precondition: "scores" must have length of "size" be and contain the counts 
// for each score
// Postcondition: Prints each index in "scores" if the count is greater than
// zero and displays the average of the scores. If there aren't scores in the
// file nothing is printed
void print_analysis(int scores[], int size);

// This program reads a file containing quiz scores, counts the number
// of occurrences for each score then prints some basic metrics like the average
// score. The first line of the input file is the maximum score that can
// be obtained on the quiz. Completely empty files will print an error message
// while a file with only the max score will print nothing.
int main()
{
	// array to hold the counts for the quiz scores 
	int *scores;
	// the size of the scores array 
	int size;
	// file name containing the quiz scores 
	string fileName;
	// input file stream for quiz score file
	ifstream fin;


	// print welcome message and get the file containing the quiz scores
	cout << "Welcome to my Quiz Score Analysis Program!\n" << endl;
	cout << "Enter the file name containing the quiz scores: ";
	cin >> fileName;

	// try to open the file the user provided
	fin.open(fileName.c_str());

	// test if opened correctly
	if (fin.fail())
	{
		cout << "Error opening file: " << fileName << endl;
		exit(1);
	}

	// get the maximum score for the exam  
	// need to accommodate the maximum score in the array
	// i.e. a score max of 100 requires an index 100, so the
	// array size needs to be at least be 101
	if ((size = get_max_score(fin)) == -1)
	{
		cout << "Error reading file: " << fileName << endl;
		exit(1);
	}

	// "new" allows me to dynamically choose an array size at runtime 
	scores = new int[size];

	// set the counter for each score to zero 
	init_score_count(scores, size);

	// count the scores from the rest of the file 
	count_scores(scores, size, fin);

	// print our analysis of the quiz scores	
	print_analysis(scores, size);

	// free the space allocated for the scores 
	delete[] scores;

	// close the file
	fin.close();

	return 0;
}

// Function implementations

// Reads the first line in the file for the maximum quiz score
// Precondition: fin stream is initialized with a open file containing scores
// Postcondition: returns the maximum score for the quiz or -1 if 
// an error occurred
int get_max_score(ifstream &fin)
{
	int max;

	/* read the max quiz score value from the file */
	fin >> max;
	/* if we encountered an error return -1 */
	if (fin.fail())
	{
		max = -1;
		return max;
	}
	else
	{
		return max + 1;
	}

}

// Initializes the counter for each score to zero
// Precondition: "scores" must be declared and allocated with length of "size"
// Postcondition: all indices of "scores" initialized to zero
void init_score_count(int scores[], int size)
{
	// for loop initializes all indices of scores to zero	
	for (int count = 0; count < size; count++)
	{
		scores[count] = 0;
	}

}

// Counts the occurrence of each score in the file and stores them in "scores"
// Precondition: indices of "scores" must be initialized to zero,
// and "scores" must have a length of "size", "fin" must be initialized 
// Postcondition: each index is equal to the number of occurrences for that 
// particular score. i.e. if the score 89 appeared 3 times index 89 would
// be equal to 3
void count_scores(int scores[], int size, ifstream &fin)
{
	int curr_score;

	// read priming the first score
	fin >> curr_score;

	// loop determines which index is incremented
	while (fin)
	{
		if ((curr_score > size - 1) || (curr_score <0))
		{
			cout << "Error in data file, discarding value: ";
			cout << curr_score << endl << endl;
		}
		else
		{
			scores[curr_score]++;
		}

		// get the next score
		fin >> curr_score;
	}
}


// Prints the count for each score if greater than zero and then prints the
// average score 
// Precondition: "scores" must have length of "size" be and contain the counts 
// for each score
// Postcondition: Prints each index in "scores" if the count is greater than
// zero and displays the average of the scores. If there aren't scores in the
// file nothing is printed
void print_analysis(int scores[], int size)
{
	int total = 0;
	double sum = 0, average = 0, product = 0;

	// for loop prints test scores/number of time that score was recieved
	for (int count = 0; count <= size - 1; count++)
	{
		if (scores[count] > 0)
		{
			cout << "There were: " << scores[count] << " ";
			cout << count << "'s" << endl;

		}

		product = (scores[count] * count);

		sum += product;
		total += scores[count];

	}
	if (total == 0){
		cout << "There is only one test score" << endl;
	}
	else{
		average = sum / total;
		cout << "The average quiz score is: ";
		cout << setprecision(3) << average << endl;
	}

}
