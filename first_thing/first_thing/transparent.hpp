#pragma once
#include "stdafx.h"
#include <map>
#include <cmath>

struct rgbaColor {
	float r;
	float g;
	float b;
	float a;
};

struct position {
	double x;
	double y;
	double z;
};

struct triangle {
	position vex1, vex2, vex3;
	rgbaColor color;
	char name;
};

struct trabject {
	position pos;
	rgbaColor color;
};

class transparentOwner {
public:
	void drawTraTris();
	void qFlower(struct position playerPos, position pos, struct rgbaColor color, double lodsDist);
private:
	void addTriangle(struct position playerPos, position vex1, position vex2, position vex3, struct rgbaColor color, char name);
	double getDistance(struct position pos1, position pos2);
	void drawOneTri(struct triangle tri);
	std::map<double, triangle> triangles;
};



