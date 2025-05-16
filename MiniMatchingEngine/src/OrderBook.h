#pragma once
#include <map>
#include <queue>

enum class OrderType { BUY, SELL };

struct Order {
    int order_id;
    OrderType type;
    int price;
    int quantity;
    long timestamp;
};

class OrderBook {
public:
    void add_order(const Order& order);
    void match_orders();
    void print_book() const;

private:
    std::map<int, std::queue<Order>> buy_orders;  // Highest price first
    std::map<int, std::queue<Order>> sell_orders; // Lowest price first
};