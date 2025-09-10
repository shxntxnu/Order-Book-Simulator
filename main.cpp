/*
This is a simplified version of the core component used in stock exchanges to match buy and sell orders.

Skills used to make this program include:

Data Structures: Priority queues (heaps), hash maps, linked lists.
Algorithms: Matching logic, time complexity optimization.
Finance relevance: Understanding of market microstructure, limit orders, and trade execution.

Bonus: Add support for market orders, partial fills, and real-time trade logging.

*** Steps to create this program ***

1. Define Order Structure: Create a structure to represent an order with attributes like order ID, type (buy/sell), price, quantity, and timestamp.
        This is done in Order.hpp and Order.cpp by defining the Order class and its constructor to initialize these attributes.
2. Order Book Class: Implement an OrderBook class that maintains two priority queues (heaps) for buy and sell orders. The buy orders should be sorted in descending order of price, while sell orders should be sorted in ascending order.
        This is done in OrderBook.hpp and OrderBook.cpp using std::function for custom comparators and priority_queue for the heaps.
3. Add Order Method: Implement a method to add new orders to the order book. This method should insert the order into the appropriate priority queue based on its type.
        This is done in OrderBook.cpp using the addOrder method to push orders into the correct queue.
4. Match Orders Method: Implement a method to match buy and sell orders. This method should continuously check the top of both priority queues and execute trades when the highest buy price is greater than or equal to the lowest sell price. Update quantities accordingly and remove fully filled orders from the queues.
        This is done in MatchingEngine.hpp and MatchingEngine.cpp using the match method to handle the matching logic.
5. Trade Execution: When a match is found, log the trade details (price, quantity, order IDs) and update the order book.
        This is done in TradeLogger.hpp and TradeLogger.cpp using the logTrade method to print trade details to the console.
6. Main Function: Create a main function to simulate adding orders and matching them, demonstrating the functionality of the order book.
*/

#include "include/Order.hpp"
#include "include/OrderBook.hpp"
#include "include/MatchingEngine.hpp"
#include "include/TradeLogger.hpp"
#include <iostream>

using namespace std;

int main() {
    OrderBook ob;
    TradeLogger logger;
    MatchingEngine engine(&ob, &logger);

    // Simulate adding and matching orders
    // Order(id, side, price, quantity)
    Order* o1 = new Order(1, OrderSide::BUY, 100.0, 10);   // Buy 10 @ 100
    Order* o2 = new Order(2, OrderSide::SELL, 99.0, 5);    // Sell 5 @ 99
    Order* o3 = new Order(3, OrderSide::SELL, 100.0, 10);  // Sell 10 @ 100

    // Matching engine will match orders and log trades
    engine.match(o1); // Should not match yet (no sell orders)
    engine.match(o2); // Should match with o1 (partial fill)
    engine.match(o3); // Should match remaining o1 and add rest to book

    // Optionally, print remaining orders in the book
    if (ob.topBuy()) {
        cout << "Remaining Buy Order: ID " << ob.topBuy()->id << " Qty " << ob.topBuy()->quantity << endl;
    }
    if (ob.topSell()) {
        cout << "Remaining Sell Order: ID " << ob.topSell()->id << " Qty " << ob.topSell()->quantity << endl;
    }

    return 0;
}