/**
 * @file Test.cpp
 * @author Shmuel.Lavian
 * @brief 
 * @version 0.1
 * @date 2021-04-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "doctest.h"
#include "NumberWithUnits.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Input") {
    ifstream units_file{"units.txt"};

}

TEST_CASE("Wrong Input") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits distance(5,"km");
    NumberWithUnits weight(5,"kg");
    CHECK_THROWS(distance+weight);
    CHECK_THROWS(distance-weight);
    CHECK_THROWS(weight+distance);
    CHECK_THROWS(weight-distance);
}

TEST_CASE("Calculation") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits distance(5,"km");
    NumberWithUnits distance2(6,"km");
    NumberWithUnits distance3(4,"km");
    NumberWithUnits negative_distance(-5,"km");
    NumberWithUnits weight(5,"kg");
    NumberWithUnits weight2(5,"kg");
    NumberWithUnits weight3(10,"kg");
    CHECK(distance < distance2);
    CHECK(distance <= distance2);
    CHECK(distance2 > distance);
    CHECK(distance2 >= distance);
    CHECK(distance2 != distance);
    CHECK(distance == distance);
    CHECK(+distance == distance);
    CHECK(-distance == negative_distance);
    CHECK(-distance != distance);
    distance++;
    CHECK(distance != distance);
    CHECK(distance != weight);
    CHECK(distance == distance2);
    distance--;
    distance--;
    CHECK(distance == distance3);
    CHECK(distance != distance2);
    CHECK((weight+weight2) == weight3);
    weight++;
    weight3++;
    CHECK((weight+weight2) == weight3);
    weight2+=weight;
    CHECK(weight2 == weight3);
}

