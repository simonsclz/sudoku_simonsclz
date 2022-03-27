package de.simonsclz.sudoku;

public class Main {

	public static void main(String[] args) {
		Integer[][] grid = {{0, 3, 0, 0, 0, 0, 0, 0, 0},
							{0, 0, 0, 0, 9, 5, 0, 0, 0},
							{0, 0, 8, 0, 0, 0, 0, 6, 0},
							{8, 0, 0, 0, 6, 0, 0, 0, 0},
							{4, 0, 0, 8, 0, 0, 0, 0, 1},
							{0, 0, 0, 0, 2, 0, 0, 0, 0},
							{0, 6, 0, 0, 0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0, 9, 0, 0, 0},
							{0, 0, 0, 0, 0, 0, 0, 7, 0}};
		SudokuSolver solver = new SudokuSolver(grid);
		if(solver.solve()) {
			for(int row = 0; row < 9; row++) {
				for(int col = 0; col < 9; col++) {
					System.out.print(grid[row][col] + " ");
				}
				System.out.println();
			}
		}
	}
}
