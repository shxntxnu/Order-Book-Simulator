/*
So far this file does the following:
- Defines the TradeLogger class with a method to log trades between buy and sell orders.
- Implements a method to log trade details including order IDs, price, and quantity.

Further work includes:
- Expanding logging capabilities to include timestamps and trade history storage.
*/

#pragma once
#include "Order.hpp"

class TradeLogger {
public:
    void logTrade(Order* buy, Order* sell, int quantity);
};