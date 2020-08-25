#include "serial_comm.h"
#include <drivers/gpio.h>


const struct uart_config uart_cfg = {
		.baudrate = 115200,
		.parity = UART_CFG_PARITY_NONE,
		.stop_bits = UART_CFG_STOP_BITS_1,
		.data_bits = UART_CFG_DATA_BITS_8,
		.flow_ctrl = UART_CFG_FLOW_CTRL_NONE
	};
void serial_comm_config(void){
    struct device *uart_dev = device_get_binding(my_serial); 

    if (!uart_dev) {
		printk("Cannot get UART device : %s \n", my_serial);
		return ;}
    int ret = uart_configure( uart_dev, &uart_cfg);
    if (ret<0){
        return;
    }
} 

