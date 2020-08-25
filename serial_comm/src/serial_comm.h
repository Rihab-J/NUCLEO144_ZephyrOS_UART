#include <device.h>
#include <drivers/uart.h>


#define my_serial CONFIG_UART_CONSOLE_ON_DEV_NAME 
void serial_comm_config(void); 
void serial_comm_send_data(struct device *uart, char * szStr);
void serial_comm_callback(struct device *dev,void *user_data);