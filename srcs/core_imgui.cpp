//
// Created by Cyril Battistolo on 19/12/2022.
//

#include "core_imgui.hpp"

UI::UI(GLFWwindow* window)
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	// Setup style
	ImGui::StyleColorsDark();
//	ImGui::StyleColorsClassic();

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	io.Fonts->AddFontDefault();
}

UI::~UI()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	std::cerr << "UI destroyed" << std::endl;
}

void UI::setup(int width, int height, float* mixValue, float* xOffset, float* yOffset)
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	// Imgui config
	ImGui::SetNextWindowSize(ImVec2(static_cast<float>(width) / 5, static_cast<float>(height)));
	ImGui::SetNextWindowPos(ImVec2(static_cast<float>(width) - static_cast<float>(width) / 5, 0));
	ImGui::Begin("Hello, world!");
	if (ImGui::Checkbox("Wireframe", &is_wireframe))
		update_event();
	ImGui::SliderFloat("Mix value", mixValue, 0.0f, 1.0f);
	// two slider on the same line with label on top
	ImGui::Text("Offset");
	ImGui::PushItemWidth(100);
	ImGui::SliderFloat("X", xOffset, -1.0f, 1.0f);
	ImGui::SameLine();
	ImGui::PushItemWidth(100);
	ImGui::SliderFloat("Y", yOffset, -1.0f, 1.0f);
	// change size slider

	ImGui::End();
}

void UI::render()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UI::update_event()
{
	std::cout << "Update event" << std::endl;
	std::cout << "Wireframe: " << is_wireframe << std::endl;
	if (is_wireframe) {
		std::cout << "Wireframe mode enabled" << std::endl;
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else {
		std::cout << "Wireframe mode disable" << std::endl;
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}
