/*
This is a simplified version of the core component used in stock exchanges to match buy and sell orders.

Skills used to make this program include:

Data Structures: Priority queues (heaps), hash maps, linked lists.
Algorithms: Matching logic, time complexity optimization.
Finance relevance: Understanding of market microstructure, limit orders, and trade execution.

Bonus: Add support for market orders, partial fills, and real-time trade logging.

Steps to create this program:
1. Define Order Structure: Create a structure to represent an order with attributes like order ID, type (buy/sell), price, quantity, and timestamp.
2. Order Book Class: Implement an OrderBook class that maintains two priority queues (heaps) for buy and sell orders. The buy orders should be sorted in descending order of price, while sell orders should be sorted in ascending order.
3. Add Order Method: Implement a method to add new orders to the order book. This method should insert the order into the appropriate priority queue based on its type.
4. Match Orders Method: Implement a method to match buy and sell orders. This method should continuously check the top of both priority queues and execute trades when the highest buy price is greater than or equal to the lowest sell price. Update quantities accordingly and remove fully filled orders from the queues.
5. Trade Execution: When a match is found, log the trade details (price, quantity, order IDs) and update the order book.
6. Main Function: Create a main function to simulate adding orders and matching them, demonstrating the functionality of the order book.
*/