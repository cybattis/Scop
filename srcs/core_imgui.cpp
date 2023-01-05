//
// Created by Cyril Battistolo on 19/12/2022.
//

#include "core_imgui.hpp"

UI::UI(GLFWwindow* window) : window(window)
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

void UI::setup(Model& obj, int width, int height)
{
	auto *app = static_cast<Application *>(glfwGetWindowUserPointer(window));

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	float side_panel_width = 350;

	ImGui::SetNextWindowSize(ImVec2(side_panel_width, height));
	ImGui::SetNextWindowPos(ImVec2(width - side_panel_width, 0));
	ImGui::Begin("Object settings", nullptr,
			ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);

	ImGui::PushItemWidth(300);
	ImGui::SliderFloat3("Pos", &obj.position[0], -100.0f, 100.0f, "%.1f");
	ImGui::SliderFloat3("Rot", &obj.rotation[0], -180.0f, 180.0f, "%.1f");
	ImGui::SliderFloat("Scale", &obj.scale[0], 0.0f, 30.0f, "%.2f", ImGuiSliderFlags_Logarithmic);

	if (ImGui::Checkbox("Wireframe", &is_wireframe))
		update_event();

	// Parse files in directory
	const std::filesystem::path dir{"assets"};
	std::vector<std::string> items;
	for (auto const& dir_entry : std::filesystem::directory_iterator{dir})
	{
		if (dir_entry.path().extension() == ".obj")
			items.push_back(dir_entry.path().filename().string());
	}

	ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();

	ImGui::SliderFloat("Ambient", &app->render.light.intensity, 0.0f, 100.0f, "%.2f", ImGuiSliderFlags_Logarithmic);
	ImGui::ColorEdit3("Light color", &app->render.light.color[0]);
	ImGui::SliderFloat("x", &app->render.light.model.position[0], -200.0f, 200.0f, "%.1f");
	ImGui::SliderFloat("y", &app->render.light.model.position[1], -200.0f, 200.0f, "%.1f");
	ImGui::SliderFloat("z", &app->render.light.model.position[2], -200.0f, 200.0f, "%.1f");

	ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();

	// Combo
	ImGui::AlignTextToFramePadding();
	ImGui::Text("Load model");

	static unsigned int item_current_idx = 0; // Here we store our selection data as an index.
	std::string combo_preview_value = items[item_current_idx];
	ImGui::PushItemWidth(250);
	if (ImGui::BeginCombo(" ", combo_preview_value.c_str(), 0))
	{
		for (unsigned int n = 0; n < items.size(); n++)
		{
			const bool is_selected = (item_current_idx == n);
			if (ImGui::Selectable(items[n].c_str(), is_selected))
			{
				item_current_idx = n;
				obj = Model("assets/" + items[n]);
			}

			// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}

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
