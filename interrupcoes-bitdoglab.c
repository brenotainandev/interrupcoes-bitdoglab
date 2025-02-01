#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "../includes/botao.h"
#include "../includes/led-rgb.h"
#include "../includes/matriz-led.h"
#include "../includes/animacoes.h"
#include "interrupcoes_bitdoglab.pio.h"

int main() {
    stdio_init_all();

    // Inicialização do contador
    PIO pio = pio0;
    bool clk;
    clk = set_sys_clock_khz(128000, false);
    uint offset = pio_add_program(pio, &interrupcoes_bitdoglab_program);
    uint sm = pio_claim_unused_sm(pio, true);
    interrupcoes_bitdoglab_program_init(pio, sm, offset, PINO_LEDS);

    // Configuração dos botões e LEDs
    configurar_botoes();
    configurar_led_rgb();

    // Timer para piscar **somente** o LED vermelho do RGB
    struct repeating_timer timer;
    add_repeating_timer_ms(200, piscar_led_rgb_vermelho, NULL, &timer); // Pisca 5x por segundo

    int ultimo_contador = -1; // Guarda o último número exibido

    // Loop principal
    while (true) {
        if (contador != ultimo_contador) { // Só atualiza se o contador mudar
            printf("Número exibido: %d\n", contador);
            ultimo_contador = contador;

            void (*animacao[]) (PIO, uint) = {
                animacao_numero_zero,
                animacao_numero_um,
                animacao_numero_dois,
                animacao_numero_tres,
                animacao_numero_quatro,
                animacao_numero_cinco,
                animacao_numero_seis,
                animacao_numero_sete,
                animacao_numero_oito,
                animacao_numero_nove
            };

            if (contador >= 0 && contador <= 9) {
                animacao[contador](pio, sm);
            } else {
                printf("Nenhuma animação disponível para o número %d\n", contador);
            }
        }

        sleep_ms(500);
    }
}
