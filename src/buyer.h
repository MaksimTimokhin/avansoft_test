#pragma once

#include <vector>
#include <memory>
#include <ostream>

#include "car.h"

class Buyer {
public:
    void ShowCars(std::ostream &out) const;
    void Buy(std::unique_ptr<Car> &&car);

private:
    std::vector<std::unique_ptr<Car>> cars_;
};