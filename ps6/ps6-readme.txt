/**********************************************************************
 *  readme.txt template                                                   
 *  PS6 Kronos 
 **********************************************************************/

Name: Stephanie La


Hours to complete assignment: 7


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I successfully completed the assignment where I was able to print the
files with the start boot time, boot time, and end boot time. 


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
 boost::regex start_boot("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2}) " 
"([0-9]++):([0-9]++):([0-9]++)" "(.*log.c.166.*)");

- [0-9]{4}: looking for 4 numbers from 0-9
- [0-9]{1,2}: looking for one or two numbers from 0-9
- [0-9]++: looking for numbers between 0-9 and + checks for more than 1 number
- (.*log.c.166.*): looking for the matching string

The first regex was looking for the start up message, where the date and time
would have to follow the format. log.c.166 was important since it was needed as 
the start up message

boost::regex end_boot("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2})" "([0-9]++)
:([0-9]++):([0-9]++)" "(.*oejs.AbstractConnector:Started 
SelectChannelConnector.*)");

- [0-9]{4}: looking for 4 numbers from 0-9
- [0-9]{1,2}: looking for one or two numbers from 0-9
- [0-9]++: looking for numbers between 0-9 and + checks for more than 1 number
- (.*oejs.AbstractConnector:Started SelectChannelConnector.*): looking for 
matching string to complete a boot

The second regex was supposed to be indicating if the startup was a success.
The date and time would have to follow the same format it did like in the
first regex.

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
My approach for solving this problem started when I had to figure out
how regular expressions worked and how to figure out the format to group
a couple of numbers together. After learning how to read regex, I just
needed to parse the log files, store and compare the lines the regex,
and then write the output through the output file. I set up the file
streams for tested the input and output files at first. I then had to 
figure out how regex_match worked and it had to be the entire line 
it had to match. The program would output whether it was booted up
successfully or not.

/**********************************************************************
 *  Did you use lambda expression? If yes describe there.
 **********************************************************************/
I did use a lambda.
 auto open_file = [&](string n) { outputFile.open(outFile.c_str()); };
    open_file(outFile.c_str());

lambda automatically opens an outfile for output.

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
I was told that I was missing a library and I needed to include it in my
Makefile to make my program work.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
One problem I encountered was that I never realized I had to use a 


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A

