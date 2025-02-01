#ifndef BOTOA_H
#define BOTOA_H

#include "pico/stdlib.h"

// Definição dos pinos dos botões
#define BOTAO_A 5
#define BOTAO_B 6

// Declaração das funções
void configurar_botoes(void);
void tratar_interrupcao_botao(uint gpio, uint32_t eventos);

extern volatile int contador; // Variável global do contador

#endif // BOTOA_H
