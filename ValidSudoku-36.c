bool isValidSudoku(char **board, int boardSize, int *boardColSize) {
  int col[9] = {0};
  int row[9] = {0};
  int block[9] = {0};

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      char c = board[i][j];

      if (c == '.') {
        continue;
      }

      int x = (c - '0') % 9; // convert char to int
      int bitmask = 1 << x; // a set (row or column) can probably 1 to 9 digits:
                            // so we use 9 bit to represent if they are present
                            // or not (based on their position)
                            // e.g: set has 3 and 5: 0000010100

      int blockIndex = (i / 3) * 3 + j / 3;

      if (row[i] >> x & 1 || block[blockIndex] >> x & 1 || col[j] >> x & 1) {
        return 0;
      }

      // Turn on bit represents the present digit. This helps above condition
      // checker detect if the current set is similar to previous set. When
      // repeated on the same row (or col, block) : i(th)
      row[i] |= bitmask;
      col[j] |= bitmask;
      block[blockIndex] |= bitmask;
    }
  }
  return 1;
}
