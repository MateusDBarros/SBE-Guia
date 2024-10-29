# Simulação de Batalhas Espaciais

Este projeto é um Simulador de Batalhas Espaciais em C. Os jogadores podem escolher uma nave e lutar contra o computador.

## Funcionalidades

- **Escolha de Nave:** O jogador pode escolher entre quatro naves diferentes, cada uma com atributos únicos de ataque, defesa e velocidade.
- **Batalha:** As naves se alternam atacando até que uma delas seja destruída.
- **Mensagens de Status:** O jogo exibe a energia restante de cada nave após cada turno.

## Estrutura de Dados

As naves são representadas por uma `struct` com os seguintes atributos:
- `nome`: Nome da nave.
- `ataque`: Valor de ataque.
- `defesa`: Valor de defesa.
- `energia`: Energia atual.
- `velocidade`: Velocidade da nave.

## Como Usar

1. Clone o repositório:
    ```
    git clone https://github.com/MateusDBarros/SBE.git
    ```

2. Compile o código:
    ```
    gcc src/main.c -o SBE
    ```

3. Execute o programa:
    ```
    ./main
    ```

4. Siga as instruções no menu para escolher sua nave e iniciar a batalha.

## Contato

- [LinkedIn](https://www.linkedin.com/in/mateus-barros13
- Email: mb685212@gmail.com
