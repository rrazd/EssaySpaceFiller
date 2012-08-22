EssaySpaceFiller
================

When you run out of ideas and need to fill up space on a long essay, use EssaySpaceFiller and 
choose the accuracy of the randomly generated text.  

<h3>Introduction</h3>
In order to generate the text, I based my algorithm <b>loosely</b> on the Markov model. 
A great book entitled "The Practice of Programming" by Kernighan & Pike has a whole 
chapter detailing how to implement the Markov model to produce plausible output
based on some input text. My method was a bit more 'rough' and you may notice that
even at the highest accuracy order of 20, the output is not plausible enough
to allow the reader to be fooled into passing the generated paragraph off as unsuspicous!

<h3>Lessons learnt</h3>
I realized after finishing the implementation that when using Markov models and
similar analysis for natural language processing one should almost
always apply a tokenizer before analyzing the text itself. This became appratent when
I ran into a problem, where with some files that were not formatted traditionally (ie. they had a lot of spaces 
in between words, then the initial seed was seen to be a space. However, all the next characters 
were seen as spaces as well and so the random text that was generated was just a blank paragraph as 
<code>nextChosenChar</code> variable was always a space. There were ways to circumnavigate this problem, but all of
them were cumbersome and tedious to implement.

<h3>Running the Code</h3>