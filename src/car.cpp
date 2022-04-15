#include "car.h"

Car::Car(unsigned int id, const std::string &color, unsigned int speed, unsigned int price) :
    id_(id), color_(color), speed_(speed), price_(price) {}

unsigned int Car::GetID() const {
    return id_;
}

std::string Car::GetColor() const {
    return color_;
}

unsigned int Car::GetSpeed() const {
    return speed_;
}

unsigned int Car::GetPrice() const {
    return price_;
}

void Car::Show(std::ostream &out) const {
    out << GetID() << ' ' << GetColor() << ' ' << GetSpeed() << "km/h " << GetPrice() << "$\n";
}