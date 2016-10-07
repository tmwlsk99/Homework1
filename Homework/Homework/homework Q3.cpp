#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"

const int width = 800;
const int height = 800;
double xpos, ypos;
float* pixels = new float[width*height * 3];



void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
void drawBox(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue);
void drawCircle(const int& i0, const int& j0, const float& red, const float& green, const float& blue);
void drawIcon1(const int& i0, const int& j0, const float& red, const float& green, const float& blue);
void drawIcon2(const int& i0, const int& j0, const float& red, const float& green, const float& blue);
void drawIcon3(const int& i0, const int& j0, const float& red, const float& green, const float& blue);
void drawIcon4(const int& i0, const int& j0, const float& red, const float& green, const float& blue);
void drawX(const int& i0, const int& j0, const float& red, const float& green, const float& blue);
void drawRhombus(const int& i0, const int& j0, const float& red, const float& green, const float& blue);
void drawHalfcircle(const int& i0, const int& j0, const float& red, const float& green, const float& blue);
void drawCirclenew(const int& i0, const int& j0, const float& red, const float& green, const float& blue);

class GeometricObject
{
public:
	int start_x;
	int end_x;
	virtual void draw()
	{
	
			drawCirclenew(start_x, end_x, 1.0f, 0.0f, 0.0f);
	
	}
};


class Line : public GeometricObject
{
public:
	int start_x, start_y;
	int end_x, end_y;
	void draw()
	{
		drawLine(start_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
	}
};

class Box : public GeometricObject
{
public:
	int start_x, start_y;
	int end_x, end_y;
	Box() {}
	Box(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y)
	{
		initialize(_start_x, _start_y, _end_x, _end_y);
	}

	void initialize(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y)
	{
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
	}
	void draw()
	{
		drawBox(start_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
	}
};

class Circle :public GeometricObject
{
public:
	int start_x;
	int end_x;
	void draw()
	{
		drawCircle(start_x, end_x, 1.0f, 0.0f, 0.0f);
	}
};

class Icon1 : public GeometricObject
{
public:
	int start_x;
	int end_x;
	void draw()
	{
		drawIcon1(start_x, end_x, 1.0f, 0.0f, 0.0f);
	}
};
class Icon2 : public GeometricObject
{
public:
	int start_x;
	int end_x;
	void draw()
	{
		drawIcon2(start_x, end_x, 1.0f, 0.0f, 0.0f);
	}
};

class Icon3 : public GeometricObject
{
public:
	int start_x;
	int end_x;
	void draw()
	{
		drawIcon3(start_x, end_x, 1.0f, 0.0f, 0.0f);
	}
};

class Icon4 : public GeometricObject
{
public:
	int start_x;
	int end_x;
	void draw()
	{
		drawIcon4(start_x, end_x, 1.0f, 0.0f, 0.0f);
	}
};

class X : public GeometricObject
{
public:
	int start_x, start_y;
	int end_x, end_y;
	void draw()
	{
		drawX(start_x, end_x, 1.0f, 0.0f, 0.0f);
	}
};

class Rhombus : public GeometricObject
{
public:
	int start_x, start_y;
	int end_x, end_y;
	void draw()
	{
		drawRhombus(start_x, end_x, 1.0f, 0.0f, 0.0f);
	}
};

class Halfcircle :public GeometricObject
{
public:
	int start_x;
	int end_x;
	void draw()
	{
		drawHalfcircle(start_x, end_x, 1.0f, 0.0f, 0.0f);
	}
};


//Line **my_lines = new Line*[5];
//Box **my_boxese = new Box*[5];

GeometricObject** my_objects = new GeometricObject*[40];


void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}




void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{

	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}


}

void drawBox(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j0 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}

	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j1)*(i - i0) / (i1 - i0) + j1;

		drawPixel(i, j, red, green, blue);
	}

	for (int j = j0; j <= j1; j++)
	{
		const int i = (i0 - i0)*(j - j0) / (j1 - j0) + i0;

		drawPixel(i, j, red, green, blue);
	}

	for (int j = j0; j <= j1; j++)
	{
		const int i = (i1 - i1)*(j - j0) / (j1 - j0) + i1;

		drawPixel(i, j, red, green, blue);
	}

}

