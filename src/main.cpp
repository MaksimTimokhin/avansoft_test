#include <iostream>

#include "car.h"
#include "buyer.h"
#include "showroom.h"
#include "car_generator.h"

void FillShowroom(Showroom &s, size_t count);
void RunLoop(Showroom &s, Buyer &b, std::istream &in, std::ostream &out);

int main() {
    Showroom s;
    FillShowroom(s, 10);
    Buyer b;
    RunLoop(s, b, std::cin, std::cout);
    return 0;
}

void FillShowroom(Showroom &s, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        s.AddCar(CarGenerator::GenerateCar());
    }
}

std::string ReadCommand(std::istream &in) {
    std::string command;
    in >> command;
    return command;
}

void ShowHelp(std::ostream &out) {
    out << "help -- show this message\n";
    out << "list -- list available cars\n";
    out << "color <color> -- list cars of given color\n";
    out << "speed <speed> -- list cars with speed at least given\n";
    out << "price <price> -- list cars cheaper than given price\n";
    out << "buy <id> -- buy car with given id\n";
    out << "owned -- list owned cars\n";
    out << "exit -- exit showroom" << std::endl;
}

void RunLoop(Showroom &s, Buyer &b, std::istream &in, std::ostream &out) {
    while (true) {
        out << "> ";
        auto command = ReadCommand(in);
        if (command == "help") {
            ShowHelp(out);
        } else if (command == "list") {
            s.ShowAll(out);
        } else if (command == "color") {
            std::string color;
            in >> color;
            s.ShowByColor(color, out);
        } else if (command == "speed") {
            unsigned int speed;
            in >> speed;
            s.ShowBySpeed(speed, out);
        } else if (command == "price") {
            unsigned int price;
            in >> price;
            s.ShowByPrice(price, out);
        } else if (command == "buy") {
            unsigned int id;
            in >> id;
            auto car = s.SellCar(id);
            if (!car) {
                out << "no car with given id found" << std::endl;
                continue;
            }
            b.Buy(std::move(car));
        } else if (command == "owned") {
            b.ShowCars(out);
        } else if (command == "exit") {
            break;
        }else {
            out << "unknown command" << std::endl;
        }
    }
}
