#include <iostream>

class Animal {
protected:
    std::string animalType;
public:
    std::string getType() {
        return animalType;
    }
    virtual void voice(Animal*) = 0;
};

class Dog: public Animal {
public:
    Dog() {
        animalType = "dog";
    }
    virtual void voice(Animal* a) {
        std::cout << (this->getType() == a->getType() ? "Woof " : "Bark ");
    }
};

class Cat: public Animal {
public:
    Cat() {
        animalType = "cat";
    }
    virtual void voice(Animal* a) {
        std::cout << (this->getType() == a->getType() ? "Purr " : "Meow ");
    }
};

void meeting(Animal* a, Animal* b);

int main() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    meeting(dog, dog);
    meeting(dog, cat);
    meeting(cat, dog);
    meeting(cat, cat);
    return 0;
}

void meeting(Animal* a, Animal* b) {
    a->voice(b);
    b->voice(a);
    std::cout << std::endl;
}
