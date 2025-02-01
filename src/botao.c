#include "../includes/botao.h"
#include <stdio.h>

// Variáveis globais para debounce
volatile int contador = 0;
volatile uint32_t ultimo_tempo_a = 0;
volatile uint32_t ultimo_tempo_b = 0;

// Configura os botões e ativa a interrupção
void configurar_botoes(void) {
    gpio_init(BOTAO_A);
    gpio_set_dir(BOTAO_A, GPIO_IN);
    gpio_pull_up(BOTAO_A);
    gpio_set_irq_enabled_with_callback(BOTAO_A, GPIO_IRQ_EDGE_FALL, true, &tratar_interrupcao_botao);

    gpio_init(BOTAO_B);
    gpio_set_dir(BOTAO_B, GPIO_IN);
    gpio_pull_up(BOTAO_B);
    gpio_set_irq_enabled_with_callback(BOTAO_B, GPIO_IRQ_EDGE_FALL, true, &tratar_interrupcao_botao);
}

// Função de interrupção dos botões
void tratar_interrupcao_botao(uint gpio, uint32_t eventos) {
    uint32_t tempo_atual = to_us_since_boot(get_absolute_time());

    if (gpio == BOTAO_A && (tempo_atual - ultimo_tempo_a > 250000)) { // 250ms debounce
        ultimo_tempo_a = tempo_atual;
        contador = (contador + 1) % 10;
        printf("Botão A pressionado! Contador: %d\n", contador);
    }

    if (gpio == BOTAO_B && (tempo_atual - ultimo_tempo_b > 250000)) { // 250ms debounce
        ultimo_tempo_b = tempo_atual;
        contador = (contador - 1 + 10) % 10;
        printf("Botão B pressionado! Contador: %d\n", contador);
    }
}
