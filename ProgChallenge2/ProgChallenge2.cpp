#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

double startX, startY, velX, velY, accelX, accelY, timeSeconds, currentTime;
long long timestep; // for time

class UserInput {
public:
    void run() {
        std::cout << "Starting X: ";
        std::cin >> startX;
        std::cout << "Starting Y: ";
        std::cin >> startY;
        std::cout << "Starting Velocity X: ";
        std::cin >> velX;
        std::cout << "Starting Velocity Y: ";
        std::cin >> velX;
        std::cout << "Acceleration X: ";
        std::cin >> accelX;
        std::cout << "Acceleration Y: ";
        std::cin >> accelY;
        std::cout << "Timestep (Seconds): ";
        std::cin >> timeSeconds;

        timestep = timeSeconds * 1000; // milliseconds for time
        currentTime = timestep / 1000; // in seconds

        std::cout << "\n\n";
    }
};

int main()
{
    UserInput input;
    
    input.run();

    while (true) {
        double x = startX + (velX * currentTime) + (0.5 * accelX * (currentTime * currentTime));
        double y = startY + (velY * currentTime) + (0.5 * accelY * (currentTime * currentTime));

        double vx = velX + (accelX * currentTime);
        double vy = velY + (accelY * currentTime);

        
        std::cout << "Time: " << currentTime << " Seconds" << std::endl;
        std::cout << "At = (" << x << ", " << y << ")" << std::endl;
        std::cout << "Velocity = (" << vx << ", " << vy << ")" << std::endl << std::endl;
        

        std::cout << std::fixed << std::setprecision(3);

        currentTime += timeSeconds;

        std::this_thread::sleep_for(std::chrono::milliseconds(timestep));

    }

    return 0;
}
