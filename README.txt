Sasha Morgan
12/1

/**
* @file <hw7.cpp>
* <Debugging assignment
* @author <Sasha Morgan, sasha97>
* @date   <December 1st, 2015>
*
* Virginia Tech Honor Code Pledge
* On my honor:
*
* - I have not discussed the C++ language code in my program with
* anyone other than my instructor or the teaching assistants
* assigned to this course.
* - I have not used C++ language code obtained from another student,
* or any other unauthorized source, either modified or unmodified.
* - If any C++ language code or documentation used in my program
* was obtained from another source, such as a text book of coarse
* notes, that has been clearly noted with a proper citation in
* the comments of my program.
* - I have not designed this program in such a way as to defeat or
* interfere with the normal operation of the Web-Cat Server.
*
* <Sasha Morgan>
*/
Bugs:

1. The first error is in the int get_max_score, in order to get the maximum score you have to add another number, so that the array is read correctly.
   To fix the error when 'return max' placed the return max; in the if(fin.fail()){ max = -1; return max;} and added an else portion to update the variable when the argument is true: else{return max+1;}
2. if(curr_score > 10) ll (curr_score < 0) is incorrect and gives you a bunch of error messages, because there can be instances where there is more than ten value, so change 10 to size-1 which will access the array.
3. for(int count = 0; count < size; count++){...}, the size alone gives you a heap error because the memory access more data than the array holds, so I changed size to size-1 which fixes this problem and added an equal sign to account for situations where count is equal to the size.
4. if(scores[count] >= 0), score[count] the equal sign is simply unneccessary, you would not display something if there are no numbers.  To fix the problem I removed the equal sign.
5. average = sum / total;cout << "The average quiz score is: "; 
cout << setprecision(3)  << average << endl; does not happen in every single situation, which is an error when the program only has one value.  To fix the problem I created an ifelse statement with a true and a false condition.
		if (total == 0){
		cout << "There is only one test score" << endl;
	}
	else{
		average = sum / total;
		cout << "The average quiz score is: ";
		cout << setprecision(3) << average << endl;
	}