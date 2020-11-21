/**********************************************************************
 *  readme 
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Stephanie La

Hours to complete assignment: 9

/**********************************************************************
 * Explain which approach you decided to use when implementing
 * (either recursive with memoization, recursive without memoization,
 * dynamic programming or Hirschberg’s algorithm). Also describe why
 * you chose this approach and what its pros and cons are.
 **********************************************************************/
I used dynamic programming as my implementation to write my program.

I chose this approach because since we have to fill a table, I needed to 
break it down into smaller problems, where I would fill out the outer 
column first with gap penalties, and then fill the insides. I get to 
store the results of the subproblems from another function and use them
for another part of the program. The pros of using dynamic programming is 
that you can use it to work on multi-step programs and save results
so other sub problems can resue them to solve the original problem.
This avoids recomputing the same quantity over and over again. The
Needleman and Wunsch method provides good time and memory complexity,
and a multilinear time complexity O(mn). The cons of this method is 
really that it just a lot of memory is used because we divide problems 
into subproblems. 

/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input:  valgrind ./ED < sequence/endgaps7.txt

atattat
tattata



Expected output:Edit distance = 4
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2

What happened:
Edit distance = 4
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2

Execution time is 0.101348 seconds

/**********************************************************************
 * Look at your computer’s specs in the settings. 
 * How much RAM does your computer have and explain what this means? 
 **********************************************************************/
I have 8 GB of ram on my computer. RAM stands for random access memory,
and it is storage your computer uses to hold short term data. If I have
8 Gb of RAM, it means I can hold up to 8 GB of RAM in my computer. RAM 
is used to hold variables like the matrix and the more memory you have 
the larger strings you could process.

/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 4
b = 2
largest N = 44721

4*n^2=8b
n^2 = 2b
v2b = 44721.35
= 44721

/**********************************************************************
 * Run valgrind if you can and attach the output file to your submission. 
 * If you cannot run it, explain why, and list all errors you’re seeing. 
 * If you can run it successfully, does the memory usage nearly match that 
 * found in the question above? 
 * Explain why or why not. 
/**********************************************************************

--------------------------------------------------------------------------------
Command:            ./ED
Massif arguments:   (none)
ms_print arguments: massif.out.147
--------------------------------------------------------------------------------


    MB
24.13^                                                                       :
     |              ########################################################::
     |             :#                                                       ::
     |             :#                                                       ::
     |            @:#                                                       ::
     |           @@:#                                                       ::
     |           @@:#                                                       ::
     |          :@@:#                                                       ::
     |         :@@@:#                                                       ::
     |         :@@@:#                                                       ::
     |        ::@@@:#                                                       ::
     |       :::@@@:#                                                       ::
     |       @::@@@:#                                                       ::
     |      :@::@@@:#                                                       ::
     |     ::@::@@@:#                                                       ::
     |     ::@::@@@:#                                                       ::
     |    :::@::@@@:#                                                       ::
     |   @:::@::@@@:#                                                       ::
     |   @:::@::@@@: #                                                       ::
     |  :@:::@::@@@:#                                                       ::
   0 +----------------------------------------------------------------------->Mi
     0                                                                   131.4

Number of snapshots: 92
 Detailed snapshots: [4, 16, 33, 51, 61, 68, 78, 85 (peak)]

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
  0              0                0                0             0            0
  1      2,460,075           72,712           72,704             8            0
  2      2,726,580           78,760           78,721            39            0
  3      3,096,589           82,624           82,562            62            0
  4      3,423,411          161,440          161,178           262            0

The memory usage does match since the higher the N, the more bytes are used.


/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt		118		0.02		25.43
ecoli5000.txt		160		0.138		100.79
ecoli7000.txt		194		0.279		196.83
ecoli10000.txt		223		0.620		401.51
ecoli20000.txt		3135		1.923		1602.94
ecoli28284.txt		8394		4.651		3302.88




/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 5.52e-9
b = 2
largest N = 3,956,283

I guessed based on previous ecoli files that the that total runtime was 
doubling for each test.
**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where 
 * (describe a method or provide a lines numbers)
 **********************************************************************/
I did use a lambda in the assignment, on lines 15 and 19.

// lambda
	auto return_push = [&](int n) { temp.push_back(0); };

	// fill matrix with 0's
	for (unsigned j = 0; j < two.length() + 1; j++) {
		return_push(0);
		//temp.push_back(0);
	}



**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/
Geeks for Geeks reference, google definitions, valgrind website.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I think overall, the assignment was very long, and a lot more time is 
needed to work on it.

When using Cpplint, I had header problems with EditDistance.h. Because 
I am using WSL, cpplint thinks my directory should be #include 
"/home/slaw/ps4/EditDistance.h" but it's not since no one else would 
have access to my directory, so it should be #include "EditDistance.h".
I put #include "/home/slaw/ps4/EditDistance.h" // NOLINT commented out 
for convenience. 

Also for EditDistance.h, I had to put // NOLINT guards so I would not get
the same header errors that wold tell me to use a #ifndef and #define from 
my own directory. 

#include <algorithm> // NOLINT was also an error Cpplint gave because of
min(), but it wasn't part of that directive because I was supposed to write 
it myself as part of the assignment, so I put // NOLINT.


Let me know if these were problems.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

