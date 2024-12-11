// Johannes Ylinen
// HarjoitusTyö

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

// Varmistus ohjelma
int getValidatedInput(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value < min || value > max) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number between " << min << " and " << max << ".\n";
        }
        else {
            return value;
        }
    }
}

// Aliohjelma varauksille
int reserveRoom(std::vector<bool>& rooms) {
    while (true) {
        int roomNumber = getValidatedInput("Select a room number: ", 1, rooms.size());
        if (!rooms[roomNumber - 1]) {
            rooms[roomNumber - 1] = true;
            std::cout << "Room " << roomNumber << " successfully reserved!\n";
            return roomNumber;
        }
        else {
            std::cout << "Room " << roomNumber << " is already reserved. Please select another room.\n";
        }
    }
}

int main() {
    std::srand(std::time(0));

    // Huoneiden määrä (30-70) ja hinta (80-100)
    int totalRooms = std::rand() % 41 + 30;
    int roomPrice = std::rand() % 21 + 80;

    std::vector<bool> rooms(totalRooms, false); // Tarkistaa jo varatut huoneet

    std::cout << "The hotel has " << totalRooms << " rooms.\n";
    std::cout << "The room price is " << roomPrice << " euros per night.\n";

    char continueBooking;
    do {
        int roomNumber = reserveRoom(rooms);

        int nights = getValidatedInput("How many nights do you want to book? ", 1, 100);

        int totalCost = nights * roomPrice;
        std::cout << "Room " << roomNumber << " booked for " << nights << " night(s). Total cost: " << totalCost << " euros.\n";

        // Kysyy toisen huoneen varauksesta
        std::cout << "Would you like to book another room? (y/n): ";
        std::cin >> continueBooking;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (continueBooking == 'y' || continueBooking == 'Y');

    std::cout << "Thank you for choosing our hotel!\n";
    return 0;
}
