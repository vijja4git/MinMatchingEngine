#include "OrderBook.h"
#include <iostream>

void OrderBook::add_order(const Order& order) {
    if (order.type == OrderType::BUY) {
        buy_orders[order.price].push(order);
    } else {
        sell_orders[order.price].push(order);
    }
}

void OrderBook::match_orders() {
    while (!buy_orders.empty() && !sell_orders.empty()) {
        auto buy_it = buy_orders.rbegin();   // Highest buy
        auto sell_it = sell_orders.begin();  // Lowest sell

        if (buy_it->first >= sell_it->first) {
            Order& buy = buy_it->second.front();
            Order& sell = sell_it->second.front();

            int traded_qty = std::min(buy.quantity, sell.quantity);
            std::cout << "Trade: " << traded_qty << " @ " << sell.price << std::endl;

            buy.quantity -= traded_qty;
            sell.quantity -= traded_qty;

            if (buy.quantity == 0) buy_it->second.pop();
            if (sell.quantity == 0) sell_it->second.pop();

            if (buy_it->second.empty()) buy_orders.erase(buy_it->first);
            if (sell_it->second.empty()) sell_orders.erase(sell_it->first);
        } else {
            break;
        }
    }
}

void OrderBook::print_book() const {
    std::cout << "\nRemaining Buy Orders:\n";
    for (auto it = buy_orders.rbegin(); it != buy_orders.rend(); ++it) {
        auto queue = it->second; // make a copy
        while (!queue.empty()) {
            const auto& order = queue.front();
            std::cout << "BUY " << order.quantity << " @ " << order.price << "\n";
            queue.pop();
        }
    }

    std::cout << "\nRemaining Sell Orders:\n";
    for (auto& [price, queue] : sell_orders) {
        auto temp = queue; // make a copy
        while (!temp.empty()) {
            const auto& order = temp.front();
            std::cout << "SELL " << order.quantity << " @ " << order.price << "\n";
            temp.pop();
        }
    }
}