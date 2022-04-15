#pragma once

#include <memory>

#include "car.h"

class CarGenerator{
public:
    static std::unique_ptr<Car> GenerateCar();
};