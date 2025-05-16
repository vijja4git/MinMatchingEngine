#pragma once
#include "OrderBook.h"

class OrderSimulator {
public:
    OrderSimulator(OrderBook& book);
    void start_streaming(int num_orders, int interval_ms); // number of orders, delay in ms

private:
    OrderBook& order_book;
    int order_counter;
    int64_t get_current_timestamp();
    Order generate_random_order();
};