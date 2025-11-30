#include <stdio.h>

int main() {
    int r1, c1;
    printf("Enter the rows and cols of sparse matrix: ");
    scanf("%d %d", &r1, &c1);

    int m1[50][50];
    printf("Enter the elements of sparse matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &m1[i][j]);
        }
    }

    int n1 = 0;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (m1[i][j] != 0) n1++;
        }
    }

    int t1[n1 + 1][3];
    t1[0][0] = r1;
    t1[0][1] = c1;
    t1[0][2] = n1;

    int k = 1;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (m1[i][j] != 0) {
                t1[k][0] = i;
                t1[k][1] = j;
                t1[k][2] = m1[i][j];
                k++;
            }
        }
    }

    printf("\nTriplet Representation:\n");
    for (int i = 0; i <= n1; i++) {
        printf("%d %d %d\n", t1[i][0], t1[i][1], t1[i][2]);
    }

    int st1[n1 + 1][3];
    st1[0][0] = t1[0][1];
    st1[0][1] = t1[0][0];
    st1[0][2] = t1[0][2];

    k = 1;
    for (int col = 0; col < t1[0][1]; col++) {
        for (int i = 1; i <= n1; i++) {
            if (t1[i][1] == col) {
                st1[k][0] = t1[i][1];
                st1[k][1] = t1[i][0];
                st1[k][2] = t1[i][2];
                k++;
            }
        }
    }

    printf("\nSimple Transpose:\n");
    for (int i = 0; i <= n1; i++) {
        printf("%d %d %d\n", st1[i][0], st1[i][1], st1[i][2]);
    }

    int ft1[n1 + 1][3];
    int cnt[50], pos[50];

    ft1[0][0] = t1[0][1];
    ft1[0][1] = t1[0][0];
    ft1[0][2] = t1[0][2];

    for (int i = 0; i < c1; i++) cnt[i] = 0;
    for (int i = 1; i <= n1; i++) cnt[t1[i][1]]++;

    pos[0] = 1;
    for (int i = 1; i < c1; i++) pos[i] = pos[i - 1] + cnt[i - 1];

    for (int i = 1; i <= n1; i++) {
        int p = pos[t1[i][1]];
        ft1[p][0] = t1[i][1];
        ft1[p][1] = t1[i][0];
        ft1[p][2] = t1[i][2];
        pos[t1[i][1]]++;
    }

    printf("\nFast Transpose:\n");
    for (int i = 0; i <= n1; i++) {
        printf("%d %d %d\n", ft1[i][0], ft1[i][1], ft1[i][2]);
    }

    int r2, c2;
    printf("\nEnter rows and cols of 2nd matrix: ");
    scanf("%d %d", &r2, &c2);

    if (r1 != r2 || c1 != c2) {
        printf("Addition not possible!\n");
        return 0;
    }

    int m2[50][50];
    printf("Enter elements of 2nd matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    int n2 = 0;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            if (m2[i][j] != 0) n2++;

    int t2[n2 + 1][3];
    t2[0][0] = r2;
    t2[0][1] = c2;
    t2[0][2] = n2;

    k = 1;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            if (m2[i][j] != 0) {
                t2[k][0] = i;
                t2[k][1] = j;
                t2[k][2] = m2[i][j];
                k++;
            }
        }
    }

    int tsum[n1 + n2 + 1][3];
    int i = 1, j = 1, s = 1;

    tsum[0][0] = r1;
    tsum[0][1] = c1;

    while (i <= n1 && j <= n2) {
        if (t1[i][0] == t2[j][0] && t1[i][1] == t2[j][1]) {
            tsum[s][0] = t1[i][0];
            tsum[s][1] = t1[i][1];
            tsum[s][2] = t1[i][2] + t2[j][2];
            i++; j++; s++;
        } else if (t1[i][0] < t2[j][0] || (t1[i][0] == t2[j][0] && t1[i][1] < t2[j][1])) {
            tsum[s][0] = t1[i][0];
            tsum[s][1] = t1[i][1];
            tsum[s][2] = t1[i][2];
            i++; s++;
        } else {
            tsum[s][0] = t2[j][0];
            tsum[s][1] = t2[j][1];
            tsum[s][2] = t2[j][2];
            j++; s++;
        }
    }

    while (i <= n1) {
        tsum[s][0] = t1[i][0];
        tsum[s][1] = t1[i][1];
        tsum[s][2] = t1[i][2];
        i++; s++;
    }
    while (j <= n2) {
        tsum[s][0] = t2[j][0];
        tsum[s][1] = t2[j][1];
        tsum[s][2] = t2[j][2];
        j++; s++;
    }

    tsum[0][2] = s - 1;

    printf("\nAddition (Triplet Form):\n");
    for (int x = 0; x < s; x++) {
        printf("%d %d %d\n", tsum[x][0], tsum[x][1], tsum[x][2]);
    }

    return 0;
}
