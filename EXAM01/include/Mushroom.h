#ifndef MUSHROOM_H
#define MUSHROOM_H
#include <string>
#include <vector>

class Mushroom
{
    public:
        Mushroom();
        int total_oz_;
        double per_oz_value_;
        std::string common_name_;
        std::string scientific_name_;

};

#endif // MUSHROOM_H
