#include <cstdio>
const int maxn = 1000010;
const int INF = 0x7fffffff;
int S1[maxn], S2[maxn];

int main() {
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &S1[i]);
    }
    scanf("%d", &m);
    if(m<10000&&sizeof(int)==4){
    	for(int i = 0; i < m; i++) {
	        scanf("%d", &S2[i]);
	    }
	    S1[n] = S2[m] = INF;
	    int medianPos = (n + m - 1) / 2;
	    int i = 0, j = 0, count = 0;
	    while(count < medianPos) {
	        if(S1[i] < S2[j]) i++;
	        else j++;
	        count++;
	    }
	    if(S1[i] < S2[j]) {
	        printf("%d\n", S1[i]);
	    } else {
	        printf("%d\n", S2[j]);
	    }
	}else{
		int tmp,index=0;
	    S1[n] = INF;
	    int medianPos = (n + m - 1) / 2;
	    int i = 0, j = 0, count = 0;
	    scanf("%d", &tmp);
	    index++;
	    while(count < medianPos) {
	        if(index<m){
		        if(S1[i] < tmp) i++;
		        else {
		            scanf("%d", &tmp);
		            index++;
		        }
			}
			else i++;
	        count++;
	    }
	    if(S1[i] < tmp) {
	        printf("%d\n", S1[i]);
	    } else {
	        printf("%d\n", tmp);
	    }
	}
    return 0;
}
