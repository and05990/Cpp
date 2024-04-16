#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time

    double bitcoinValue = 10000.0; // Starting value of Bitcoin
    double volatility = 0.01; // Volatility factor (percentage change per update)

    while (true)
    {
        // Generate a random percentage change in the Bitcoin value
        double percentageChange = (rand() % 200 - 100) / 100.0 * volatility;

        // Update the Bitcoin value
        bitcoinValue *= (1.0 + percentageChange);

        // Print the updated Bitcoin value
        cout << "Bitcoin value: $" << bitcoinValue << endl;

        // Wait for 3 seconds before updating again
        using namespace std::chrono;
        this_thread::sleep_for(seconds(3));
    }

    return 0;
}
