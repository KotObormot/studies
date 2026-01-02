// https://www.youtube.com/watch?v=nZNcRRXeKTk&t=430s
// Observer

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class IObserver {
  public:
    virtual void update(float temperature) = 0;
    virtual ~IObserver() = default;
};

class WeatherStation {
  private:
    std::vector<std::weak_ptr<IObserver>> observers;
    float temperature;
  public:
    void registerObserver(std::shared_ptr<IObserver> observer) {
        observers.push_back(observer);
    }
    void notifyObservers() {
        for(auto it(observers.begin()); it != observers.end(); ++it) {
            if(auto observer = it->lock()) {
                observer->update(temperature);
            }
        }
    }
    void setTemperature(float temp) {
        this->temperature = temp;
        notifyObservers();
    }
};

class PhoneDislay : public IObserver {
    void update(float temperature) override {
        std::cout << "Temperature:\t" << temperature << "\n";
    } 
};

int main() {
    auto weatherStation = std::make_shared<WeatherStation>();

    {
        auto phoneDisplay = std::make_shared<PhoneDislay>();
        weatherStation->registerObserver(phoneDisplay);

        for(int i(0); i < 10; ++i) {
            weatherStation->setTemperature(i + 1);
        }
    }
    std::cout << "\n================\n";

    weatherStation->setTemperature(20);
    
    return 0;
}