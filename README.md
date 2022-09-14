# Assignment 1

## Information about the repository

This repository contains the following:
- `points2d.h`

## Parts of program completed

All parts (functions of class Points2D) completed

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
