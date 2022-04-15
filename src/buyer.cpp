#include "buyer.h"

void Buyer::ShowCars(std::ostream &out) const {
    for (const auto &car : cars_) {
        car->Show(out);
    }
}

void Buyer::Buy(std::unique_ptr<Car> &&car) {
    cars_.push_back(std::move(car));
}