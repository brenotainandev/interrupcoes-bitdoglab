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

    // Loop principal
    while (true) {
        printf("Número exibido: %d\n", contador);

        switch (contador)
        {
            case 0:
                animacao_numero_zero(pio, sm);
                break;
            case 1:
                animacao_numero_um(pio, sm);
                break;
            case 2:
                animacao_numero_dois(pio, sm);
                break;
            case 3:
                animacao_numero_tres(pio, sm);
                break;
            case 4:
                animacao_numero_quatro(pio, sm);
                break;
            case 5:
                animacao_numero_cinco(pio, sm);
                break;
            case 6:
                animacao_numero_seis(pio, sm);
                break;
            case 7:
                animacao_numero_sete(pio, sm);
                break;
            case 8:
                animacao_numero_oito(pio, sm);
                break;
            case 9:
                animacao_numero_nove(pio, sm);
                break;
            default:
                printf("Nenhuma animação disponível para o número %d\n", contador);
        }

        sleep_ms(500);
    }
}
