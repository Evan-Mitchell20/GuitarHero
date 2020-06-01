/**********************************************************************
 *  readme.txt template                                                   
 *  Guitar Hero: GuitarString implementation and SFML audio output 
 **********************************************************************/

Name: Evan Mitchell
CS Login: emitchel


Hours to complete assignment : 6

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I believe I completed the whole assignment successfully.
When I press on the keyboard while running the program, music plays.
I tested to make sure they played at different frequencies and that all keys
worked. In addition, I did use exceptions and they actually helped me debug my program,
since they were thrown while testing.


/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  As a pair, or individually?
 *  If you completed the AutoGuitar, what does it play?
 **********************************************************************/
I did not complete anty extra credit parts.

/**********************************************************************
 *  Does your GuitarString implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes, it passes the unit tests. I know because I ran the unit tests
using my GuitarString implementation with the resulting output:

emitchel@dan416-05:~/Evan_Mitchell_ps5b$ ./GuitarHero
Running 1 test case...

*** No errors detected
emitchel@dan416-05:~/Evan_Mitchell_ps5b$ 

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
None


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
None

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Good assignment, I learned a lot about sfml and how to use the audio features.
In addition, I learned how to make my code more generic since my first
instinct was to use a large switch statement, but using a vector turned out to be a much
better approach.

Time and Space complexity: My ring buffer should be good at inserting into the back, but dequeueing
might be an expensive operation. The Space performance should be similar to that of a standard array.
