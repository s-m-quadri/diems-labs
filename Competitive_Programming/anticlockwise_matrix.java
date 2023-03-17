class Main {
    static int[][] buildMatrix(int m, int n) {
        int matrix[][] = new int[m][n];
        int left = 0, top = 0, right = n - 1, bottom = m - 1;
        int count = 1;
        while(left <= right && top <= bottom){
            for(int i = top; i <= bottom; i++) matrix[i][left] = count++;
            left++;
            for(int i = left; i <= right; i++) matrix[bottom][i] = count++;
            bottom--;
            for(int i = bottom; i >= top; i--) matrix[i][right] = count++;
            right--;
            for(int i = right; i >= left; i--) matrix[top][i] = count++;
            top++;
        }
        return matrix;
    }

    static void printMatrix(int[][] matrix){
        for (int[] row: matrix){
            for (int col: row) System.out.printf("%d\t", col);
            System.out.println();
        } 
    }

    public static void main(String args[]) {
        int[][] matrix = buildMatrix(5,5);
        printMatrix(matrix);
    }
}