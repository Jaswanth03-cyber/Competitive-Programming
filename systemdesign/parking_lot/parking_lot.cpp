#include <bits/stdc++.h>
using namespace std ;

/*
https://lldcoding.com/design-lld-a-parking-lot-machine-coding-interview
*/

/*
above is a good design instead of enum use abstract classes and inheritence like this 
*/
class Payment {
  public:
    virtual double calculateCost(double hours) = 0;
};

class CarPayment : public Payment {
  public:
    double calculateCost(double hours) { return hours * 2; }
};

class BikePayment : public Payment {
  public:
    double calculateCost(double hours) { return hours * 1; }
};

class HandicappedPayment : public Payment {
  public:
    double calculateCost(double hours) { return 0; }
};

class Vehicle {
  protected:
    Payment* payment;
    std::chrono::time_point<std::chrono::system_clock> parkedTime;

  public:
    virtual std::string getType() = 0;
    virtual double calculateCost(double hours) {
        return payment->calculateCost(hours);
    }

    void setParkedTime() {
        parkedTime = std::chrono::system_clock::now();
    }

    std::chrono::time_point<std::chrono::system_clock> getParkedTime() {
        return parkedTime;
    }
};


class Car : public Vehicle {
  public:
    Car() { payment = new CarPayment(); }
    std::string getType() { return "Car"; }
};

class Bike : public Vehicle {
  public:
    Bike() { payment = new BikePayment(); }
    std::string getType() { return "Bike"; }
};

class HandicappedVehicle : public Vehicle {
  public:
    HandicappedVehicle() { payment = new HandicappedPayment(); }
    std::string getType() { return "Handicapped"; }
};

class ParkingLot {
  private:
    std::vector<std::vector<std::vector<Vehicle*>>> spots;
    int floors;
    int rows;
    int spotsPerRow;

  public:
    ParkingLot(int floors, int rows, int spotsPerRow) {
        this->floors = floors;
        this->rows = rows;
        this->spotsPerRow = spotsPerRow;
        spots.resize(floors);
        for (int i = 0; i < floors; i++) {
            spots[i].resize(rows);
            for (int j = 0; j < rows; j++) {
                spots[i][j].resize(spotsPerRow);
            }
        }
    }


/*
assigning a parking spot is done different here the parking spot we are giving the floor number, row and spot 
rather than that for each floor we need to maintain a hashmap of type of the vehicle and the spots we will get 
have which spots are empty which spots are occupied we can have an algorithm which parking spot to give 
*/

    bool park(Vehicle* v, int floor, int row, int spot) {
        if (spots[floor][row][spot] == nullptr) {
            spots[floor][row][spot] = v;
            std::cout << v->getType() << " parked successfully at floor " << floor << ", row " << row << ", spot " << spot << "." << std::endl;
            return true;
        } else {
            std::cout << "Spot already occupied." << std::endl;
            return false;
        }
    }

    bool leave(Vehicle* v) {
        for (int i = 0; i < floors; i++) {
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < spotsPerRow; k++) {
                    if (spots[i][j][k] == v){
                        double hours = calculateHoursParked(spots[i][j][k]);
                        double cost = spots[i][j][k]->calculateCost(hours);
                        spots[i][j][k] = nullptr;
                        std::cout << v->getType() << " left successfully. Total cost: " << cost << std::endl;
                        return true;
                    }
                }
            }
        }
        std::cout << v->getType() << " not found." << std::endl;
        return false;
    }

    int availableSpots(int floor) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < spotsPerRow; j++) {
            if (spots[floor][i][j] == nullptr) {
                count++;
            }
        }
    }
    return count;
}

    int handicappedSpots(int floor) {
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < spotsPerRow; j++) {
                if (dynamic_cast<HandicappedVehicle*>(spots[floor][i][j]) != nullptr) {
                    count++;
                }
            }
        }
        return count;
    }

    double calculateHoursParked(Vehicle* v) {
        for (int i = 0; i < floors; i++) {
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < spotsPerRow; k++) {
                    if (spots[i][j][k] == v) {
                        // get the current time
                        auto now = std::chrono::system_clock::now();
                        // get the time the vehicle was parked
                        auto parkedTime = spots[i][j][k]->getParkedTime();
                        // calculate the difference in hours
                        auto duration = std::chrono::duration_cast<std::chrono::hours>(now - parkedTime);
                        return duration.count();
                    }
                }
            }
        }
        return 0;
    }
};


int main() {
    ParkingLot lot(3, 10, 20);
    Car car1, car2;
    Bike bike1, bike2;
    HandicappedVehicle hv1;

    car1.setParkedTime();
    lot.park(&car1, 0, 0, 0);
    car2.setParkedTime();
    lot.park(&car2, 0, 0, 1);
    bike1.setParkedTime();
    lot.park(&bike1, 0, 0, 2);
    hv1.setParkedTime();
    lot.park(&hv1, 2, 9, 19);

    std::cout << "Available spots on floor 0: " << lot.availableSpots(0) << std::endl;
    std::cout << "Handicapped spots on floor 2: " << lot.handicappedSpots(2) << std::endl;

    lot.leave(&car1);
    lot.leave(&bike2);

    std::cout << "Available spots on floor 0: " << lot.availableSpots(0) << std::endl;

    return 0;
}