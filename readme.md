Advanced Algorithms Assessment 1

AUTHOR

    Ethan Leet
    s5223103


ABOUT

    This assignmnet involved writting c++ code to solve five advanced algorithm problems. As well as submitting c++ source code, a detailed report was to be included which derives the efficiency and proves the validity of each problem, test cases and experiements are also included. Question five required a more in depth analysis compared to the other four programs, and its details are listed within the report.

Compiling

    Each program was compiled using clang++ and the c++ standard library 14 without errors nor warnings. Makefiles are used to compile each question and the project as a whole. Running the 'make' command in the question folder will compile that question with all its dependencies whereas executing the make command from the parent folder will compile all five problems in this submission and place the binaries in the respective question folder.
    
    If make is not available please check the respective questions makefile to extract the command used to compile individual programs with their respective binaries.

    After compilation, the below commands can be executed from the question folder:


Question 1 

    This question requires a list of long integers to be passed. The first item in the list should be k, the number of smallest integers you wish to keep seperate. The following integers are the entire list.

    To run this program the following command can be executed:

    ./a.out file.txt

   Two sample text files are attached to this submission. A gen_list.cpp file is included which will create a list of 10,000 random long integers and set k to 100.


Question 2

    This question requires two command line arguments to be passed. The length and width of the maze.

    To run this program with a length of 55 and width of 100 the following command can be executed:

    ./a.out 55 100


Question 3

    This question requires no command line arguments. The test case functions inside main.cpp can be changed to test any number of integers you would like.


Question 4

    This question requires no command line argumenets. The main function is segmented into three parts; 1, 2 and 3 which represent the testing of each of the three bacon files. Actor names are coded on lines 26, 67, 106 and 107.

    The program expects three text files (attached to this submission) to be present. If you would like to change the text files used they must be in the same format. The strings on line 10 can then be updated with the file you wish to test.


Question 5

    This question requires the eight compliment graphs included in this submission to be present. The program requires a command line argument to be passed which is the target vertex cover.

    Algorithm and Graph execution decisions are decided during rune time, and can be chosen by entering a choice during run time.
