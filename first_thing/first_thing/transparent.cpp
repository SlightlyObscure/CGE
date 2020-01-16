#include "transparent.hpp"



void transparentOwner::drawTraTris() {
	glPushMatrix();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	int testC = 0;
	for (std::map<double, triangle>::reverse_iterator it = triangles.rbegin(); it != triangles.rend(); it++) {
		triangle tri = it->second;

		glColor4f(tri.color.r, tri.color.g, tri.color.b, tri.color.a);

		glBegin(GL_TRIANGLES);
		glVertex3f(tri.vex1.x, tri.vex1.y, tri.vex1.z);
		glVertex3f(tri.vex2.x, tri.vex2.y, tri.vex2.z);
		glVertex3f(tri.vex3.x, tri.vex3.y, tri.vex3.z);
		glEnd();
	}
	//printf("\n");

	glDisable(GL_BLEND);

	glPopMatrix();
}

void transparentOwner::qFlower(struct position playerPos, position pos, struct rgbaColor color, double lodsDist) {
	double distance = getDistance(playerPos, pos);
	
	if (distance > lodsDist * 20) {
		
	}
	else if (distance > lodsDist * 2) {												//LEVEL 2
		//x-negative face
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ -0.5 + pos.x, 0.8 + pos.y, -0.5 + pos.z }, color, 'a');
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ -0.5 + pos.x, 0.8 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 0.8 + pos.y, 0.5 + pos.z }, color, 'b');

		//x-positive face
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.8 + pos.y, -0.5 + pos.z }, color, 'c');
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.8 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.8 + pos.y, 0.5 + pos.z }, color, 'd');

		//y-negative face
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, color, 'e');
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, color, 'f');

		//y-positive face
		//addTriangle(playerPos, position{ -0.5 + pos.x, 1.0 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 1.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 1.0 + pos.y, -0.5 + pos.z }, color, 'g');
		//addTriangle(playerPos, position{ -0.5 + pos.x, 1.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 1.0 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 1.0 + pos.y, 0.5 + pos.z }, color, 'h');


		// z-negative face
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 0.8 + pos.y, -0.5 + pos.z }, color, 'i');
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 0.8 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.8 + pos.y, -0.5 + pos.z }, color, 'j');

		// z-positive face
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ -0.5 + pos.x, 0.8 + pos.y, 0.5 + pos.z }, color, 'k');
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ -0.5 + pos.x, 0.8 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.8 + pos.y, 0.5 + pos.z }, color, 'l');
	}
	else if (getDistance(playerPos, pos) > lodsDist) {																//LEVEL 1
		//x-negative face
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, color, 'a');
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, color, 'b');

		//x-positive face
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, color, 'c');
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, color, 'd');

		//y-negative face
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, color, 'e');
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, color, 'f');

		// z-negative face
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, color, 'i');
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, color, 'j');

		// z-positive face
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, color, 'k');
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, color, 'l');

		//petals
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, position{ 0.0 + pos.x, 1.0 + pos.y, -0.5 + pos.z }, color, 'z');
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, position{ -0.5 + pos.x, 1.0 + pos.y, 0.0 + pos.z }, color, 'z');
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 1.0 + pos.y, 0.0 + pos.z }, color, 'z');
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, position{ 0.0 + pos.x, 1.0 + pos.y, 0.5 + pos.z }, color, 'z');
	}
	else {																												//LEVEL 0
		//x-negative face
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, -0.3 + pos.z }, position{ -0.5 + pos.x, 0.0 + pos.y, 0.3 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, -0.3 + pos.z }, color, 'a');
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, 0.3 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, -0.3 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, 0.3 + pos.z }, color, 'b');

		//x-positive face
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, -0.3 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, 0.3 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, -0.3 + pos.z }, color, 'c');
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, 0.3 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, -0.3 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, 0.3 + pos.z }, color, 'd');

		//y-negative face
		//addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, color, 'e');
		//addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, color, 'f');

		// z-negative face
		addTriangle(playerPos, position{ -0.3 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ 0.3 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ -0.3 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, color, 'i');
		addTriangle(playerPos, position{ 0.3 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ -0.3 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, position{ 0.3 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, color, 'j');

		// z-positive face
		addTriangle(playerPos, position{ -0.3 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.3 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ -0.3 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, color, 'k');
		addTriangle(playerPos, position{ 0.3 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ -0.3 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, position{ 0.3 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, color, 'l');

		// -x/-z face
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, -0.3 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, -0.3 + pos.z }, position{ -0.3 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, color, 'z');
		addTriangle(playerPos, position{ -0.3 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, position{ -0.3 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, -0.3 + pos.z }, color, 'z');
		//petal
		addTriangle(playerPos, position{ -0.3 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, -0.3 + pos.z }, position{ -0.4 + pos.x, 0.8 + pos.y, -0.4 + pos.z }, color, 'z');

		// +x/-z face
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, -0.3 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, -0.3 + pos.z }, position{ 0.3 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, color, 'z');
		addTriangle(playerPos, position{ 0.3 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, position{ 0.3 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, -0.3 + pos.z }, color, 'z');
		//petal
		addTriangle(playerPos, position{ 0.3 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, -0.3 + pos.z }, position{ 0.4 + pos.x, 0.8 + pos.y, -0.4 + pos.z }, color, 'z');

		// -x/+z face
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, 0.3 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, 0.3 + pos.z }, position{ -0.3 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, color, 'z');
		addTriangle(playerPos, position{ -0.3 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, position{ -0.3 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, 0.3 + pos.z }, color, 'z');
		//petal
		addTriangle(playerPos, position{ -0.3 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, 0.3 + pos.z }, position{ -0.4 + pos.x, 0.8 + pos.y, 0.4 + pos.z }, color, 'z');

		// +x/+z face
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, 0.3 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, 0.3 + pos.z }, position{ 0.3 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, color, 'z');
		addTriangle(playerPos, position{ 0.3 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, position{ 0.3 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, 0.3 + pos.z }, color, 'z');
		//petal
		addTriangle(playerPos, position{ 0.3 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, 0.3 + pos.z }, position{ 0.4 + pos.x, 0.8 + pos.y, 0.4 + pos.z }, color, 'z');

		//bottom
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, -0.3 + pos.z }, position{ -0.5 + pos.x, 0.0 + pos.y, 0.3 + pos.z }, position{ 0.0 + pos.x, 0.0 + pos.y, 0.0 + pos.z }, color, 'a');
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, -0.3 + pos.z }, position{ 0.5 + pos.x, 0.0 + pos.y, 0.3 + pos.z }, position{ 0.0 + pos.x, 0.0 + pos.y, 0.0 + pos.z }, color, 'a');
		addTriangle(playerPos, position{ -0.3 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ 0.3 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ 0.0 + pos.x, 0.0 + pos.y, 0.0 + pos.z }, color, 'i');
		addTriangle(playerPos, position{ -0.3 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.3 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.0 + pos.x, 0.0 + pos.y, 0.0 + pos.z }, color, 'i');
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, -0.3 + pos.z }, position{ -0.3 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ 0.0 + pos.x, 0.0 + pos.y, 0.0 + pos.z }, color, 'z');
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, -0.3 + pos.z }, position{ 0.3 + pos.x, 0.0 + pos.y, -0.5 + pos.z }, position{ 0.0 + pos.x, 0.0 + pos.y, 0.0 + pos.z }, color, 'z');
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.0 + pos.y, 0.3 + pos.z }, position{ -0.3 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.0 + pos.x, 0.0 + pos.y, 0.0 + pos.z }, color, 'z');
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.0 + pos.y, 0.3 + pos.z }, position{ 0.3 + pos.x, 0.0 + pos.y, 0.5 + pos.z }, position{ 0.0 + pos.x, 0.0 + pos.y, 0.0 + pos.z }, color, 'z');


		//petals
		addTriangle(playerPos, position{ -0.3 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, position{ 0.3 + pos.x, 0.6 + pos.y, -0.5 + pos.z }, position{ 0.0 + pos.x, 1.0 + pos.y, -0.5 + pos.z }, color, 'z');
		addTriangle(playerPos, position{ -0.5 + pos.x, 0.6 + pos.y, -0.3 + pos.z }, position{ -0.5 + pos.x, 0.6 + pos.y, 0.3 + pos.z }, position{ -0.5 + pos.x, 1.0 + pos.y, 0.0 + pos.z }, color, 'z');
		addTriangle(playerPos, position{ 0.5 + pos.x, 0.6 + pos.y, -0.3 + pos.z }, position{ 0.5 + pos.x, 0.6 + pos.y, 0.3 + pos.z }, position{ 0.5 + pos.x, 1.0 + pos.y, 0.0 + pos.z }, color, 'z');
		addTriangle(playerPos, position{ -0.3 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, position{ 0.3 + pos.x, 0.6 + pos.y, 0.5 + pos.z }, position{ 0.0 + pos.x, 1.0 + pos.y, 0.5 + pos.z }, color, 'z');

	}
	
}

void transparentOwner::addTriangle(struct position playerPos, position vex1, position vex2, position vex3, struct rgbaColor color, char name) {
	position triMiddle = { (vex1.x + vex2.x + vex3.x) / 3, (vex1.y + vex2.y + vex3.y) / 3, (vex1.z + vex2.z + vex3.z) / 3 };

	double dist = getDistance(playerPos, triMiddle);

	triangle tri = {vex1, vex2, vex3, color, name};

	bool distIsNew = false;

	while (distIsNew == false) {
		std::pair<std::map<double, triangle>::iterator, bool> result = triangles.insert(std::pair<double, triangle>(dist, tri));
		distIsNew = std::get<1>(result);
		dist += 0.00000001;
	}
	
}

double transparentOwner::getDistance(position pos1, position pos2) {
	return sqrt(pow(pos2.x - pos1.x, 2) + pow(pos2.y - pos1.y, 2) + pow(pos2.z - pos1.z, 2));
}

void transparentOwner::drawOneTri(triangle tri) {
	glColor4f(tri.color.r, tri.color.g, tri.color.b, tri.color.a);

}
