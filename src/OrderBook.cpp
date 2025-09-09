/*
So far this file does the following:
- Defines the OrderBook class with priority queues for buy and sell orders.
- Implements methods to add orders, retrieve the top orders, and remove orders from the queues.

Further work includes:
- Ensuring thread safety for concurrent access.

OrderBook.cpp
- Implements the OrderBook class with two priority queues for buy and sell orders.
- Buy orders are sorted by highest price first.
- Sell orders are sorted by lowest price first.
*/

#include "OrderBook.hpp"

OrderBook::OrderBook():
    // before returning, initialize the priority queues with appropriate comparators for buy and sell orders.
    // Initialize buyOrders with comparator for highest price first
    buyOrders([](Order* a, Order* b) {
        // If prices are equal, earlier timestamp has higher priority
        if (a->price == b->price)
            return a->timestamp > b->timestamp;
        return a->price < b->price;
    }),
    // Initialize sellOrders with comparator for lowest price first
    sellOrders([](Order* a, Order* b) {
        // If prices are equal, earlier timestamp has higher priority
        if (a->price == b->price)
            return a->timestamp > b->timestamp;
        return a->price > b->price;
    }) {}

void OrderBook::addOrder(Order* order) {
    // Add order to the appropriate queue
    if (order->side == OrderSide::BUY)
        buyOrders.push(order);
    else
        sellOrders.push(order);
}

Order* OrderBook::topBuy() {
    // Return top buy order or nullptr if empty
    return buyOrders.empty() ? nullptr : buyOrders.top();
}

Order* OrderBook::topSell() {
    // Return top sell order or nullptr if empty
    return sellOrders.empty() ? nullptr : sellOrders.top();
}

void OrderBook::popBuy() {
    // Remove top buy order if not empty
    if (!buyOrders.empty()) buyOrders.pop();
}

void OrderBook::popSell() {
    // Remove top sell order if not empty
    if (!sellOrders.empty()) sellOrders.pop();
}