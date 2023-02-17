# Lakelon Bailey - Project 2: Sorting List-Based Strings and Numbers (02/16/2023)
## Benchmarks
- Method: I developed a python script that develops the input files, compiles the program, and then uses the subprocess and time modules to time the C++ sorting algorithms through dymanically generated shell commands. For all of these sorting algorithms, I included the -n flag to require them all to sort numerically.
- Results:
    |   Mode   |   Size   | Elapsed Time  |
    | -------- | -------- | ------------- |
    |   STL    | 1.00e+01 |    0.0046     |
    |   STL    | 1.00e+02 |    0.0033     |
    |   STL    | 1.00e+03 |    0.0036     |
    |   STL    | 1.00e+04 |    0.0075     |
    |   STL    | 1.00e+05 |    0.0490     |
    |   STL    | 1.00e+06 |    0.5459     |
    |   STL    | 1.00e+07 |    3.2023     |
    |  QSORT   | 1.00e+01 |    0.0050     |
    |  QSORT   | 1.00e+02 |    0.0035     |
    |  QSORT   | 1.00e+03 |    0.0035     |
    |  QSORT   | 1.00e+04 |    0.0075     |
    |  QSORT   | 1.00e+05 |    0.0468     |
    |  QSORT   | 1.00e+06 |    0.5152     |
    |  QSORT   | 1.00e+07 |    3.2027     |
    |  MERGE   | 1.00e+01 |    0.0129     |
    |  MERGE   | 1.00e+02 |    0.0036     |
    |  MERGE   | 1.00e+03 |    0.0042     |
    |  MERGE   | 1.00e+04 |    0.0122     |
    |  MERGE   | 1.00e+05 |    0.0548     |
    |  MERGE   | 1.00e+06 |    0.7323     |
    |  MERGE   | 1.00e+07 |    15.1557    |
    |  QUICK   | 1.00e+01 |    0.0047     |
    |  QUICK   | 1.00e+02 |    0.0034     |
    |  QUICK   | 1.00e+03 |    0.0039     |
    |  QUICK   | 1.00e+04 |    0.0080     |
    |  QUICK   | 1.00e+05 |    0.0602     |
    |  QUICK   | 1.00e+06 |    1.3782     |
    |  QUICK   | 1.00e+07 |    54.3701    |

## Questions
1. **Question: Discuss the relative performance of each sorting method and try to explain the differences.**
    - **Answer:** The performance ranking of these sorting algorithms, in terms of speed alone, follows their top to bottom position in the above graph. STL and QSORT are very similar in speed, while MERGE is significantly slower and QUICK is by far the slowest. My theory is that the first two are faster because they are interacting with a lighter data structure: a basic array. Merge sort is likely faster than quick sort due to its better worst case scenario in terms of time complexity (quick sort pivot point could be bad).
2. **Question: What do these results reveal about the relationship between theoretical complexity discussed in class and actual performance?**
    - **Answer:** These results reveal that complexity is not the only factor that determines ultimate performance, as the size of data structures as well as potentially unlucky worst-case scenarios could arise throughout the more complicated algorithms.
3. **Question: In your opinion, which sorting mode is the best? Justify your conclusion by examining the trade-offs for the chosen mode**
    - **Answer:** In my opinion, merge sort is the best. It is a stable sorting algorithm that is both simple to read/understand as well as theoretically one of the fastest sorting algorithms. This algorithm can also be easily applied to many different types of linked items, therefore being less rigid in nature than STL/QSORT. In this context, however, there is a tradeoff of it being slower, but I do not see how this comparison would stand in a production sense in which the theoretical time complexities may be more prevalent.

## Summary of Group Members:
- I decided to work alone for this project, so the work was solely completed by me.