#include "car_generator.h"

#include <array>
#include <random>

std::unique_ptr<Car> CarGenerator::GenerateCar() {
    static unsigned int id = 0;
    static std::random_device seed_gen;
    static std::mt19937 gen(seed_gen());
    static std::array<std::string, 6> colors = {"black", "blue", "yellow", "red", "green", "white"};
    
    std::uniform_int_distribution<unsigned int> color_dist(0, 5);
    std::uniform_int_distribution<unsigned int> speed_dist(80, 240);
    std::uniform_int_distribution<unsigned int> price_dist(2000, 5000);
    return std::make_unique<Car>(id++, colors[color_dist(gen)], speed_dist(gen), price_dist(gen));
}