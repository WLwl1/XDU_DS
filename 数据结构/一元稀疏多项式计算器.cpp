#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b);
struct PolyNode {
    int coef;
    int exp;
};

int main() {
    int n, m, op, i, j, nonZeroCount = 0;
    scanf("%d %d %d", &n, &m, &op);
    struct PolyNode polyA[n + m], polyB[m];

    for (i = 0; i < n; i++) {
        scanf("%d %d", &polyA[i].coef, &polyA[i].exp);
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d", &polyB[i].coef, &polyB[i].exp);
    }

    int sign = 1;
    if (op) sign = -1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (polyB[j].exp == polyA[i].exp) {
                polyA[i].coef += sign * polyB[j].coef;
                polyB[j].coef = 0;
            }
        }
    }
    for (i = 0; i < m; i++) {
        if (polyB[i].coef != 0) {
            polyA[n + i].exp = polyB[i].exp;
            polyA[n + i].coef = sign * polyB[i].coef;
        } else {
            polyA[n + i].exp = 0;
            polyA[n + i].coef = 0;
            nonZeroCount++;
        }
    }
    qsort(polyA, n + m, sizeof(polyA[0]), cmp);

    int firstTerm = 1, isFirstNonZero = 0;
    for (i = 0; i < n + m; i++) {
        if (polyA[i].coef) {
            if (isFirstNonZero && polyA[i].coef > 0) printf("+");
            firstTerm = 0; isFirstNonZero = 1;
            if (polyA[i].coef == 1) {
                if (polyA[i].exp == 1) {
                    printf("x");
                } else if (polyA[i].exp == 0) {
                    printf("%d", polyA[i].coef);
                } else {
                    printf("x^%d", polyA[i].exp);
                }
            } else if (polyA[i].coef == -1) {
                if (polyA[i].exp == 1) {
                    printf("-x");
                } else if (polyA[i].exp == 0) {
                    printf("%d", polyA[i].coef);
                } else {
                    printf("-x^%d", polyA[i].exp);
                }
            } else {
                if (polyA[i].exp == 1) {
                    printf("%dx", polyA[i].coef);
                } else if (polyA[i].exp == 0) {
                    printf("%d", polyA[i].coef);
                } else {
                    printf("%dx^%d", polyA[i].coef, polyA[i].exp);
                }
            }
        }
    }
    if (firstTerm) {
        printf("0");
    }
    return 0;
}

int cmp(const void *a, const void *b) {
    struct PolyNode *pA = (struct PolyNode *)a;
    struct PolyNode *pB = (struct PolyNode *)b;
    return (pA->exp - pB->exp);
}
