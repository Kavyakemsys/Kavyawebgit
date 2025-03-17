#include <iostream>

// Existing MQTTRequestResponseManager class
class MQTTRequestResponseManager {
public:
    // The time_interval variable is initialized to 10
    static int time_interval;

    // Function to set a new value to time_interval
    static void setTimeInterval(int new_time_interval) {
        std::cout << "*********************************************************** " << std::endl;
        std::cout << "MQTTRequestResponseManager :: old time_interval value: " << time_interval << std::endl;
        time_interval = new_time_interval;
        std::cout << " MQTTRequestResponseManager :: Enter new time_interval value: " << time_interval << std::endl;
        std::cout << "*********************************************************** " << std::endl;
    }

    // Function to get the current value of time_interval
    static int getTimeInterval() {
        return time_interval;
    }
};

// Initialize the static time_interval variable to 10
int MQTTRequestResponseManager::time_interval = 10;

// New CommunicatorManager class
class CommunicatorManager {
public:
    // Pointer to MQTTRequestResponseManager
    MQTTRequestResponseManager *m_mqttRequestResponseObj;

    // Constructor
    CommunicatorManager() {
        // Initialize the pointer to a new instance of MQTTRequestResponseManager
        m_mqttRequestResponseObj = new MQTTRequestResponseManager();
    }

    // Destructor to clean up the dynamically allocated memory
    ~CommunicatorManager() {
        delete m_mqttRequestResponseObj;
    }

    // Function to interact with MQTTRequestResponseManager through the pointer
    void updateTimeInterval(int new_time_interval) {
        m_mqttRequestResponseObj->setTimeInterval(new_time_interval);
    }

    // Function to retrieve current time_interval
    int getCurrentTimeInterval() {
        return m_mqttRequestResponseObj->getTimeInterval();
    }
};

// Export the functions for use in the shared object (C linkage)
extern "C" {
    // Function to retrieve the current value of time_interval
    int get_time_interval() {
        return MQTTRequestResponseManager::getTimeInterval();
    }

    // Function to set a new value for time_interval
    void set_time_interval(int new_time_interval) {
        MQTTRequestResponseManager::setTimeInterval(new_time_interval);
    }
}

int main() {
    // Create an instance of CommunicatorManager
    CommunicatorManager commManager;

    // Use the CommunicatorManager to update and retrieve the time_interval
    std::cout << "CommunicatorManager :: Initial time_interval: " << commManager.getCurrentTimeInterval() << std::endl;

    commManager.updateTimeInterval(30);  // Update the time_interval to 30
    std::cout << "CommunicatorManager :: Updated time_interval: " << commManager.getCurrentTimeInterval() << std::endl;

    return 0;
}

