/* ==============================================================================
 * Algoritmo: Ordered Set (PBDS)
 * Descrição: Um std::set com superpoderes. 
 * Funcionalidades extra em O(log N):
 *  - find_by_order(k): retorna um iterador para o k-ésimo menor elemento (0-indexed)
 *  - order_of_key(k): retorna o número de elementos estritamente menores que k
 * ============================================================================== */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Definição do Ordered Set
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// NOTA: Para funcionar como um multiset (permitir duplicados), muda `less<int>` para `less_equal<int>`.
// Cuidado que no less_equal, a função erase() normal apaga TODAS as instâncias. 
// Deves apagar por iterador: s.erase(s.find_by_order(s.order_of_key(x)));
