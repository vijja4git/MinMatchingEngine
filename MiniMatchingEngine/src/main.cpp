#include "OrderBook.h"

int main() {
    OrderBook book;

    // Sample test data
    book.add_order({1, OrderType::BUY, 100, 10, 1});
    book.add_order({2, OrderType::SELL, 99, 5, 2});
    book.add_order({3, OrderType::SELL, 98, 5, 3});

    book.match_orders();
    book.print_book();

    return 0;
}