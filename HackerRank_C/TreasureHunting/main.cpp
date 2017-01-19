#include <cstdio>
#include <cmath>

using namespace std;

struct Point {
    double x = 0;
    double y = 0;

    Point() {
    }
    Point(double x, double y) :
            x(x), y(y) {
    }

    bool operator==(const Point& point);
};

struct Line {
    double k = 0;
    double c = 0;

    Line() {
    }

    double f(double x);
};

Line* lineFrom2Points(Point* point1, Point* point2);

Point* intersectionOf2Lines(Line* line1, Line* line2);

Point* pointFrom2Points_90(Point* a, Point* o);

void computeLineCFromPoint(Line* line, Point* point);

double distanceBetweenTwoPoints(Point* point1, Point* point2);

bool compareVectors(Point* v1, Point* v2);

int main() {
    Point start;
    Point destination;
    Point v;
    scanf("%lf %lf\n%lf %lf", &destination.x, &destination.y, &v.x, &v.y);

    Point* v1 = pointFrom2Points_90(&v, &start);
    Line* l1 = lineFrom2Points(&start, &v);
    Line* l2 = lineFrom2Points(&start, v1);
    computeLineCFromPoint(l2, &destination);
    Point* i = intersectionOf2Lines(l1, l2);
    double vL = distanceBetweenTwoPoints(&start, &v);

    double k = distanceBetweenTwoPoints(&start, i) / vL;
    if (compareVectors(&v, i))
        k = -k;

    destination.x -= i->x;
    destination.y -= i->y;
    double n = distanceBetweenTwoPoints(&start, &destination) / vL;
    if (compareVectors(&destination, v1))
        n = -n;
    printf("%lf\n%lf", k, n);
}

bool compareVectors(Point* v1, Point* v2) {
    double xP = v1->x * v2->x;
    double yP = v1->y * v2->y;
    return (xP < 0 || yP < 0);
}

double distanceBetweenTwoPoints(Point* point1, Point* point2) {
    return sqrt(
            pow((point1->x - point2->x), 2) + pow((point1->y - point2->y), 2));
}

Line* lineFrom2Points(Point* point1, Point* point2) {
    Line* line = new Line();
    line->k = (point2->y - point1->y) / (point2->x - point1->x);
    computeLineCFromPoint(line, point1);
    return line;
}

Point* intersectionOf2Lines(Line* line1, Line* line2) {
    if (line1->k == line2->k)
        return 0;

    Point* point = new Point();
//    if (isinf(line1->k)) {
//        point->x = line1->c;
//        point->y = line2->f(point->x);
//    } else if (isinf(line2->k)) {
//        point->x = line2->c;
//        point->y = line1->f(point->x);
//    } else {
    point->x = (line2->c - line1->c) / (line1->k - line2->k);
    point->y = point->x * line1->k + line1->c;
//    }
    return point;
}

Point* pointFrom2Points_90(Point* a, Point* o) {
    Point* point = new Point();
    point->x = o->x - a->y + o->y;
    point->y = a->x - o->x + o->y;
    return point;
}

void computeLineCFromPoint(Line* line, Point* point) {
//    if (isinf(line->k)) {
//        line->c = point->x;
//    } else {
    line->c = point->y - point->x * line->k;
//    }
}

double Line::f(double x) {
//    return (isinf(k)) ? 0 : (x * k + c);
    return (x * k + c);
}
