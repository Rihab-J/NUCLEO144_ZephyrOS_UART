#include "serial_comm.h"
static volatile bool data_received;
void main(void)
{
	struct device *uart;
	uart = device_get_binding(my_serial);

	if (!uart) {
		printk("Cannot find myuart uart(%s)!\n", my_serial);
		return;
	}
    
	serial_comm_config();
	serial_comm_send_data(uart, "hello\n");
	//uart_callback_set(uart,serial_comm_callback,NULL);
	uart_irq_callback_set(uart, serial_comm_callback);
	uart_irq_rx_enable(uart);

	printk("Please send characters to serial console\n");

	data_received = false;
	while (data_received == false) {
	}

	/*Verify uart_irq_rx_disable() */
	uart_irq_rx_disable(uart);
	
	while (1) {
	}
}

