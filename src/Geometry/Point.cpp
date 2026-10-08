/* ==============================================================================
 * Base de Geometria: Struct Point
 * Operações usam 'long long' para evitar overflow em multiplicações.
 * ==============================================================================
 */
struct Point {
    long long x, y;

    // Subtração de pontos cria um vetor (A -> B = B - A)
    Point operator-(const Point& p) const { return {x - p.x, y - p.y}; }

    // Produto Vetorial (Cross Product): (this X p)
    long long cross(const Point& p) const { return x * p.y - y * p.x; }
};