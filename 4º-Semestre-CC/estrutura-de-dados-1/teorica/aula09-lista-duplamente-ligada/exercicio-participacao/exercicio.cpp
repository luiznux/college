
/*
 * calcula o valor do elemento medio de uma lista usando dois aux,
 * que começa na cabeça e outro no tail, caso seja par a lista ele retorna
 * a media dos valores do meio
 */
float Double_linked_list::middle_value(){

    Node *aux_start = head;
    Node *aux_end = tail;

    while(true){

        //é impar  a lista
        if(aux_start == aux_end){
            return aux_start->item;

            //é par
        }else if(aux_start->next == aux_end){
            return (aux_start->item + aux_end->item)/2;
        }
        aux_start = aux_start->next;
        aux_end = aux_end->preview;
    }
}

//metodo para a ordenação
void Double_linked_list::insertionSort(int *arr, int n)
{
    int i, j;
    int key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*
 *o metodo consiste em passar uma copia dos valores da lista para um vetor
 *de mesmo tamanho(trei que percorrer a lista para saber o tamanho),e entao
 *ordeno o vetor e altero o valor de cada no da lista com os valores do ve-
 *vetor ja ordenado
 */
void Double_linked_list::sort_list(){

    int size = 0;

    //calculo do tamanho
    for(Node *aux = head;aux != NULL; aux = aux->next){
        size++;
    }

    //preenchendo o vetor
    int vector[size];
    int i = 0;
    for(Node *aux = head; aux != NULL && i < size; aux = aux->next, i++){
        vector[i] = aux->item;
    }

    //ordeno e altero a lista original
    insertionSort(vector, size);
    i = 0;
    for(Node *aux = head; aux != NULL && i < size; aux = aux->next, i++){

        aux->item = vector[i];
    }
}
