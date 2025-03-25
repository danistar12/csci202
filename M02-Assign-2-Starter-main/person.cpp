#include "Person.h"

Person::Person(const std::string &name, int age) : name(name), age(age) {}

bool Person::operator==(const Person &other) const
{
    return this->age == other.age;
}

bool Person::operator!=(const Person &other) const
{
    return !(*this == other);
}

bool Person::operator<(const Person &other) const
{
    return this->age < other.age;
}

bool Person::operator<=(const Person &other) const
{
    return this->age <= other.age;
}

bool Person::operator>(const Person &other) const
{
    return this->age > other.age;
}

bool Person::operator>=(const Person &other) const
{
    return this->age >= other.age;
}

std::ostream &operator<<(std::ostream &os, const Person &person)
{
    os << "Name: " << person.name << ", Age: " << person.age;
    return os;
}
