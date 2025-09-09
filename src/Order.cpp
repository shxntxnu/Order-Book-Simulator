/*
So far this file does the following:
- Defines the Order class with attributes for id, side, price, quantity, and timestamp.
- Implements a constructor to initialize these attributes.

Further work includes:
- Adding methods for order comparison based on price and timestamp to facilitate priority queue operations.
*/

#include "Order.hpp"

Order::Order(int id, OrderSide side, double price, int quantity):
    id(id), side(side), price(price), quantity(quantity),
    timestamp(std::chrono::high_resolution_clock::now()) {
        // Constructor initializes order attributes and sets the timestamp to the current time
        // this can be auto assigned via a static variable or system clock
    }