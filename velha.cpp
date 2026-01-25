#include <iostream>

using namespace std;

char tabuleiro [3][3];
char jogador = 'X';

void iniciarTabuleiro(){
    for (int i = 0; i < 3; i++ ) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void mostrarTabuleiro(){
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << tabuleiro[i][j] << " ";
            if(j < 2) cout << "|";
        }
        cout << "\n";
        if(i < 2) cout << "---|---|---\n";
    }
}

bool verificarVitoria() {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return true;
    }

    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] != ' ' && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j])
            return true;
    }

    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return true;
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return true;

    return false;
}

bool verificarEmpate(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tabuleiro[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

void jogada(){
    int linha, coluna;
    while(true){
        cout << "jogador " << jogador << "digite a linha e coluna 0 a 2: ";

        if (!(cin >> linha >> coluna)) {
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            continue;
        }

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2){
            cout << "posicao invalida \n";
        }
        else if(tabuleiro[linha][coluna] != ' '){
            cout << "ocupad0  \n";
        }
        else{
            tabuleiro[linha][coluna] = jogador;
            break;
        }
    }
}

void trocarJogador() {
    if (jogador == 'X') {
        jogador = 'O';
    } else {
        jogador = 'X';
    }
}

int main(){
    iniciarTabuleiro();

    while(true){
        mostrarTabuleiro();
        jogada();

        if(verificarVitoria()){
            mostrarTabuleiro();
            cout << "jogador " << jogador << " venceu \n";
            break; 
        }
        if(verificarEmpate()){
            mostrarTabuleiro();
            cout << "velha \n";
            break;
        }
        trocarJogador();
    }
    return 0;
}