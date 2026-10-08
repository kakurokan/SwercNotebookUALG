/* ==============================================================================
 * Área de Polígono (Shoelace Formula)
 * Os pontos devem estar ordenados (horário ou anti-horário).
 * Retorna o dobro da área (para manter sempre em inteiros).
 * Se precisarem da área real, dividam por 2.0 no fim.
 * ==============================================================================
 */
long long polygon_area_x2(const vector<Point>& poly) {
    long long area = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        // poly[i] cruza com o vértice seguinte (fazendo wrap-around para 0)
        area += poly[i].cross(poly[(i + 1) % n]);
    }
    return abs(area);  // A área real é abs(area) / 2.0
}