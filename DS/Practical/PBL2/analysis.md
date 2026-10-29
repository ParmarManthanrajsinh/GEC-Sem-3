### PBL Activity II — Sorting Algorithm Speed Test Bench

**Subject:** Data Structure (BE03000081) &nbsp;•&nbsp; **Semester:** 3 (Odd 2026-27)

**Task:** Build a C program that generates datasets of various sizes (1000 to 10000) and measures the execution time (in ms) for Bubble Sort, Insertion Sort, Selection Sort, Merge Sort and Quick Sort, then plot the results in Excel.

---

#### 1. Objective

Measure and compare the practical running time of five classic sorting algorithms on
randomly generated integer datasets, and verify how the measured growth matches the
theoretical time complexity.

#### 2. Experimental Setup

| Item | Value |
| ---- | ----- |
| Language | C (C11) |
| Compiler | `gcc -O2 -std=c11 -Wall -Wextra` |
| Dataset sizes | 1000, 2000, ... 10000 (step 1000) |
| Data distribution | Random integers in `[0, 1000000)` |
| Random seed | 12345 (fixed, reproducible) |
| Repetitions | 3 runs per algorithm per size (average reported) |
| Timer | `clock_gettime(CLOCK_MONOTONIC)` (millisecond resolution) |
| Fairness | Every algorithm sorts a **fresh copy of the same dataset** |

#### 3. Measured Results (time in milliseconds)

| Size | Bubble | Insertion | Selection | Merge | Quick |
| ---: | -----: | --------: | --------: | ----: | ----: |
| 1000 | 1.677 | 0.111 | 1.116 | 0.049 | 0.033 |
| 2000 | 6.651 | 0.426 | 4.396 | 0.101 | 0.073 |
| 3000 | 14.972 | 0.938 | 10.124 | 0.168 | 0.118 |
| 4000 | 26.654 | 1.623 | 17.721 | 0.256 | 0.176 |
| 5000 | 41.706 | 2.516 | 27.718 | 0.293 | 0.196 |
| 6000 | 60.315 | 4.244 | 40.421 | 0.338 | 0.248 |
| 7000 | 83.867 | 5.048 | 54.722 | 0.459 | 0.339 |
| 8000 | 110.108 | 6.404 | 71.295 | 0.454 | 0.325 |
| 9000 | 141.069 | 8.214 | 90.223 | 0.519 | 0.386 |
| 10000 | 177.499 | 10.411 | 111.315 | 0.587 | 0.425 |

The corresponding line chart (X-axis = dataset size, Y-axis = time in ms, one series
per algorithm) is generated inside `results.xlsx` on the **Timings** sheet.

#### 4. Theoretical vs. Observed Complexity

| Algorithm | Best | Average | Worst | Space | Observed trend |
| --------- | ---- | ------- | ----- | ----- | -------------- |
| Bubble | O(n) | O(n^2) | O(n^2) | O(1) | Quadratic growth |
| Insertion | O(n) | O(n^2) | O(n^2) | O(1) | Quadratic growth, small constant |
| Selection | O(n^2) | O(n^2) | O(n^2) | O(1) | Quadratic growth |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) | Near-linear growth |
| Quick | O(n log n) | O(n log n) | O(n^2) | O(log n) | Near-linear growth |

#### 5. Observations

1. **Two clear groups.** On random data the O(n^2) algorithms (Bubble, Insertion,
   Selection) are orders of magnitude slower than the O(n log n) algorithms
   (Merge, Quick). At n = 10000, Bubble takes ~177 ms while Quick takes ~0.43 ms —
   roughly **420x faster**.
2. **Growth rate.** From n = 1000 to n = 10000 (10x the input), Bubble, Insertion and
   Selection grow by roughly **95-105x**, matching the quadratic curve, whereas Merge
   and Quick grow only about **12-13x**, matching the `n log n` behaviour
   (10 * log 10000 / log 1000 ≈ 13.3x).
3. **Insertion Sort on random data.** Insertion Sort is consistently much faster than
   Bubble and Selection Sort (e.g. ~10 ms vs ~177 ms vs ~111 ms at n = 10000). This is
   due to its tight inner loop, early termination of the shift, and better cache
   locality — despite sharing the same O(n^2) average complexity.
4. **Merge vs Quick.** Both are close; Merge Sort is limited by its extra O(n) buffer
   and data movement, while Quick Sort performs better in-place. The two stay within a
   small factor of each other, consistent with their similar `n log n` cost.
5. **Measurement noise.** Individual runs show small jitter caused by OS scheduling,
   CPU frequency scaling and cache effects. Averaging several repetitions (3 here)
   and using a fixed random seed keeps the comparison stable and reproducible.

#### 6. Conclusion

The experiment confirms the theoretical prediction: for random datasets, algorithm
complexity dominates performance. Quadratically-growing algorithms become impractical
as the input grows, while divide-and-conquer algorithms (Merge and Quick Sort) scale
gracefully. Among the elementary algorithms, Insertion Sort performed best in practice.

#### 7. How to Reproduce

```bash
cd DS/Practical/PBL2
make run       # builds, runs the benchmark, writes results.csv
pip install openpyxl   # one time only
make report    # builds results.xlsx with the comparison chart
```
