#include <iostream>
#include <string>
#include <unistd.h>  // For sleep (to simulate delay in super loop)

// Function prototypes
int get_time_interval();
void set_time_interval(int);

// Define the command string at compile time
#define COMMAND_STR "set_sensor_time_interval"  

// Simulate the existing static time_interval handling
static int time_interval = 10;

// Function to retrieve the current time_interval value
int get_time_interval() {
    return time_interval;
}

// Function to set a new time_interval value
void set_time_interval(int new_time_interval) {
    time_interval = new_time_interval;
}

class GatewayAgentManager {
public:
    void ExecuteCloudCommand(const std::string& commandStr) {
        // Use the commandStr defined at compile time
        if (commandStr == COMMAND_STR) {
            int new_time_interval;
            std::cout << "GatewayAgentManager :: Enter new time_interval value: ";
            std::cin >> new_time_interval;

            // Set the new time_interval value
            set_time_interval(new_time_interval);
            std::cout << "GatewayAgentManager :: Updated time_interval: " << get_time_interval() << std::endl;
        }
        else {
            std::cout << "GatewayAgentManager ::Invalid command.\n";
        }
    }
};

int main() {
    GatewayAgentManager m_gatewayAgentManagerObj;
    std::string commandStr;

    while (true) {
       
        std::string commandStr = "set_sensor_time_interval";
       
        // Execute the command (using the compile-time defined commandStr)
        m_gatewayAgentManagerObj.ExecuteCloudCommand(commandStr);

        // Simulate a small delay before the next loop iteration (optional)
        sleep(1); // Sleep for 1 second
    }

    std::cout << "Program has exited." << std::endl;
    return 0;
}

