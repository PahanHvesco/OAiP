int** createMatrix(int row, int col);
void randMatrix(int** Matrix, int row, int col);
void printMatrix(int** Matrix, int row, int col);
void coppyCol(int** Matrix, int col, int row1, int row2);
void coppyRow(int** Matrix, int row, int col1, int col2);
int sumRow(int** Matrix, int sum_row, int col);
int sumCol(int** Matrix, int row, int sum_col);
void deleteIndexRow(int** Matrix, int row, int* col, int IndexCol);
void deleteIndexCol(int** Matrix, int* row, int col, int IndexRow);
