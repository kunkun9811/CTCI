#pragma once

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
        vector<double> computeIntersectionPoint(double x1_1, double y1_1, double x2_1, double y2_1, double x1_2, double y1_2, double x2_2, double y2_2);
        double getSlope(double x1, double y1, double x2, double y2);
        double getYIntercept(double x, double y, double slope);
        double checkWithinBound(double x1_1, double x2_1, double x1_2, double x2_2, double intersection_x);
};