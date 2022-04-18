#include <string>
#include <iostream>
#include <fstream>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Character {
public:
    Character(std::string_view _name, int _age) : name(_name), age(_age) {}

private:
    std::string name;
    int age;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive& ar, [[maybe_unused]] const unsigned int version)
    {
        ar << name;
        ar << age;
    }
};

int main()
{
    std::ofstream ofs("character.txt");

    const Character helgret{ "Helgret", 40 };
    {
        boost::archive::text_oarchive oa(ofs);
        oa << helgret;
    }
}