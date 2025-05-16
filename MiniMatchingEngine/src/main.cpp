#include "OrderBook.h"
#include "OrderSimulator.h"

int main() {
    OrderBook book;
    OrderSimulator simulator(book);

    // Simulate 20 orders, 200ms apart
    simulator.start_streaming(20, 200);

    return 0;
}