# sudoku.py
# 1st of January 2022


def main() -> None:
    grid: list = [[0, 0, 0, 8, 0, 5, 0, 1, 3],
                  [9, 0, 5, 2, 0, 3, 6, 0, 0],
                  [6, 0, 3, 0, 9, 0, 2, 0, 4],
                  [0, 0, 1, 0, 0, 0, 0, 0, 5],
                  [0, 4, 0, 1, 0, 0, 7, 0, 6],
                  [2, 5, 6, 3, 0, 4, 8, 9, 0],
                  [5, 9, 0, 0, 0, 7, 1, 0, 2],
                  [1, 0, 2, 0, 8, 0, 4, 7, 0],
                  [0, 0, 4, 9, 1, 0, 0, 3, 8]]
    if solve(grid):
        for row in grid:
            print(row)
    else:
        print("Sorry. No solution found.")


def solve(grid: list) -> bool:
    count_zeros: int = 0
    for row in range(9):
        for col in range(9):
            if grid[row][col] == 0:
                count_zeros += 1
    if count_zeros == 0:
        return True
    for row in range(9):
        for col in range(9):
            if grid[row][col] == 0:
                for value in range(1, 10):
                    grid[row][col] = value
                    if is_valid(grid, value, row, col) and solve(grid):
                        return True
                    else:
                        grid[row][col] = 0
                return False
    return False


def is_valid(grid: list, value: int, row: int, col: int) -> bool:
    if same_column(grid, value, col) or same_row(grid, value, row) or same_square(grid, value, row, col):
        return False
    return True


def same_column(grid: list, value: int, col: int) -> bool:
    counter: int = 0
    for row in range(9):
        if grid[row][col] == value:
            counter += 1
    if counter < 2:
        return False
    return True


def same_row(grid: list, value: int, row: int) -> bool:
    counter: int = 0
    for col in range(9):
        if grid[row][col] == value:
            counter += 1
    if counter < 2:
        return False
    return True


def same_square(grid: list, value: int, row: int, col: int) -> bool:
    row_start: int = (row // 3) * 3
    col_start: int = (col // 3) * 3
    counter: int = 0
    for row_counter in range(row_start, row_start + 3):
        for col_counter in range(col_start, col_start + 3):
            if grid[row_counter][col_counter] == value:
                counter += 1
    if counter < 2:
        return False
    return True


main()
