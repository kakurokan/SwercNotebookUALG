/**
 * Calcula a Transposta de uma matriz.
 * A transposta de uma matriz A é denotada por A^T, onde A^T[j][i] = A[i][j].
 * Referência: Capítulo 23 (Matrices).
 * * @param matrix A matriz original de dimensões M x N.
 * @return Uma nova matriz de dimensões N x M com linhas e colunas trocadas.
 */
public static int[][] transformMatrix(int[][] matrix) {
    // 1. Determinar as dimensões da matriz original.
    int rows = matrix.length;

    // Verifica se a matriz tem linhas para evitar "IndexOutOfBounds" ao acessar matrix[0].
    // Se rows > 0, pegamos o tamanho da primeira linha (número de colunas).
    int cols = rows > 0 ? matrix[0].length : 0;

    // 2. Criar a matriz de resultado (Transposta).
    // IMPORTANTE: As dimensões são invertidas.
    // Se 'matrix' é [rows][cols], 'result' será [cols][rows].
    int[][] result = new int[cols][rows];

    // 3. Iterar pela matriz original e preencher a transposta.
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Lógica da Transposição:
            // O elemento na posição (i, j) da original vai para a posição (j, i) no resultado.
            // Ex: O que estava na linha 0, coluna 2 vai para linha 2, coluna 0.
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}