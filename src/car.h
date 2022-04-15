#pragma once

#include <ostream>

class Car {
public:
    Car(unsigned int id, const std::string &color, unsigned int speed, unsigned int price);

    unsigned int GetID() const;
    std::string GetColor() const;
    unsigned int GetSpeed() const;
    unsigned int GetPrice() const;

    void Show(std::ostream &out) const;

private:
    unsigned int id_;
    std::string color_;
    unsigned int speed_;
    unsigned int price_;
};