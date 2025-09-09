/*
So far this file does the following:
- Defines the TradeLogger class with a method to log trades between buy and sell orders.
- Implements a method to log trade details including order IDs, price, and quantity.

Further work includes:
- Expanding logging capabilities to include timestamps and trade history storage.
*/

#include <iostream>
#include "TradeLogger.hpp"

void TradeLogger::logTrade(Order* buy, Order* sell, int quantity) {
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(sell->timestamp.time_since_epoch()).count();
    
    std::cout << "Trade executed: Buy ID " << buy->id
              << " Sell ID " << sell->id
              << " Price " << sell->price
              << " Quantity " << quantity
              << " Timestamp(ms) " << time
              << std::endl;
}