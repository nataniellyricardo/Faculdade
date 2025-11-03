
int main() {
    int x[] = {1, 0, 0, 0, 1};
    int cont = 0;
    int i;
    int n = 5;
    int a;

    scanf ( " %d ", &a );

    for ( i = 0; i < n; i++ ) {
        if ( x [i] == 0 ) {
            if ( ( i == 0 || x [ i - 1 ] == 0 ) && ( i == n - 1 || x [ i + 1 ] == 0 ) ) {
                x [i] = 1;       
                cont++;     // Incrementa o contador
            }
        }
    }

    if ( cont >= a ){
        printf("true\n");
	} else {
        printf("false\n");
	}

    return 0;
}