/*
So far this file does the following:
- Defines the OrderBook class with priority queues for buy and sell orders.
- Implements methods to add orders, retrieve the top orders, and remove orders from the queues.

Further work includes:
- Ensuring thread safety for concurrent access.

OrderBook class maintains two priority queues:
- buyOrders: sorted by highest price first (max-heap)
- sellOrders: sorted by lowest price first (min-heap)
Custom comparators are used for correct sorting.
*/

#pragma once
#include <queue>
#include <vector>
#include "Order.hpp"
#include <functional>

using namespace std;

class OrderBook {
public:
    // Priority queue for buy orders: highest price first
    std::priority_queue<Order*, std::vector<Order*>, std::function<bool(Order*, Order*)>> buyOrders;
    // Priority queue for sell orders: lowest price first
    std::priority_queue<Order*, std::vector<Order*>, std::function<bool(Order*, Order*)>> sellOrders;

    /*
    Sorting logic for the priority queues:
    - Buy Orders: Higher price has higher priority. If prices are equal, earlier timestamp has higher priority.
    - Sell Orders: Lower price has higher priority. If prices are equal, earlier timestamp has higher priority.
    This is implemented using lambda functions as comparators in the constructor.
    */

    OrderBook();
    void addOrder(Order* order);
    Order* topBuy();
    Order* topSell();
    void popBuy();
    void popSell();
};
