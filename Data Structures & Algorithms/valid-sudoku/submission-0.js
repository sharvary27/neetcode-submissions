class Solution {
    /**
     * @param {character[][]} board
     * @return {boolean}
     */
 isValidSudoku(board) {
  // Check rows
  for (let i = 0; i < 9; i++) {
    const seen = new Set();
    for (let j = 0; j < 9; j++) {
      const val = board[i][j];
      if (val !== '.') {
        if (seen.has(val)) return false;
        seen.add(val);
      }
    }
  }

  // Check columns
  for (let j = 0; j < 9; j++) {
    const seen = new Set();
    for (let i = 0; i < 9; i++) {
      const val = board[i][j];
      if (val !== '.') {
        if (seen.has(val)) return false;
        seen.add(val);
      }
    }
  }

  // Check 3x3 sub-boxes
  for (let boxRow = 0; boxRow < 9; boxRow += 3) {
    for (let boxCol = 0; boxCol < 9; boxCol += 3) {
      const seen = new Set();
      for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
          const val = board[boxRow + i][boxCol + j];
          if (val !== '.') {
            if (seen.has(val)) return false;
            seen.add(val);
          }
        }
      }
    }
  }

  return true; // No duplicates found, valid Sudoku
}

}
