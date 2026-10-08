/* ==============================================================================
 * Intersecção de Segmentos (Simples)
 * Verifica se os segmentos AB e CD se cruzam (exclui casos de colinearidade).
 * ==============================================================================
 */
bool segments_intersect(Point a, Point b, Point c, Point d) {
    int o1 = orientation(a, b, c);
    int o2 = orientation(a, b, d);
    int o3 = orientation(c, d, a);
    int o4 = orientation(c, d, b);

    // Se as orientações forem opostas, há intersecção
    return (o1 != o2) && (o3 != o4);
}