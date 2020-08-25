To assure the UART serial communication, a callback function was needed
For that we could use : 
 * uart_callback_set() : for the event-based API, (the asynchrone api)
 * uart_irq_callback_set() :  for the regular IRQ-based API (basic api)
 
As we use the Nucelo_f412zg board, only the API with a regular IRQ (basic api) is supported

Reference : 
        https://docs.zephyrproject.org/latest/reference/peripherals/uart.html#api-reference