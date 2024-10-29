#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Nave
{
    char nome[25];
    int ataque;
    int defesa;
    int energia;
    int velocidade;
};

struct Nave naves[4] = {
        {"Astro", 18, 15, 120, 50},
        {"Apollo", 25, 10, 100, 40},
        {"Sombra", 18, 15, 150, 48},
        {"Umbra", 19, 15, 105, 45}
        };

int P1(void);
int P2(void);
void status(struct Nave nave1, struct Nave nave2);
void ataque(struct Nave *nave1, struct Nave *nave2);
void defesa(struct Nave *nave1, struct Nave *nave2);
int velocidade(struct Nave nave1, struct Nave nave2);
int vitoria(struct Nave nave1, struct Nave nave2);

int main(void)
{
    srand(time(0));
    int escolha; //Armazena a escolha da nave
    int acaoJogador; //Armazena qual ação o jogador tera
    int acaoComputador; //Armazena a ação do computador;
    int turno;

    struct Nave jogador;
    struct Nave computador;
    
    
    printf("| %-10s | %-5s | %-5s | %-5s| %-5s\n", "Nome", "Ataque", "Defesa", "Velocidade","Energia");
    printf("----------------------------------------------\n");
    for (int i = 0; i < 4; i++) {
        printf("| %-10s | %-6d | %-6d | %-5d\n",naves[i].nome, naves[i].ataque, naves[i].defesa, naves[i].velocidade ,naves[i].energia);
        
    }
    do {
        printf("\n---Escolha sua nave---\n");
        printf("1. Astro\n2. Apollo\n3. Sombra\n4. Umbra\n(Aperte 5 para sair)\n");
        scanf("%d", &escolha);
        switch (escolha) {
        case 1:
            jogador = naves[0];
            break;
        case 2:
            jogador = naves[1];
            break;
        case 3:
            jogador = naves[2];
            break;
        case 4:
            jogador = naves[3];
            break;
        case 5:
            printf("Encerrando programa...\n");
            return 0;
            break;
        
        default:
            system("cls");
            printf("Opcao invalida!\n");
            printf("\n");
            continue;
        }
        
        //Seleciona uma da opções aleatoriamente e previne matchup espelhadas
        int index = rand() % 4;
        while (index == escolha - 1) {
            index = rand() % 4;
        }
        computador = naves[index];
        turno = velocidade(jogador, computador);
        system("cls");

        do {
            if (vitoria(jogador, computador) == 0) {
                status(jogador, computador);
                printf("Voce venceu!\n");
                return 0;
            }
            else if (vitoria(jogador, computador) == 1) {
                status(jogador, computador);
                printf("Voce Perdeu, mais sorte da proxima vez!\n");
                return 0;
            }
            //Inicio da batalha
            status(jogador, computador);
            acaoJogador = P1();
            acaoComputador = P2();
            printf("\n");

            if(acaoJogador == 2 && acaoComputador == 2) {
                    printf("Ninguem atacou nesse turno!\n");
                    continue;
            }
            if(acaoJogador == 1 && acaoComputador == 1) {
                ataque(&jogador, &computador);
                ataque(&computador, &jogador);
                if (turno == 0)
                    turno = 1;
                else 
                    turno = 0;
                continue;
            }

            if (turno == 0) {
                if (acaoJogador == 1) 
                    defesa(&jogador, &computador);
                else 
                    defesa(&computador, &jogador);
                turno == 1;
                continue;
            }
            else {
                if (acaoComputador == 1)
                    defesa(&computador, &jogador);
                turno = 0;
                continue;
            }

        } while (jogador.energia != 0 && computador.energia != 0 );
    } while(escolha != 5);
    return 0;
}

int P1(void) {
    int acaoV; //acaoV para identifica e nao confundir a variavel com a função
    do {
        printf("1. Atacar\n");
        printf("2. Defender\n");
        scanf("%d", &acaoV);
        switch (acaoV) {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while(acaoV != 1 && acaoV != 2);  
}

int P2(void) {
    return rand() % 2 + 1;
}

void ataque(struct Nave *nave1, struct Nave *nave2) {
     //Ataca normalmente
    nave2->energia -= nave1->ataque;
    if (nave2->energia < 0)
        nave2->energia = 0;
    nave2->velocidade -= 2;
    printf("%s ataca %s causando %d de dano.\n", nave1->nome, nave2->nome, nave1->ataque);
    if (vitoria(*nave1, *nave2) == 0) {
        status(*nave1, *nave2);
        printf("Voce venceu!\n");
        return;
    }
    else if (vitoria(*nave1, *nave2) == 1) {
        status(*nave1, *nave2);
        printf("Voce Perdeu, mais sorte da proxima vez!\n");
        return;
    }
    return;
}



void defesa(struct Nave *nave1, struct Nave *nave2) {
    int dano;
    dano = nave1->ataque - nave2->defesa;
    nave2->velocidade - 1;
    if (dano < 0)
        dano = 0;
    nave2->energia -= dano;
    if (nave2->energia < 0)
        nave2->energia = 0;
    printf("%s defende o ataque de %s, mas sofre %d de dano.\n", nave2->nome, nave1->nome, dano);
    if (vitoria(*nave1, *nave2) == 0) {
        status(*nave1, *nave2);
        printf("Voce venceu!\n");
        return;
    }
    else if (vitoria(*nave1, *nave2) == 1) {
        status(*nave1, *nave2);
        printf("Voce Perdeu, mais sorte da proxima vez!\n");
        return;
    }
    return;
}
int velocidade(struct Nave nave1, struct Nave nave2) {
    if(nave1.velocidade > nave2.velocidade)
        return 0;
    else if (nave1.velocidade <  nave2.velocidade)
        return 1;
    else 
        return 0;
}
void status(struct Nave nave1, struct Nave nave2) {
    printf("Energia Jogador '%s': %d\n",nave1.nome, nave1.energia);
    printf("Energia Computador '%s': %d\n",nave2.nome, nave2.energia);
}

int vitoria(struct Nave nave1, struct Nave nave2) {
    if (nave1.energia == 0) {
        return 1;
    }
    if (nave2.energia == 0) {
        return 0;
    }
    return -1;
}