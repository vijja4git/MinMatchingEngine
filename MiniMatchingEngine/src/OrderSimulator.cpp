#include "OrderSimulator.h"
#include <chrono>
#include <random>
#include <thread>
#include <iostream>

OrderSimulator::OrderSimulator(OrderBook& book) : order_book(book), order_counter(1) {}

int64_t OrderSimulator::get_current_timestamp() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
               std::chrono::system_clock::now().time_since_epoch())
        .count();
}

Order OrderSimulator::generate_random_order() {
    static std::default_random_engine rng(std::random_device{}());
    std::uniform_int_distribution<int> price_dist(95, 105);
    std::uniform_int_distribution<int> qty_dist(1, 10);
    std::bernoulli_distribution side_dist(0.5); // 50% buy/sell

    OrderType type = side_dist(rng) ? OrderType::BUY : OrderType::SELL;

    return {
        order_counter++, type, price_dist(rng), qty_dist(rng), get_current_timestamp()
    };
}

void OrderSimulator::start_streaming(int num_orders, int interval_ms) {
    for (int i = 0; i < num_orders; ++i) {
        Order o = generate_random_order();
        std::cout << "New Order: " << (o.type == OrderType::BUY ? "BUY " : "SELL ")
                  << o.quantity << " @ " << o.price << "\n";

        order_book.add_order(o);
        order_book.match_orders();
        std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));
    }

    order_book.print_book();
}