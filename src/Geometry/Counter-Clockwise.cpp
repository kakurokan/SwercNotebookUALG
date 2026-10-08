/* ==============================================================================
 * Teste de Orientação
 * Retorna:
 *  1 se C está à esquerda de AB (Curva à esquerda)
 * -1 se C está à direita de AB (Curva à direita)
 *  0 se A, B e C são colineares
 * ==============================================================================
 */
int orientation(Point a, Point b, Point c) {
    long long val = (b - a).cross(c - a);
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}