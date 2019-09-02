void Pilha::reverse(){

    int x;
    Pilha aux;
    Pilha aux2;

// passa da pilha origina para aux, aux ficara invertida
    while(!vazia()){
        top(x);
        pop();
        aux.push(x);
    }

    // passa da aux1 par aux2, aux ficara com a ordem da original
    while(!aux.vazia()){
        aux.top(x);
        aux.pop();
        aux2.push(x);
    }

    // passa da aux 2 para a original, deixando a origem invertida
    while(!aux2.vazia()){
        aux2.top(x);
        aux2.pop();
        push(x);
    }

}

void Pilha::inverte_outra_pilha(Pilha &S){
    int x;
    Pilha aux;

    // passo da original para  a invertida e para aux
    while(!vazia()){
        top(x);
        pop();
        S.push(x);
        aux.push(x);
    }

    // passo da aux para a original afim de mante original inteira
    while(!aux.vazia()){
        aux.top(x);
        aux.pop();
        push(x);
    }
}
