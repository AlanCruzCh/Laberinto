#include <stdio.h>
#include <stdlib.h>

int *avanza_derecha(int laberinto_aux[][7], int fila, int columna, int posicion_fila_columna_bandera[]){
    if ((laberinto_aux[fila + 1][columna] != 1) && (fila != 7)){
        laberinto_aux[fila][columna] = 2;
        posicion_fila_columna_bandera[0] = (fila += 1);
        posicion_fila_columna_bandera[1] = columna;
        posicion_fila_columna_bandera[2] = 2;  /*2 es la bandera para que baje */
        return posicion_fila_columna_bandera;
    }
    else if ((laberinto_aux[fila - 1][columna] != 1) && (fila != 0)){
        laberinto_aux[fila][columna] = 2;
        posicion_fila_columna_bandera[0] = (fila -= 1); 
        posicion_fila_columna_bandera[1] = columna;
        posicion_fila_columna_bandera[2] = 3; /* 3 es la bandera para que suba */
        return posicion_fila_columna_bandera;
    }
    else if ((laberinto_aux[fila][columna + 1] == 1) || (columna == 7)){
        posicion_fila_columna_bandera[1] = columna;
        laberinto_aux[fila][columna] = 2;
        if ((laberinto_aux[fila + 1][columna] != 1) && (fila != 7)){
            posicion_fila_columna_bandera[0] = (fila +=1);
            posicion_fila_columna_bandera[2] = 2;  /*2 es la bandera para que baje */
            return posicion_fila_columna_bandera;
        }
        else if ((laberinto_aux[fila][columna -1] != 1) && (columna != 0)){
            posicion_fila_columna_bandera[0] = fila;
            posicion_fila_columna_bandera[2] = 1; /* 1 es la bandera para que valla a la izquierda */
            return posicion_fila_columna_bandera;
        }    
        else if((laberinto_aux[fila -1][columna] != 1) && (fila != 0)){
            posicion_fila_columna_bandera[0] = (fila -= 1);
            posicion_fila_columna_bandera[2] = 3; /* 3 es la bandera para que suba */
            return posicion_fila_columna_bandera;
        }
    }
    else{
        laberinto_aux[fila][columna] = 2;
    }
    return avanza_derecha(laberinto_aux,fila,columna + 1, posicion_fila_columna_bandera);
}

int *avanza_izquierda(int laberinto_aux[][7], int fila, int columna, int posicion_fila_columna_bandera[]){
    if ((laberinto_aux[fila + 1][columna] != 1) && (fila != 7)){
        laberinto_aux[fila][columna] = 2;
        posicion_fila_columna_bandera[0] = (fila += 1);
        posicion_fila_columna_bandera[1] = columna;
        posicion_fila_columna_bandera[2] = 2;  /*2 es la bandera para que baje */
        return posicion_fila_columna_bandera;
    }
    else if ((laberinto_aux[fila - 1][columna] != 1) && (fila != 0)){
        laberinto_aux[fila][columna] = 2;
        posicion_fila_columna_bandera[0] = (fila -= 1); 
        posicion_fila_columna_bandera[1]= columna;
        posicion_fila_columna_bandera[2] = 3; /* 3 es la bandera para que suba */
        return posicion_fila_columna_bandera;
    }
    else if ((laberinto_aux[fila][columna - 1] == 1)|| (columna == 0)){
        posicion_fila_columna_bandera[1] = columna;
        laberinto_aux[fila][columna] = 2;
        if ((laberinto_aux[fila + 1][columna] != 1) && (fila != 7)){
            posicion_fila_columna_bandera[0] = (fila +=1);
            posicion_fila_columna_bandera[2] = 2;  /*2 es la bandera para que baje */
            return posicion_fila_columna_bandera;
        }
        else if ((laberinto_aux[fila][columna + 1] != 1) && (columna != 0)){
            posicion_fila_columna_bandera[0] = fila;
            posicion_fila_columna_bandera[2] = 0; /* 0 es la bandera para que valla a la derecha */
            return posicion_fila_columna_bandera;
        }    
        else if ((laberinto_aux[fila - 1][columna] != 1) && (fila != 0)){
            posicion_fila_columna_bandera[0] = (fila -= 1);
            posicion_fila_columna_bandera[2] = 3; /* 3 es la bandera para que suba */
            return posicion_fila_columna_bandera;
        }
    }
    else{
        laberinto_aux[fila][columna] = 2;
    }
    return avanza_izquierda(laberinto_aux,fila,columna - 1, posicion_fila_columna_bandera);
}



int main(){
    /*
    int laberinto[7][7] = { {0,1,1,1,1,1,1},
                            {0,0,0,0,1,1,1},
                            {1,0,1,1,1,1,1},
                            {0,0,1,1,1,1,1},
                            {1,0,1,1,1,0,1},
                            {0,0,0,0,0,0,0},
                            {0,1,0,0,1,0,0}};
                            */
    int laberinto[7][7] = { {0,0,0,0,0,0,0},
                            {1,1,1,1,1,1,1},
                            {1,0,1,1,1,1,1},
                            {0,0,1,1,1,1,1},
                            {1,0,1,1,1,0,1},
                            {0,0,0,0,0,0,0},
                            {0,1,0,0,1,0,0}};
    
    int posicion_fila_columna_bandera[3] = {0,0,0};
    int fila = 0; 
    int columna = 0;  
    int bandera = 0;
    int *derecha, *izquierda, *abajo, *arriba; 
    derecha = avanza_derecha(laberinto, fila, columna, posicion_fila_columna_bandera);
    fila = derecha[0];
    columna = derecha[1];
    bandera = derecha[2];    
    printf("%d %d %d\n\n", fila, columna, bandera);

    izquierda = avanza_izquierda(laberinto, fila, columna, posicion_fila_columna_bandera);
    fila = izquierda[0];
    columna = izquierda[1];
    bandera = izquierda[2];    
    printf("%d %d %d\n\n", fila, columna, bandera);
                    
    /*
    while((fila != 2)&&(columna != 2)){
        switch (bandera)
        {
        case 0:
            derecha = avanza_derecha(laberinto, fila, columna, pos_columna, posicion_fila_columna_bandera);
            fila = derecha[0];
            columna = derecha[1];
            bandera = derecha[2];    
            printf("%d %d %d\n\n", fila, columna, bandera);
            break;
        case 1:
            izquierda = avanza_izquierda(laberinto, fila, columna, pos_columna, posicion_fila_columna_bandera);
            fila = izquierda[0];
            columna = izquierda[1];
            bandera = izquierda[2];
            printf("%d %d %d\n\n", fila, columna, bandera);
            break;
        case 2:
            abajo = avanza_abajo(laberinto, fila, columna, pos_fila, posicion_fila_columna_bandera);
            fila = abajo[0];
            columna = abajo[1];
            bandera = abajo[2];
            printf("%d %d %d\n\n", fila, columna, bandera);
            break;
        default:
            break;
        }
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 7; j++){
                printf("%d ", laberinto[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    */
   return 0;
}