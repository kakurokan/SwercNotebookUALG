/* 
 * Area de Poligono (Shoelace Formula)
 * Os pontos devem estar ordenados (horario ou anti-horario).
 * Retorna o dobro da area (para manter sempre em inteiros).
 * Se precisarem da area real, dividam por 2.0 no fim.
 */
long long polygon_area_x2(const vector<Point>& poly) {
    long long area = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        // poly[i] cruza com o vertice seguinte (fazendo wrap-around para 0)
        area += poly[i].cross(poly[(i + 1) % n]);
    }
    return abs(area);  // A area real e abs(area) / 2.0
}
