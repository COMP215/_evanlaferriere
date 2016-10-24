#include <iostream>
#include "Mushroom.h"
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
std::vector<Mushroom> read_csv()
{
    std::cout << "What's the name of the input file? Do not include .csv. ";
    std::string in_file;
    std::cin >> in_file;
    in_file += ".csv";
    std::ifstream input;
    input.open(in_file);
    std::string to_mushroom;
    std::getline(input, to_mushroom);
    int com_num, sci_num, oz_num, price;
    std::vector<Mushroom> shrooms;
    while ( std::getline(input, to_mushroom) )
    {
        std::cout << to_mushroom << endl;
        shrooms.push_back(Mushroom());
        com_num = to_mushroom.find(',');
        shrooms.back().common_name_ = to_mushroom.substr(0,com_num);
        sci_num = to_mushroom.find(',', com_num);
        shrooms.back().scientific_name_ = to_mushroom.substr(com_num+1,sci_num);
        oz_num = to_mushroom.find(',', sci_num);
        shrooms.back().total_oz_ = std::atoi(to_mushroom.substr(sci_num+1, oz_num).c_str());
        price = to_mushroom.find_last_of(',');
        std::cout << "price pos: " << price << endl;
        //shrooms.back().per_oz_value_ = std::atoi(to_mushroom.substr(price).c_str())/shrooms.back().total_oz_;
    }
}
void Go_Mushrooming()
{
    std::vector<Mushroom> Trip = read_csv();
    std::vector<Mushroom> Satchel;
    int satchel_weight_limit, oz_carried, sentinel_shroom_weight;
    oz_carried = 0;
    std::cout << "How many ounces of mushrooms can your satchel carry? ";
    std::cin >> satchel_weight_limit;
    for(int i = 0; i < Trip.size(); i++)
    {
        sentinel_shroom_weight += Trip[i].total_oz_;
    }
    while(oz_carried < satchel_weight_limit && oz_carried < sentinel_shroom_weight)
    {
        int best_shroom = 0;
        for(int i = 0; i < Trip.size(); i++)
        {
            if(Trip[i].per_oz_value_ > Trip[best_shroom].per_oz_value_)
                best_shroom = i;
        }
        if(Trip[best_shroom].total_oz_+oz_carried < satchel_weight_limit)
        {
            Satchel.push_back(Trip[best_shroom]);
            oz_carried += Trip[best_shroom].total_oz_;
            Trip.erase(Trip.begin()+best_shroom);
        }
        else
        {
            Satchel.push_back(Mushroom());
            Satchel.back().common_name_ = Trip[best_shroom].common_name_;
            Satchel.back().scientific_name_ = Trip[best_shroom].scientific_name_;
            Satchel.back().per_oz_value_ = Trip[best_shroom].per_oz_value_;
            Satchel.back().total_oz_ = 0;
            while(oz_carried < satchel_weight_limit)
            {
                oz_carried++;
                Satchel.back().total_oz_++;
            }
            break;
        }
    }
    int total_value;
    for(int i = 0; i < Satchel.size(); i++)
    {
        std::cout << Satchel[i].total_oz_ << " oz of " << Satchel[i].common_name_ << " (" << Satchel[i].scientific_name_ << ") mushrooms." << std::endl;
        total_value += Satchel[i].total_oz_ * Satchel[i].per_oz_value_;
    }
    std::cout << "---------------------------" << std::endl;
    std::cout << "Total value $" << total_value;
}

int main()
{
    Go_Mushrooming();
}
