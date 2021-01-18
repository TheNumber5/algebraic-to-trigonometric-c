This is a simple terminal-only C program (that is pretty bad) that converts complex numbers from their algebraic form to a trigonometric form.

# Instructions

*Convert from file:* `algebraictotrigonometric.exe -f <input file name> <output file name>`
The input file must contain only the real and imaginary parts in order, for example:

`3 1
-1 6
-1.7 2.3
7 -2.44`
Would be 3+i, -1+6i, -1.7+2.3i and 7-2.44i respectively. The output will be in the form: `<Modulus> <Argument>`. For example, converting `1 1` will result `1.414214 0.785398.` The argument is in radians.

*Direct mode via terminal:* `algebraictotrigonometric.exe -d <real part> <imaginary part>`
Needs input like in the file mode. Will output to the console the trigonometric form in `<Modulus> <Argument>`.

*Benchmark (experimental):* `algebraictotrigonometric -b <number of how many complex number to generate and convert>`
This creates n complex numbers in algebraic form and converts them into trigonometric form. This function is only for testing the CPU, the numbers are not printed to the console because this will slow down the process. The time needed for the processing is then displayed in milliseconds.

# TODO
Make the algorithm more efficient, and add organized error-checking for bad input.
