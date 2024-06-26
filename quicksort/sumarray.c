int sumarray(int arr[], int size) {
    //Caso base: se o array estiver vazio, a soma é 0 
    if (size == 0) {
        return 0;
    }
    //Caso base: se o array tiver um único alemento, a soma é esse elemento 
    if (size == 1) {
        return arr[0];
    }
    //Encontrar o ponto médio do array
    int mid = size / 2;
    //Alocar memória para as duas metades
    int* left = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc(mid * sizeof(int));

    //Copiar elementos para a metade esquerda
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    //Copiar elementos para a metade direita
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    //Chamada recursiva para cada parte e soma os resultados 
    int sumleft = sumarray(left, mid);
    int sumright =  sumarray(right, (size - mid));

    //Combionar os resultados 
    int sumtotal = sumleft + sumright;
    
    //Liberar memória alocada
    free(left);
    free(right);

    return sumtotal;
}

int main() {
    int array[] = {1,2,3,4,5};
    int size = sizeof(array) / sizeof(array[0]);
    int res = sumarray(array, size);
    printf("A soma dos elemnetos do array é: %d\n", res);
    return 0;
}