//Author/Autor: José Joaquim de Andrade Neto
//Link da questão UVA: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1217
//Link da questão URI: https://www.urionlinejudge.com.br/judge/pt/problems/view/1166

#include<cmath>
#include<cstdio>
#include<cstring>
 
using namespace std;
 
int T, N, tot;
int peg[100];
 
void simul(int v, int p) {
    if(p == N) return;
    if(peg[p] == 0) {
        peg[p] = v;
        tot++;
        return simul(v + 1, p);
    }
     
    for(int i = 0; i <= p; i++) {
        int root = (int) sqrt(peg[i] + v);
        if(root * root == peg[i] + v) {
            peg[i] = v;
            tot++;
            return simul(v + 1, p);
        }
    }
 
    simul(v, p + 1);
}
 
int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        memset(peg, 0, sizeof peg);
        tot = 0;
        simul(1, 0);
        printf("%d\n", tot);
    }
}
