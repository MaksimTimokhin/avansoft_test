#include "showroom.h"

void Showroom::AddCar(std::unique_ptr<Car> &&car) {
    cars_[car->GetID()] = std::move(car);
}

std::unique_ptr<Car> Showroom::SellCar(unsigned int id) {
    if (!cars_.count(id)) {
        return std::unique_ptr<Car>();
    }
    auto car = std::move(cars_[id]);
    cars_.erase(id);
    return car;
}

void Showroom::ShowAll(std::ostream &out) const {
    for (const auto &[_, car] : cars_) {
        car->Show(out);
    }
}

void Showroom::ShowByColor(const std::string &color, std::ostream &out) const {
    for (const auto &[_, car] : cars_) {
        if (car->GetColor() == color) {
            car->Show(out);
        }
    }
}

void Showroom::ShowBySpeed(unsigned int speed, std::ostream &out) const {
    for (const auto &[_, car] : cars_) {
        if (car->GetSpeed() >= speed) {
            car->Show(out);
        }
    }
}

void Showroom::ShowByPrice(unsigned int price, std::ostream &out) const {
    for (const auto &[_, car] : cars_) {
        if (car->GetPrice() <= price) {
            car->Show(out);
        }
    }
}