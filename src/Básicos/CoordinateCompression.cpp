/* ==============================================================================
 * Algoritmo: Coordinate Compression
 * Descrição: Mapeia valores esparsos [10, 10^9, 50, ...] para [0, 2, 1, ...].
 * ==============================================================================
 */
void coordinate_compression(vector<long long>& a) {
    vector<long long> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    // Remove duplicados
    sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());

    // Substitui cada elemento pelo seu rank (índice comprimido)
    for (int i = 0; i < a.size(); i++) {
        a[i] = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) -
               sorted_a.begin();
    }
}