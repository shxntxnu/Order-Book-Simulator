/*
So far this file does the following:
- Defines the MatchingEngine class that uses OrderBook and TradeLogger.
- Implements a method to match incoming orders against the order book and log trades.

Further work includes:
- Enhancing matching logic to handle edge cases and improve efficiency.
*/

#pragma once
#include "OrderBook.hpp"
#include "TradeLogger.hpp"

class MatchingEngine {
public:
    OrderBook* orderBook;
    TradeLogger* logger;

    MatchingEngine(OrderBook* ob, TradeLogger* tl);
    void match(Order* incomingOrder);
};