void drawCircle(const int& i0, const int& j0, const float& red, const float& green, const float& blue)
{
	int r = 50; //원의 반지름 
	for (int i = i0 - r; i < i0 + r; i++) {
		for (int j = j0 - r; j < j0 + r; j++) {
			int n = ((i - i0)*(i - i0) + (j - j0)*(j - j0) - r*r);
			int m = ((i - i0)*(i - i0) + (j - j0)*(j - j0) - (r - 1)*(r - 1));
			if (n < 0 && m>0) //두 원의 사이 
				drawPixel(i, j, red, green, blue);
		}
	}
}
void drawCirclenew(const int& i0, const int& j0, const float& red, const float& green, const float& blue)
{
	int r = 65;
	if ((xpos - i0)*(xpos - i0) + (ypos - j0)*(ypos - j0) - (r*r)<0)
	{
		for (int i = i0 - r; i < i0 + r; i++)
		{
			for (int j = j0 - r; j < j0 + r; j++)
			{
				int n = ((i - i0)*(i - i0) + (j - j0)*(j - j0) - r*r);
				int m = ((i - i0)*(i - i0) + (j - j0)*(j - j0) - (r - 1)*(r - 1));
				if (n < 0 && m>0)
					drawPixel(i, j, 0.0f, 0.0f, 0.0f);
			}
		}
	}
	else 
		for (int i = i0 - r; i < i0 + r; i++)
		{
			for (int j = j0 - r; j < j0 + r; j++)
			{
				int n = ((i - i0)*(i - i0) + (j - j0)*(j - j0) - r*r);
				int m = ((i - i0)*(i - i0) + (j - j0)*(j - j0) - (r - 1)*(r - 1));
				if (n < 0 && m>0)
					drawPixel(i, j, 1.0f, 0.0f, 0.0f);
			}
		}
}

