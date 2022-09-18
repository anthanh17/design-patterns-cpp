#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <vector>

enum class AnimalType {
    CAT = 1,
    DOG,
    MOUSE
};

class Animal {
public:
    Animal() = default;
    virtual ~Animal() = default;
    virtual std::string getFood() = 0;
    virtual std::size_t getPrice() = 0;
};

class Cat final : public Animal {
public:
    Cat() = default;
    ~Cat() = default;
    std::string getFood() override {
        return "ngot";
    }
    std::size_t getPrice() override {
        return 5;
    }
};

class Dog final : public Animal {
public:
    Dog() = default;
    ~Dog() = default;
    std::string getFood() override {
        return "chua";
    }
    std::size_t getPrice() override {
        return 10;
    }
};

class Mouse final : public Animal {
public:
    Mouse() = default;
    ~Mouse() = default;
    std::string getFood() override {
        return "cay";
    }
    std::size_t getPrice() override {
        return 3;
    }
};

class FactoryMethod {
public:
    static std::unique_ptr<Animal> createAnimal(AnimalType type) {
        switch(type) {
            case AnimalType::CAT :{
                return std::make_unique<Cat>();
            } break;

            case AnimalType::DOG :{
                return std::make_unique<Dog>();
            } break;

            case AnimalType::MOUSE :{
                return std::make_unique<Mouse>();
            } break;
        }
    }
};

int main() {
    std::string input{};
    getline(std::cin, input);       // cin -> input

    int sum{};
    std::vector<int> numbers{};

    int number{};
    std::stringstream iss(input);   // input -> iss
    while(iss >> number) {          // split space iss -> number
        numbers.push_back(number);
        auto animal = FactoryMethod::createAnimal(static_cast<AnimalType>(number));
        std::cout << animal->getFood() << " ";
        sum += animal->getPrice();
    }
    std::cout << "\n" << sum;
    return 0;
}