#include "serial_comm.h"
#include <string.h>

void serial_comm_send_data(struct device *uart, char * szStr) {
    size_t i;
    unsigned char temp;
    for (i = 0; i < strlen(szStr); i++) {
        temp = szStr[i];
        uart_poll_out(uart, temp);
    }
}
