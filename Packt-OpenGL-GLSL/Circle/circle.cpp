// Packt-OpenGL-GLSL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <GLFW/glfw3.h>

const int steps = 100; // Number of triangles to draw the circle
const float angle = 3.1415926f * 2.f / steps; // Angle between each triangle in the circle 


int main()
{
    GLFWwindow * window; // Create a windowed mode window and its OpenGL context

    if (!glfwInit())
	{
        std::cerr << "Failed to initialize GLFW\n";
		return -1;
	}

    window = glfwCreateWindow(800, 600, "Hello World", 0, 0); // Create a windowed mode window and its OpenGL context

    if (!window) 
    {
		std::cerr << "Failed to create window\n";
		glfwTerminate();
		return -1;
	
    }

	glfwMakeContextCurrent(window); // Make the window's context current

	float xPos = 0; float yPos = 0; float radius = 1.0f;

	


	// Rendering loop
	while (!glfwWindowShouldClose(window))
	{

		glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set the clear color
		glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

		float prevX = xPos;
		float prevY = yPos - radius;

		for (int i=0; i <=steps;i++)
		{
			float newX = radius * sin(angle * i);
			float newY = -radius * cos(angle * i);

			glBegin(GL_TRIANGLES); // Begin drawing a triangle
			glColor3f(0,0.5f,0); // Set the color of the triangle
			glVertex3f(0.0f, 0.0f, 0.0f); // Center of circle
			glVertex3f(prevX, prevY, 0.0f); // Previous point
			glVertex3f(newX, newY, 0.0f); // New point
			glEnd(); // End drawing the triangle

			prevX = newX;
			prevY = newY;
		}


		
		glfwSwapBuffers(window); // Swap the front and back buffers
		glfwPollEvents(); // Poll for events
	}

	glfwTerminate();
	return 0;

}

