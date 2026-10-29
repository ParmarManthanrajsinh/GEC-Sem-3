# PBL Activity II — Sorting Algorithm Speed Test Bench

Cross-platform C benchmark that generates random datasets of various sizes
(1000 to 10000) and measures the execution time (in milliseconds) of Bubble,
Insertion, Selection, Merge and Quick sort. Results are written to
`results.csv`, and `generate_report.py` turns them into an Excel chart.

See [`analysis.md`](analysis.md) for the results, complexity comparison and
observations.

## Files

| File | Description |
| ---- | ----------- |
| `sorting_benchmark.c` | Benchmark program (single file, C11) |
| `CMakeLists.txt` | Cross-platform build (Linux, macOS, Windows / MSVC / MinGW) |
| `build.bat` | One-step Windows build script (wraps CMake) |
| `Makefile` | Convenience build for Linux/macOS |
| `generate_report.py` | Builds `results.xlsx` with a comparison chart (needs `openpyxl`) |
| `results.csv`, `results.xlsx` | Generated output (data + Excel chart) |

## Requirements

- A C compiler: `gcc`/`clang` (Linux/macOS) or MSVC/MinGW (Windows)
- **CMake 3.15+** (for the CMake/Windows flow)
- Python 3 with `openpyxl` for the Excel report: `pip install openpyxl`

## Build & Run

### Linux / macOS

Using the Makefile:

```sh
make          # build
make run      # build + run, writes results.csv
make report   # build results.xlsx from results.csv
make clean    # remove build artifacts and generated files
```

Or using CMake:

```sh
cmake -S . -B build
cmake --build build
./build/sorting_benchmark     # writes results.csv
python3 generate_report.py    # writes results.xlsx
```

### Windows

Double-click / run the batch script:

```bat
build.bat
```

Then run the executable it reports, for example:

```bat
build\Release\sorting_benchmark.exe   :: MSVC
build\sorting_benchmark.exe           :: MinGW / Ninja
python generate_report.py
```

Or manually with CMake:

```bat
cmake -S . -B build
cmake --build build --config Release
build\Release\sorting_benchmark.exe
python generate_report.py
```

## Configuration

Benchmark parameters are compile-time constants at the top of
`sorting_benchmark.c`. Edit them and rebuild:

| Constant | Meaning | Default |
| -------- | ------- | ------- |
| `START_SIZE` | Smallest dataset size | `1000` |
| `END_SIZE` | Largest dataset size | `10000` |
| `STEP_SIZE` | Size increment | `1000` |
| `REPETITIONS` | Runs averaged per algorithm | `3` |
| `VALUE_LIMIT` | Upper bound for random values | `1000000` |

A fixed random seed (`12345`) keeps runs comparable. Timings still vary slightly
between machines and runs due to OS scheduling and CPU frequency scaling.

## Adding a New Algorithm

1. Write a function with this signature that sorts `arr[0..n-1]` ascending:

   ```c
   static void heap_sort(int arr[], int n)
   {
       /* ... */
   }
   ```

2. Add one entry to the `algorithms` array in `main()`:

   ```c
   const algorithm_t algorithms[] = {
       {"bubble", bubble_sort},
       {"insertion", insertion_sort},
       {"selection", selection_sort},
       {"merge", merge_sort},
       {"quick", quick_sort},
       {"heap", heap_sort},          /* <-- new */
   };
   ```

The new name automatically appears in the console table, the CSV header and the
Excel chart. Keep names short and comma-free. No other changes are required.
