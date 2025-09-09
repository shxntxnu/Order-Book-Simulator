/*
So far this file does the following:
- Defines the MatchingEngine class that uses OrderBook and TradeLogger.
- Implements a method to match incoming orders against the order book and log trades.

Further work includes:
- Enhancing matching logic to handle edge cases and improve efficiency.
*/

#include "MatchingEngine.hpp"

MatchingEngine::MatchingEngine(OrderBook* ob, TradeLogger* tl)
    : orderBook(ob), logger(tl) {}

void MatchingEngine::match(Order* incomingOrder) {
    if (incomingOrder->side == OrderSide::BUY) {
        while (orderBook->topSell() && incomingOrder->quantity > 0 && orderBook->topSell()->price <= incomingOrder->price) {
            Order* bestSell = orderBook->topSell();
            int tradedQty = std::min(incomingOrder->quantity, bestSell->quantity);
            logger->logTrade(incomingOrder, bestSell, tradedQty);
            incomingOrder->quantity -= tradedQty;
            bestSell->quantity -= tradedQty;
            if (bestSell->quantity == 0) orderBook->popSell();
        }
    } else {
        while (orderBook->topBuy() && incomingOrder->quantity > 0 && orderBook->topBuy()->price >= incomingOrder->price) {
            Order* bestBuy = orderBook->topBuy();
            int tradedQty = std::min(incomingOrder->quantity, bestBuy->quantity);
            logger->logTrade(bestBuy, incomingOrder, tradedQty);
            incomingOrder->quantity -= tradedQty;
            bestBuy->quantity -= tradedQty;
            if (bestBuy->quantity == 0) orderBook->popBuy();
        }
    }

    // If not fully filled, add remaining to order book; else, delete to avoid memory leak
    if (incomingOrder->quantity > 0) {
        orderBook->addOrder(incomingOrder);
    } else {
        delete incomingOrder; // Clean up if fully matched
    }
}
