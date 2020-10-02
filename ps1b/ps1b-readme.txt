/**********************************************************************
 *  Linear Feedback Shift Register (part B) ps1b-readme.txt template
 **********************************************************************/

Name: Stephanie La

Hours to complete assignment: 6
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
In the transform function, it takes two arguments, an image object and a 
FibLFSR object. After finding the size, each pixel was xor'ed by the 
bit->generate function(8), shifting each bit 8 times. Each pixel was then
set encrypted. The main function reads four arguments from the command line:
the executable name, the source image, and the LFSR seed. I assigned each
part of the argv[] array to each order of the commands. They were executed
in the order they were given. At the end, the encoded and decoded images 
are displayed in its own windows.



/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/
n/a



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Used Youtube, Stack Overflow, Geeks for Geeks, SFML website for references 
and tutorials on how to implement SFML functions and command lines.



/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I think implementing accepting command line arguments was the hardest 
part of the assignment.I didn't really learn about the background in the 
main function and its parameters, so I had to use a lot or resources to 
help me understand what it was about.It is highly preferrable to atach a 
link to what the main function is about.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
In the instructions, it was not asked to also pass in the orignal image 
I used to encrypt. However, I have the two screenshots proving the encryption 
and decryption process of the image(It was required to pass these two in).
Let me know if you need the orignal png as well.
