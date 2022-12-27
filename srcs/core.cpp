//
// Created by Cyril Battistolo on 19/12/2022.
//

#include "core.hpp"

Application::Application(const int width, const int height, const char *title) :
	width(width), height(height),
	window(init_glfw(title)),
	ui(UI(window))
{
	// TODO: init config
	ratio = static_cast<float>(width) / static_cast<float>(height);
	print_info_config(title);
	glfwSetWindowUserPointer(window, (void *)this);
}

GLFWwindow* Application::init_glfw(const char *title) const
{
	GLFWwindow *win;

	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);

	// GL 3.3 + GLSL 330
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac

	win = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (!win) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	std::cout << "Window created" << std::endl;

	// create context
	glfwMakeContextCurrent(win);

	// init callbacks
	glfwSetKeyCallback(win, key_callback);
	glfwSetMouseButtonCallback(win, mouse_button_callback);
	glfwSetCursorPosCallback(win, mouse_position_callback);
	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
	glfwSetWindowRefreshCallback(win, window_refresh_callback);

	// Enable vsync
	glfwSwapInterval(1);
	// Size limits of the window
	glfwSetWindowSizeLimits(win, 1150, 750, GLFW_DONT_CARE, GLFW_DONT_CARE);

	// Load OpenGL functions
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	std::cout << "GLAD initialized" << std::endl;
	glEnable(GL_DEPTH_TEST);
	return win;
}

Application::~Application()
{
	ui.~UI();
	glfwDestroyWindow(window);
	glfwTerminate();
	std::cout << "Application terminated" << std::endl;
	exit(EXIT_SUCCESS);
}

void Application::error_callback(int error, const char *description)
{
	(void) error;
	std::cerr << "Error: " << description << std::endl;
}

void Application::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	(void) scancode;
	(void) mods;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	if (key == GLFW_KEY_F12 && action == GLFW_PRESS)
		glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, 1920, 1080, 0);
}

void Application::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	(void) window;
	glViewport(0, 0, width, height);
	std::cout << "Window resized to " << width << "x" << height << std::endl;
}

void Application::mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
	(void) button;
	(void) action;
	(void) mods;
	(void) window;
}

void Application::mouse_position_callback(GLFWwindow *window, double xpos, double ypos)
{
	(void) window;
	(void) xpos;
	(void) ypos;
//	std::cout << "Mouse position: " << xpos << ", " << ypos << std::endl;
}


void Application::window_refresh_callback(GLFWwindow *window)
{
	(void) window;
}

void Application::print_info_config(const char *title) const
{
	int nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);

	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "OpenGL Shading version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	std::cout << "OpenGL Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Max Vertex attributes supported: " << nrAttributes << std::endl;
	std::cout << "" << std::endl;
	std::cout << "GLFW version: " << glfwGetVersionString() << std::endl;
	std::cout << "" << std::endl;
	std::cout << title << std::endl;
	std::cout << "Window size: " << width << "x" << height << std::endl;
	std::cout << "Window ratio: " << ratio << std::endl;
	std::cout << "Application created" << std::endl;
}
