# Assignment 1

## Information about the repository

This repository contains the following:
- `points2d.h`

## Parts of program completed

All parts (functions of class Points2D) completed.
- Default constructor: set member variable size_ to 0.
- Copy constructor: copy size_ variable from the given object and uses a for loop to copy all elements to a newly allocated array for sequence_ member variable.
- Copy assignment: utilizes copy constructor to create an exact copy of supplied object parameter and uses std::swap to swap the current object being created with the copied object.
- Move constructor: shallow copies supplied temporary object parameter and sets supplied object to default version of Points2D.
- Move assignment: transfers temporary supplied object parameter to left side of = operator.
- Destructor: deallocates sequence_ using delete[] and sets it to nullptr if size_ member variable is not 0.
- One parameter constructor: takes an array of size 2 (represents 2D point) and puts it into sequence_ member variable after allocating it with size 1.
- size accessor: returns size_ member variable, does not modify member variables.
- operator[]: checks if supplied location value is within the existing sequence_ member variable of the Points2D object. If it is, returns a reference to the array (not the element stored, but the array). If it isn't, throws an error and aborts the program.
- operator+: decides which Points2D sequence is smaller and utilizes its size_ member variable to add the two sequences up until that point. Then appends the rest of the 2d points of the bigger sequence. If they are the same size, skips the second step.
- operator<<: if the Points2D sequence is empty, outputs an empty point "()" to the terminal, if not empty, outputs them in the output format: "(0, 1) (2, 3) (4, 5)...". Spaces are only between points, no leading or trailing spaces.
- operator>>: takes the first number from the input stream to determine the amount of 2d points added to the sequence of the reference object some_points. The numbers following are paired into (x, y) points to be added to the sequence. If the Points2D object supplied isn't empty, reallocation of memory takes place to fit the 2d points into the sequence, as well as keeping the points already present in the sequence. Error handling utilizes the istream functions ".fail()" and ".eof()" to determine if invalid characters are detected in the input stream or if the input stream doesn't contain the necessary numbers to meet the 2d points quota as the first number of the input stream dictates.

## Bugs encountered

I'm not certain if it is a bug, but gradescope Test2b failed and Test3 partially failed.
I think it may be an error handling problem for the overloaded operator[].
`Fall22-Assignment1.pdf` specified to use abort() function for all errors after printing "ERROR" in the cerr stream.
Linux lab computers successfully prints "ERROR" and so does my windows computer, but gradescope doesn't print "ERROR".
Whatever the case, the program stops as intended for Test2b and Test3.

## Input file

`test_input_file.txt`

## Output file

`expected_output.txt`

## Running the assignment

Use provided `Makefile`

To compile on terminal, type:

```bash
make clean
make all
```

To delete executables and object files, type:

```bash
make clean
```

To run, type:

```bash
./test_points2d
```

## Providing Input from Standard Input

To run with a given file that is redirected to standard input:

```bash
./test_points2d < test_input_file.txt
```
