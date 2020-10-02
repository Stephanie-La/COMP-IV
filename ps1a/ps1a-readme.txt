/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Stephanie La
Hours to complete assignment: 5 hours
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
I learned how to build a LFSR with c++ and testing existing code with Boost libraries. 
I also learned how to make a Makefile with flags and targets. Step function simulates one 
step of LFSR and returns to the rightmost bit. The generate function would return a k-bit integer
simulating k steps, where the bit would be doubled and added to the bit returned from step.
I did not use an xor ^ for my step function, but I saved the result between two taps into a variable, 
and then tested if the other taps were equal to the variable.

/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/
No extra credit for ps1a.


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Boost website, discussion board threads, discussion with classmates about possible Makefile flags.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I had a lot of problems with the linkage to boost framework and limited instructions 
on how to set up my targets.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
