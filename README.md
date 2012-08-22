EssaySpaceFiller
================

When you run out of ideas and need to fill up space on a long essay, use EssaySpaceFiller and 
choose the accuracy of the randomly generated text.  

In order to generate the text, I based my algorithm loosely on the Markov model. 
A great book entitled "The Practice of Programming" by Kernighan & Pike has a whole 
chapter detailing how to implement the Markov model to produce plausible output
based on some input text. My method was a bit more 'rough' and you may notice that
even at the highest accuracy order of 20, the output is not plausible enough
to allow the reader to be fooled into passing the generated paragraph as unsuspicous!

I realized after finishing the implementation that 