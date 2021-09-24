#include <stdio.h>
#include "pico/stdlib.h"
#include <tusb.h>
#include "pico/binary_info.h"

#include "ym2413_io.pio.h"

int main() {
	bi_decl(bi_1pin_with_name(19,"YM2413 /IC"));
	bi_decl(bi_1pin_with_name(20,"YM2413 /A0"));
	bi_decl(bi_1pin_with_name(18,"YM2413 /CS /WE"));
	bi_decl(bi_1pin_with_name(18,"YM2413 /CS /WE"));
	bi_decl(bi_2pins_with_func(16, 17, GPIO_FUNC_I2C));
	
    stdio_init_all();
	
    while(!tud_cdc_connected()) sleep_ms(100);
    printf("tud_cdc_connected()\n");

    printf("PIO Init...\n");
    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &ym2413_io_program);
    ym2413_io_program_init(pio, sm, offset, 32.f,2,18);


    printf("Done!\n");

    gpio_init(20); // A0
    gpio_init(19); // RESET

    gpio_set_dir(20, GPIO_OUT);
    gpio_set_dir(19, GPIO_OUT);

    gpio_set_dir(19, 0);
    gpio_set_dir(20, 0);


    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
    return 0;
}
