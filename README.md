# Exercises from The C++ Programming Language

My solutions to [exercises](https://www.stroustrup.com/4thExercises.pdf) from the book.

I discovered the useful clang format tool while doing the last exercise
for chapter 8. Code of exercises prior to that is mostly consistent with
the style appearing in the book.

## List of exercises that require more thinking to solve fully

* Chapter 8 second part of exercise 5: implement ++ and -- operators for the code
  version using `<locale>`
* Chapter 10 exercise 13: convert the mini-compiler written by Bjarne to allow a
  user to define functions; perhaps invent a notation for functions taking parameters
* Chapter 11 exercise 3: make apply function take function object as argument.
* Chapter 12 exercise 6: GNU ed might not have been "a simple C program" that
  exercises 5 and 6 ask to convert to C++. I completed exercise 5, probably.
	Just probably because the program compiles, but tests of the included test
	suite fail.
* Chapter 12 exercise 8: last part not implemented yet ("arbitrarily long word stored
  as an array of characters on free store")
* Chapter 12 exercise 11: use Kasinski analysis, hoping it gives an indication of
  probable key length. Use that to line ciphertext characters to columns, and
  write out one of such columns. Then on the right, write out letters of the alphabet
  starting from that character. Do any of the new columns give a letter frequency that
  corresponds to that of English language? Does that help towards the solution?
* Chapter 12, exercises 16 and 17 (*3-marked). Wanting to move on, I'm passing the
  two exercises for now. Simply because I anticipate they take more effort to complete.
  The reference regarding print function in §12.2.5 is unclear. I could not find it.
  I checked also chapters 11 and 3 for subsections 2.5 (anticipating a one-off error ;),
  but that did not clarify the issue.
* Chapter 13, motivation is more difficult to find as the exercises get more and
  more demanding. The topic of this chapter is clearly very important. This and
  it's exercises might be worth a revisit, when planning for writing a larger
  program.