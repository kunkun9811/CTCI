#include "line_intersection.hpp"

vector<double> Solution::computeIntersectionPoint(
        double x1_1,
        double y1_1,
        double x2_1,
        double y2_1,

        double x1_2,
        double y1_2,
        double x2_2,
        double y2_2){

                // slope and y-intercept for line 1
                double slope_1 = getSlope(x1_1, y1_1, x2_1, y2_1);
                double yIntercept_1 = getYIntercept(x1_1, y1_1, slope_1);

                // slope and y-intercept for line 2
                double slope_2 = getSlope(x1_2, y1_2, x2_2, y2_2);
                double yIntercept_2 = getYIntercept(x1_2, y1_2, slope_2);

                // if lines are parallel, no intersection point
                if(slope_1 == slope_2){
                        cout << "NO INTERSECTION POINT, LINE SEGMENTS ARE PARALLEL" << endl;
                        double neg_inf = -1 * numeric_limits<double>::infinity();
                        return vector<double>{neg_inf, neg_inf};
                }

                // else it exists, computer the intersection point
                double intersection_x = (yIntercept_1-yIntercept_2)/(slope_1-slope_2);
                double intersection_y = slope_1*intersection_x + yIntercept_1;

                printf("slope_1 = %e\n", slope_1);
                printf("yIntercept_1 = %e\n", yIntercept_1);
                printf("slope_2 = %e\n", slope_2);
                printf("yIntercept_2 = %e\n", yIntercept_2);
                printf("Intersection x = %e\n", intersection_x);
                printf("Intersection y = %e\n", intersection_y);

                printf("x1_1 = %e\n", x1_1);
                printf("x2_1 = %e\n", x2_1);
                printf("x1_2 = %e\n", x1_2);
                printf("x2_2 = %e\n", x2_2);

                printf("x1_1 <= intersection_x = %i\n", x1_1 <= intersection_x);
                printf("intersection_x <= x2_1 = %i\n", intersection_x <= x2_1);
                printf("x1_2 <= intersection_x = %i\n", x1_2 <= intersection_x);
                printf("intersection_x <= x2_2 = %i\n", intersection_x <= x2_2);

                // check if intersection point is within bounds of both line segments
                if(checkWithinBound(x1_1, x2_1, x1_2, x2_2, intersection_x)){
                        return vector<double>{
                                intersection_x,
                                intersection_y
                        };
                }

                // if is not within one of the line segments, return neg_inf
                cout << "INTERSECTION POINT NOT WITHIN BOUND OF ONE OF THE LINE SEGMENTS" << endl;
                double neg_inf = -1 * numeric_limits<double>::infinity();
                return vector<double>{neg_inf, neg_inf};
}

double Solution::getSlope(double x1, double y1, double x2, double y2){
        return (y2-y1)/(x2-x1);
}

double Solution::getYIntercept(double x, double y, double slope){
        // y - y1 = m(x - x1)
        // y = mx - (m*x1 + y1) --> paranthsis part is the y intercept
        double y1 = -1 * y;
        double mx1 = slope * -1 * x;
        return mx1 + y1;
}

double Solution::checkWithinBound(double x1_1, double x2_1, double x1_2, double x2_2, double intersection_x){
        bool isWithinLine1 = x1_1 <= x2_1 ? x1_1 <= intersection_x && intersection_x <= x2_1 : x2_1 <= intersection_x && intersection_x <= x1_1;
        bool isWithinLine2 = x1_2 <= x2_2 ? x1_2 <= intersection_x && intersection_x <= x2_2 : x2_2 <= intersection_x && intersection_x <= x1_2;

        return isWithinLine1 && isWithinLine2;
}