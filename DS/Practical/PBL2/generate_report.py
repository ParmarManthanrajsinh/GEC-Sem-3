#!/usr/bin/env python3
"""Build results.xlsx (with a comparison chart) from results.csv.

Usage:
    python3 generate_report.py [input.csv] [output.xlsx]

Run from the PBL2 folder. On Windows use `python` instead of `python3`.
Requires openpyxl:  pip install openpyxl
"""

import csv
import sys
from pathlib import Path

try:
    from openpyxl import Workbook
    from openpyxl.chart import LineChart, Reference, Series
except ImportError:
    sys.exit("openpyxl is required. Install it with: pip install openpyxl")

CSV_FILE = Path("results.csv")
XLSX_FILE = Path("results.xlsx")


def read_results(path):
    if not path.exists():
        sys.exit(
            f"{path} not found. Run the benchmark first "
            "(`make run`, or the compiled executable / `build.bat`)."
        )

    with path.open(newline="") as handle:
        rows = list(csv.reader(handle))

    if len(rows) < 2:
        sys.exit(f"{path} does not contain any data rows.")

    header = rows[0]
    data = [[float(value) for value in row] for row in rows[1:]]
    return header, data


def build_workbook(header, data, output):
    workbook = Workbook()
    sheet = workbook.active
    sheet.title = "Timings"

    sheet.append(header)
    for row in data:
        sheet.append(row)

    chart = LineChart()
    chart.title = "Sorting Algorithm Speed Test Bench"
    chart.style = 12
    chart.x_axis.title = "Dataset size (elements)"
    chart.y_axis.title = "Time (ms)"
    chart.height = 12
    chart.width = 24

    row_count = len(data) + 1
    column_count = len(header)

    categories = Reference(sheet, min_col=1, min_row=2, max_row=row_count)
    for column in range(2, column_count + 1):
        values = Reference(sheet, min_col=column, min_row=1, max_row=row_count)
        chart.series.append(Series(values, title_from_data=True))

    chart.set_categories(categories)
    sheet.add_chart(chart, "H2")

    workbook.save(output)


def main():
    csv_file = Path(sys.argv[1]) if len(sys.argv) > 1 else CSV_FILE
    xlsx_file = Path(sys.argv[2]) if len(sys.argv) > 2 else XLSX_FILE

    header, data = read_results(csv_file)
    build_workbook(header, data, xlsx_file)
    print(f"Report written to {xlsx_file} ({len(data)} data rows).")


if __name__ == "__main__":
    main()
