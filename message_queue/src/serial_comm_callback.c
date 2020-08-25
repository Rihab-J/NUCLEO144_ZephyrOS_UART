#include "serial_comm.h"
#include <string.h>

#define SLEEPTIME 100

struct message
{
	uint8_t recData;
};
char __aligned(4) my_msgq_buffer[10 * sizeof(char)];
K_MSGQ_DEFINE(my_msgq, sizeof(char), 10, 4);

void serial_comm_callback(struct device *uart_dev, void *user_data)
{
	struct message data;

	if (!uart_irq_update(uart_dev))
	{
		printk("retval should always be 1");
		return;
	}
	if (uart_irq_rx_ready(uart_dev))
	{
		uart_fifo_read(uart_dev, &data.recData, 1);
	}

	while (k_msgq_put(&my_msgq, &data, K_NO_WAIT) != 0)
	{
		/* message queue is full: purge old data & try again */
		printk("message queue is full: purging old data & try again");
		k_msgq_purge(&my_msgq);
	}
}
void read_data(void)
{
	struct message received_message;

	while (1)
	{

		/* get a data item */
		if (k_msgq_get(&my_msgq, &received_message, K_FOREVER) == 0)
		{
			printk("%c", received_message.recData);
		}
	}
}