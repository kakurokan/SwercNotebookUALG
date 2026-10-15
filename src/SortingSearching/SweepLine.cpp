/* 
 * Algoritmo: Sweep-Line (Event Sorting)
 * Descrição: Processa intervalos sobrepostos. Cada intervalo [L, R] é
 * dividido em dois eventos: entrada (L) e saída (R).
 */
#include <bits/stdc++.h>
using namespace std;

struct Event {
    long long time;
    int type;  // 1 para entrada, -1 para saída (ou 0 para saída se a ordem
               // importar)
    int id;    // Útil se precisarmos de rastrear qual o intervalo (ex: Room
               // Allocation)

    // Ordenação: 1º pelo tempo. Em caso de empate, processar entradas primeiro?
    // Depende do problema. Aqui, processamos saídas (-1) antes de entradas (1)
    // se quisermos estritamente sobreposição simultânea.
    bool operator<(const Event& other) const {
        if (time != other.time) return time < other.time;
        return type < other.type;
    }
};

int max_overlap(const vector<pair<long long, long long>>& intervals) {
    vector<Event> events;
    for (int i = 0; i < intervals.size(); i++) {
        events.push_back({intervals[i].first, 1, i});
        events.push_back({intervals[i].second, -1, i});
    }

    sort(events.begin(), events.end());

    int current_active = 0, max_active = 0;
    for (const auto& ev : events) {
        current_active += ev.type;
        max_active = max(max_active, current_active);
    }
    return max_active;
}