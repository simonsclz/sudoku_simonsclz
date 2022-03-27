package de.simonsclz.sudoku;

public class SudokuSolver {
	
	private Integer[][] grid;
	
	public SudokuSolver(Integer[][] grid) {
		this.grid = grid;
	}

	public boolean solve() {
		if(isFilled()) {
			return true;
		}
		for(int row = 0; row < 9; row++) {
			for(int col = 0; col < 9; col++) {
				if(grid[row][col] == 0) {
					for(int number = 1; number < 10; number++) {
						grid[row][col] = number;
						if(checkRow(row, number) && checkCol(col, number) && checkSquare(row, col, number) && solve()) {
							return true;
						} else {
							grid[row][col] = 0;
						}
					}
					return false;
				}
			}
		}
		return false;
	}
	
	private boolean isFilled() {
		boolean filled = true;
		for(int row = 0; row < 9; row++) {
			for(int col = 0; col < 9; col++) {
				if(grid[row][col] == 0)  {
					filled = false;
				}
			}
		}
		if(filled) {
			return true;
		}
		return false;
	}
	
	public boolean checkRow(int rowNumber, int number) {
		int counter = 0;
		for(int col = 0; col < 9; col++) {
			if(grid[rowNumber][col] == number) counter++;
		}
		if(counter <= 1) return true;
		return false;
	}

	public boolean checkCol(int colNumber, int number) {
		int counter = 0;
		for(int row = 0; row < 9; row++) {
			if(grid[row][colNumber] == number) counter++;
		}
		if(counter <= 1) return true;
		return false;
	}
	
	public boolean checkSquare(int rowNumber, int colNumber, int number) {
		int counter = 0;
		int rowStart = (int)(rowNumber / 3) * 3;
		int colStart = (int)(colNumber / 3) * 3;
		for(int row = rowStart; row < rowStart + 3; row++) {
			for(int col = colStart; col < colStart + 3; col++) {
				if(grid[row][col] == number) counter++;
			}
		}
		if(counter <= 1) return true;
		return false;
	}
	
}
