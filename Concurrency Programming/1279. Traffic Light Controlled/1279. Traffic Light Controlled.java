class TrafficLight {
    private int greenLight = 1; // 1表示roadA绿灯、roadB红灯，2表示roadA红灯、roadB绿灯
    private ReentrantLock lightLock = new ReentrantLock();
    
    public synchronized void carArrived(
        int carId,           // ID of the car
        int roadId,          // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,       // Direction of the car
        Runnable turnGreen,  // Use turnGreen.run() to turn light to green on current road
        Runnable crossCar    // Use crossCar.run() to make car cross the intersection 
    ) {
        if(greenLight != roadId)
        {
            turnGreen.run();
            greenLight = roadId;
        }
        crossCar.run();
    }
}