void drawIcon1(const int& i0, const int& j0, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i0 + 50; i++)
	{
		const int j = (j0 + 50 - j0)*(i - i0) / (i0 + 50 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
	for (int i = i0; i <= i0 + 50; i++)
	{
		const int j = (j0 - (j0 - 50))*(i - i0) / (i0 - (i0 + 50)) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawIcon2(const int& i0, const int& j0, const float& red, const float& green, const float& blue)
{
	for (int i = i0 - 50; i <= i0; i++)
	{
		const int j = (j0 + 50 - j0)*(i - i0) / (i0 - 50 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
	for (int i = i0 - 50; i <= i0; i++)
	{
		const int j = (j0 - (j0 - 50))*(i - i0) / (i0 - (i0 - 50)) + j0;

		drawPixel(i, j, red, green, blue);
	}
}
void drawIcon3(const int& i0, const int& j0, const float& red, const float& green, const float& blue)
{
	for (int i = i0 - 50; i <= i0; i++)
	{
		const int j = (j0 + 50 - j0)*(i - i0) / (i0 - 50 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
	for (int i = i0; i <= i0 + 50; i++)
	{
		const int j = (j0 + 50 - (j0))*(i - i0) / (i0 + 50 - (i0)) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawIcon4(const int& i0, const int& j0, const float& red, const float& green, const float& blue)
{
	for (int i = i0 - 50; i <= i0; i++)
	{
		const int j = (j0 - (j0 - 50))*(i - i0) / (i0 - (i0 - 50)) + j0;

		drawPixel(i, j, red, green, blue);
	}
	for (int i = i0; i <= i0 + 50; i++)
	{
		const int j = (j0 - (j0 - 50))*(i - i0) / (i0 - (i0 + 50)) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawX(const int& i0, const int& j0, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i0 + 50; i++)
	{
		const int j = (j0 + 50 - j0)*(i - i0) / (i0 + 50 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
	for (int i = i0; i <= i0 + 50; i++)
	{
		const int j = (j0 - (j0 - 50))*(i - i0) / (i0 - (i0 + 50)) + j0;

		drawPixel(i, j, red, green, blue);
	}
	for (int i = i0 - 50; i <= i0; i++)
	{
		const int j = (j0 + 50 - j0)*(i - i0) / (i0 - 50 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
	for (int i = i0 - 50; i <= i0; i++)
	{
		const int j = (j0 - (j0 - 50))*(i - i0) / (i0 - (i0 - 50)) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawRhombus(const int& i0, const int& j0, const float& red, const float& green, const float& blue)
{
	for (int i = i0 - 100; i <= i0 - 100 + 50; i++)
	{
		const int j = (j0 + 50 - j0)*(i - (i0 - 100)) / (i0 - 100 + 50 - (i0 - 100)) + j0;

		drawPixel(i, j, red, green, blue);
	}
	for (int i = i0 - 100; i <= i0 - 100 + 50; i++)
	{
		const int j = (j0 - (j0 - 50))*(i - (i0 - 100)) / (i0 - 100 - (i0 - 100 + 50)) + j0;

		drawPixel(i, j, red, green, blue);
	}
	for (int i = i0 - 50; i <= i0; i++)
	{
		const int j = (j0 + 50 - j0)*(i - i0) / (i0 - 50 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
	for (int i = i0 - 50; i <= i0; i++)
	{
		const int j = (j0 - (j0 - 50))*(i - i0) / (i0 - (i0 - 50)) + j0;

		drawPixel(i, j, red, green, blue);
	}
}
void drawHalfcircle(const int& i0, const int& j0, const float& red, const float& green, const float& blue)
{
	for (int i = i0 - 50; i <= i0 + 50; i++)
	{
		int j;

		j = sqrt(2500 - (i - (i0))*(i - (i0))) + (j0);

		drawPixel(i, j, red, green, blue);
	}
}
void drawOnPixelBuffer()
{
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background

													//for (int i = 0; i<width*height; i++) {
													//	pixels[i * 3 + 0] = 1.0f; // red 
													//	pixels[i * 3 + 1] = 1.0f; // green
													//	pixels[i * 3 + 2] = 1.0f; // blue
													//}

	const int i = rand() % width, j = rand() % height;
	drawPixel(i, j, 0.0f, 0.0f, 0.0f);

	// drawing a line
	//TODO: anti-aliasing


	for (int i = 0; i < 40; i++)

		my_objects[i]->draw();


	//TODO: try moving object
}

int main(void)
{


	for (int i = 0; i < 2; i++)
	{
		my_objects[i] = new Box(50 + 100 * i*i, 150, 100 + 100 * i* i, 200);


		GeometricObject *geo = new GeometricObject;
		geo->start_x = 75 + 100 * i*i;
		geo->end_x = 175;
		my_objects[i + 20] = geo;

		//my_boxese[i]->initialize(i*20, 50, 50+50*i, 100);
	}

	for (int i = 2; i < 4; i++)
	{
		Line *temp = new Line;

		temp->start_x = 50 + 50 * (i*i - 1);
		temp->start_y = 50;
		temp->end_x = 80 + 50 * (i*i - 1);
		temp->end_y = 100;
		my_objects[i] = temp;

		GeometricObject *geo = new GeometricObject;
		geo->start_x = 65 + 50 * (i*i - 1);
		geo->end_x = 75;
		my_objects[i + 20] = geo;
	}


	for (int i = 4; i < 6; i++)
	{
		Circle *temp = new Circle;

		temp->start_x = 150 * (i - 3);

		temp->end_x = 300;

		my_objects[i] = temp;

		GeometricObject *geo = new GeometricObject;
		geo->start_x = 150 * (i - 3);
		geo->end_x = 300;
		my_objects[i + 20] = geo;
	}

	for (int i = 6; i < 8; i++)
	{
		Icon1 *temp = new Icon1;

		temp->start_x = 450 + 400 * (i - 6) / 2;

		temp->end_x = 300;

		my_objects[i] = temp;


		GeometricObject *geo = new GeometricObject;
		geo->start_x = 450 + 400 * (i - 6) / 2;
		geo->end_x = 300;
		my_objects[i + 20] = geo;
	}

	for (int i = 8; i < 10; i++)
	{
		Icon2 *temp = new Icon2;

		temp->start_x = 150 * (i - 7);

		temp->end_x = 420;

		my_objects[i] = temp;

		GeometricObject *geo = new GeometricObject;
		geo->start_x = 150 * (i - 7);
		geo->end_x = 420;
		my_objects[i + 20] = geo;
	}

	for (int i = 10; i < 12; i++)
	{
		Icon3 *temp = new Icon3;

		temp->start_x = 450 + 400 * (i - 10) / 2;

		temp->end_x = 420;

		my_objects[i] = temp;

		GeometricObject *geo = new GeometricObject;
		geo->start_x = 450 + 400 * (i - 10) / 2;
		geo->end_x = 420;
		my_objects[i + 20] = geo;
	}

	for (int i = 12; i < 14; i++)
	{
		Icon4 *temp = new Icon4;

		temp->start_x = 150 * (i - 11);

		temp->end_x = 540;

		my_objects[i] = temp;

		GeometricObject *geo = new GeometricObject;
		geo->start_x = 150 * (i - 11);
		geo->end_x = 540;
		my_objects[i + 20] = geo;
	}

	for (int i = 14; i < 16; i++)
	{
		X *temp = new X;

		temp->start_x = 450 + 400 * (i - 14) / 2;
		temp->end_x = 540;
		my_objects[i] = temp;

		GeometricObject *geo = new GeometricObject;
		geo->start_x = 450 + 400 * (i - 14) / 2;
		geo->end_x = 540;
		my_objects[i + 20] = geo;
	}

	for (int i = 16; i < 18; i++)
	{
		Rhombus *temp = new Rhombus;

		temp->start_x = 150 * (i - 15);
		temp->end_x = 660;
		my_objects[i] = temp;

		GeometricObject *geo = new GeometricObject;
		geo->start_x = 150 * (i - 15) - 50;
		geo->end_x = 660;
		my_objects[i + 20] = geo;
	}
	for (int i = 18; i < 20; i++)
	{
		Halfcircle *temp = new Halfcircle;

		temp->start_x = 450 + 400 * (i - 18) / 2;
		temp->end_x = 660;
		my_objects[i] = temp;


		GeometricObject *geo = new GeometricObject;
		geo->start_x = 450 + 400 * (i - 18) / 2;
		geo->end_x = 660;
		my_objects[i + 20] = geo;
	}


	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

							  /* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glfwGetCursorPos(window, &xpos, &ypos);
		/* Render here */
		//glClear(GL_COLOR_BUFFER_BIT);

		drawOnPixelBuffer();

		//TODO: RGB struct
		//Make a pixel drawing function
		//Make a line drawing function

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}
