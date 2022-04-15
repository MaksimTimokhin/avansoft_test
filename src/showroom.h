#pragma once

#include <unordered_map>
#include <memory>
#include <ostream>

#include "car.h"

class Showroom {
public:
    void AddCar(std::unique_ptr<Car> &&car);
    std::unique_ptr<Car> SellCar(unsigned int id);

    void ShowAll(std::ostream &out) const;
    void ShowByColor(const std::string &color, std::ostream &out) const;
    void ShowBySpeed(unsigned int speed, std::ostream &out) const;
    void ShowByPrice(unsigned int price, std::ostream &out) const;

private:
    std::unordered_map<unsigned int, std::unique_ptr<Car>> cars_;
};
