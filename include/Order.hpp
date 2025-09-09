/*
So far, this file does the following:
- Defines the Order class with attributes for id, side, price, quantity, and timestamp.
- Implements a constructor to initialize these attributes.

Further work includes:
- Adding methods for order comparison based on price and timestamp to facilitate priority queue operations. Do this by overloading comparison operators in the Order class.
*/

#pragma once
#include <string>
#include <chrono>

enum class OrderSide { BUY, SELL };

class Order {
public:
    int id;
    OrderSide side;
    double price;
    int quantity;
    std::chrono::time_point<std::chrono::high_resolution_clock> timestamp;

    Order(int id, OrderSide side, double price, int quantity);

    // Comparison operators for sorting (not used by priority_queue directly, but useful for testing and extension)
    bool operator<(const Order& other) const {
        if (price != other.price)
            return price < other.price;
        return timestamp > other.timestamp; // earlier timestamp = higher priority
    }
    bool operator>(const Order& other) const {
        if (price != other.price)
            return price > other.price;
        return timestamp < other.timestamp;
    }
};
