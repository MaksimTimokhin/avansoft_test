add_executable(car_showroom main.cpp)
target_sources(car_showroom PRIVATE
                car.cpp
                buyer.cpp
                showroom.cpp
                car_generator.cpp)