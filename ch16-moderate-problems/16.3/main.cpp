#include <iostream>
#include "line_intersection.hpp"

using namespace std;

int main() {

        double x1_1 = 2;
        double y1_1 = 0;
        double x2_1 = 2;
        double y2_1 = 3;

        double x1_2 = 0;
        double y1_2 = 1;
        double x2_2 = 3;
        double y2_2 = 4;

        Solution solution = Solution();

        vector<double> result = solution.computeIntersectionPoint(x1_1, y1_1, x2_1, y2_1, x1_2, y1_2, x2_2, y2_2);

        printf("Intersection Point = (%e, %e)\n", result[0], result[1]);

        return 0;
}