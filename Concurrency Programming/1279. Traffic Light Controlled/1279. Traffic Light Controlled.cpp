#include <mutex>

class TrafficLight {
private:
    int greenLight = 1; // 1表示roadA绿灯、roadB红灯，2表示roadA红灯、roadB绿灯
    std::mutex mtx;
public:
    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    ) {
        std::lock_guard<std::mutex> lock(mtx);
        if(greenLight != roadId)
        {
            turnGreen();
            greenLight = roadId;
        }
        crossCar();
    }
};
