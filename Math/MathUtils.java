public static class MathUtils {
    // Um número primo grande comumente usado em competições (10^9 + 7).
    // O fato de ser PRIMO é crucial para o funcionamento do modInverse (Fermat).
    static final long MOD = 1_000_000_007;

    /**
     * Calcula (base^exp) % MOD de forma eficiente.
     * Técnica: Exponenciação Binária (Binary Exponentiation / Exponentiation by Squaring).
     * [cite_start]Referência: Capítulo 21.2 "Modular exponentiation"
     * * Complexidade: O(log exp) - Muito mais rápido que um loop O(exp).
     * Exemplo: Para calcular 3^10, faz ~4 passos em vez de 10.
     */
    public static long modPow(long base, long exp) {
        long res = 1;
        base %= MOD; // Garante que a base esteja no intervalo [0, MOD-1]

        while (exp > 0) {
            // Se o expoente é ÍMPAR (o bit menos significativo é 1),
            // multiplicamos o resultado pela base atual.
            // Propriedade: x^n = x * (x^2)^((n-1)/2)
            if ((exp & 1) == 1)
                res = (res * base) % MOD;

            // Em todos os passos, elevamos a base ao quadrado
            // e dividimos o expoente por 2 (shift right).
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    /**
     * Calcula o Inverso Modular de n módulo MOD.
     * Em aritmética modular, não existe divisão direta (a / b).
     * Em vez disso, multiplicamos pelo inverso: a * (b^-1).
     * * Técnica: Pequeno Teorema de Fermat.
     * Fórmula: n^(MOD-2) % MOD é o inverso de n.
     * REQUISITO: MOD deve ser um número PRIMO.
     */
    public static long modInverse(long n) {
        return modPow(n, MOD - 2);
    }

    /**
     * Calcula o Máximo Divisor Comum (GCD / MDC) de dois números.
     * Técnica: Algoritmo de Euclides.
     * Propriedade: gcd(a, b) = gcd(b, a % b).
     * [cite_start]Referência: Capítulo 21.1 "Euclid's algorithm" [cite: 3429-3430].
     */
    public static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    /**
     * (Bônus) Calcula o Mínimo Múltiplo Comum (LCM / MMC).
     * Fórmula: (a * b) / gcd(a, b).
     * Cuidado: overflow em a*b antes da divisão!
     */
    public static long lcm(long a, long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }
}