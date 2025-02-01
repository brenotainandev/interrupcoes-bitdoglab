#include <stdio.h>
#include "pico/stdlib.h"
#include "../includes/botao.h"
#include "../includes/led-rgb.h"
#include "../includes/matriz-led.h"

int main() {
    stdio_init_all();

    // Configuração dos botões e LEDs
    configurar_botoes();
    configurar_led_rgb();

    // Timer para piscar **somente** o LED vermelho do RGB
    struct repeating_timer timer;
    add_repeating_timer_ms(200, piscar_led_rgb_vermelho, NULL, &timer); // Pisca 5x por segundo

    // Loop principal
    while (true) {
        printf("Número exibido: %d\n", contador);

        sleep_ms(500);
    }
}
