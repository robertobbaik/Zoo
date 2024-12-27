#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

class Animal
{
public:
    virtual void makeSound() = 0;
    ~Animal() 
    {
        cout << "Destructor Animal" << endl;
    };
};

class Dog : public Animal
{
public:
    Dog(string m_word) : m_word(m_word) {};
    void makeSound()
    {
        cout << m_word << endl;
    }

private:
    string m_word;
};

class Cat : public Animal
{
public:
    Cat(string m_word) : m_word(m_word) {};
    void makeSound()
    {
        cout << m_word << endl;
    }

private:
    string m_word;
};

class Cow : public Animal
{
public:
    Cow(string m_word) : m_word(m_word) {};
    void makeSound()
    {
        cout << m_word << endl;
    }

private:
    string m_word;
};

class Zoo
{
private:
    vector<Animal*> v;

public:
    void addAnimal(Animal *animal)
    {
        v.push_back(animal);
    }

    void performActions()
    {
        for (int i = 0; i < v.size(); i++)
        {
            v[i]->makeSound();
        }
    }

    ~Zoo()
    {
        for (int i = 0; i < v.size(); i++)
        {
           delete v[i];
        }
        cout << "Destructor Zoo" << endl;
    }
};

Animal *createRandomAnimal()
{
    int randomIdx = rand() % 3;

    Animal *animal;

    switch (randomIdx)
    {
    case 0:
        animal = new Dog("Woof");
        break;
    case 1:
        animal = new Cat("Meow");
        break;
    case 2:
        animal = new Cow("Mmmmmm");
        break;
    }

    return animal;
}

int main()
{
    Zoo *zoo = new Zoo();

    for (int i = 0; i < 10; i++)
    {
        zoo->addAnimal(createRandomAnimal());
    }

    zoo->performActions();
    
    delete zoo;

    return 0;
}