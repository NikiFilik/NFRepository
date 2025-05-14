#include "IPropertyChangedListener.hpp"
#include "INotifyDataChanged.hpp"

#include "IPropertyChangingListener.hpp"
#include "INotifyDataChanging.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace nf {
	class Car : public nf::INotifyDataChanged {
    private:
        std::vector<nf::IPropertyChangedListener*> propertyChangedListeners;

        std::string brand;
        int maxSpeed = 0;

    public:
        void addPropertyChangedListener(nf::IPropertyChangedListener* listener) override {
            this->propertyChangedListeners.push_back(listener);
        }

        void removePropertyChangedListener(nf::IPropertyChangedListener* listener) override {
            auto iter = std::find(this->propertyChangedListeners.begin(), this->propertyChangedListeners.end(), listener);

            if (iter != this->propertyChangedListeners.end()) {
                this->propertyChangedListeners.erase(iter);
            }
        }

        void setBrand(const std::string& brand) {
            if (this->brand == brand) return;

            this->brand = brand;
            for (auto listener : this->propertyChangedListeners) {
                listener->onPropertyChanged(this, "brand");
            }
        }

        void setMaxSpeed(int maxSpeed) {
            if (this->maxSpeed == maxSpeed) return;

            this->maxSpeed = maxSpeed;
            for (auto listener : this->propertyChangedListeners) {
                listener->onPropertyChanged(this, "maxSpeed");
            }
        }

        std::string getBrand() const {
            return brand;
        }

        int getMaxSpeed() const {
            return maxSpeed;
        }
	};



    class Train : public nf::INotifyDataChanging {
    private:
        std::vector<nf::IPropertyChangingListener*> propertyChangingListeners;

        std::string destination;
        int numOfCars = 0;

    public:
        void addPropertyChangingListener(nf::IPropertyChangingListener* listener) override {
            this->propertyChangingListeners.push_back(listener);
        }

        void removePropertyChangingListener(nf::IPropertyChangingListener* listener) override {
            auto iter = std::find(this->propertyChangingListeners.begin(), this->propertyChangingListeners.end(), listener);

            if (iter != this->propertyChangingListeners.end()) {
                this->propertyChangingListeners.erase(iter);
            }
        }

        void setDestination(const std::string& destination) {
            if (this->destination == destination) return;

            for (auto listener : this->propertyChangingListeners) {
                if (!listener->onPropertyChanging(this, "destination", this->destination, destination)) {
                    return;
                }
            }

            this->destination = destination;
        }

        void setNumOfCars(int numOfCars) {
            if (this->numOfCars == numOfCars) return;

            for (auto listener : this->propertyChangingListeners) {
                if (!listener->onPropertyChanging(this, "numOfCars", this->numOfCars, numOfCars)) {
                    return;
                }
            }

            this->numOfCars = numOfCars;
        }

        std::string getDestination() const {
            return destination;
        }
        int getNumOfCars() const {
            return numOfCars;
        }
    };



    class BrandChangedListener : public nf::IPropertyChangedListener {
    public:
        void onPropertyChanged(nf::INotifyDataChanged* object, const std::string& propertyName) override {
            if (propertyName != "brand") return;

            Car* car = dynamic_cast<Car*>(object);
            if (!car) return;

            std::cout << "[BrandChangedListener] Brand changed to: " << car->getBrand() << "\n";
        }
    };

    class MaxSpeedChangedListener : public nf::IPropertyChangedListener {
    public:
        void onPropertyChanged(nf::INotifyDataChanged* object, const std::string& propertyName) override {
            if (propertyName != "maxSpeed") return;

            Car* car = dynamic_cast<Car*>(object);
            if (!car) return;

            std::cout << "[MaxSpeedChangedListener] MaxSpeed changed to: " << car->getMaxSpeed() << "\n";
        }
    };



    class DestinationValidator : public nf::IPropertyChangingListener {
    public:
        bool onPropertyChanging(nf::INotifyDataChanging* object, const std::string& propertyName, const std::any& oldValue, const std::any& newValue) override {
            if (propertyName != "destination") return true;

            try {
                std::string newDestination = std::any_cast<std::string>(newValue);

                if (newDestination.empty()) {
                    std::cout << "[DestinationValidator] Destination cannot be empty!\n";
                    return false;
                }

                std::cout << "[DestinationValidator] Destination changed to: " << newDestination << "\n";
                return true;
            }
            catch (const std::bad_any_cast&) {
                std::cout << "[DestinationValidator] Type error!\n";
                return false;
            }
        }
    };

    class NumOfCarsValidator : public nf::IPropertyChangingListener {
    public:
        bool onPropertyChanging(nf::INotifyDataChanging* object, const std::string& propertyName, const std::any& oldValue, const std::any& newValue) override {
            if (propertyName != "numOfCars") return true;

            try {
                int newNumOfCars = std::any_cast<int>(newValue);

                if (newNumOfCars < 0) {
                    std::cout << "[NumOfCarsValidator] NumOfCars cannot be less than zero!\n";
                    return false;
                }

                std::cout << "[NumOfCarsValidator] NumOfCars changed to: " << newNumOfCars << "\n";
                return true;
            }
            catch (const std::bad_any_cast&) {
                std::cout << "[NumOfCarsValidator] Type error!\n";
                return false;
            }
        }
    };
}

int main() {
    nf::Car car;

    nf::BrandChangedListener brandChangedListener;
    nf::MaxSpeedChangedListener maxSpeedChangedListener;

    car.addPropertyChangedListener(&brandChangedListener);
    car.addPropertyChangedListener(&maxSpeedChangedListener);

    car.setBrand("Ferrari");
    car.setMaxSpeed(300);



    nf::Train train;

    nf::DestinationValidator destinationValidator;
    nf::NumOfCarsValidator numOfCarsValidator;

    train.addPropertyChangingListener(&destinationValidator);
    train.addPropertyChangingListener(&numOfCarsValidator);

    train.setDestination("Kaliningrad");
    train.setNumOfCars(-1);

    train.setDestination("");
    train.setNumOfCars(10);

	return 0;
}