#include "serial_comm.h"

#include <string.h>
unsigned int i;

static volatile bool data_received;
void serial_comm_callback(struct device *uart_dev, void *user_data)
{
	uint8_t recData;
	if (!uart_irq_update(uart_dev))
	{
		printk("retval should always be 1");
		return;
	}

	if (uart_irq_rx_ready(uart_dev))
	{
		uart_fifo_read(uart_dev, &recData, 1);
		printk("%c", recData);
	}

	if ((recData == '\n') || (recData == '\r'))
	{
		data_received = true;
	}
}
