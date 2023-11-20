#include <core/print.hpp>
#include <core/string.hpp>
#include <imgui/basic_imgui_application.hpp>
#include <imgui/widgets.hpp>
#include "async_input_stream.hpp"
#include <iostream>

class HydeonGUI: public BasicImguiApplication{
	using Super = BasicImguiApplication;
	using ThisClass = HydeonGUI;
	
	String m_InputText;

	AsyncInputStream m_StdIn{std::cin};
public:
	HydeonGUI():
		BasicImguiApplication(1280, 720, "Hydeon")
	{}

	void Tick(float dt)override {
		Super::Tick(dt);
		
		Optional<String> input = m_StdIn.Read();

		if (input.HasValue()) {
			HandleTextInput(input.Value());
		}
	}

	void HandleTextInput(const String &string) {
		m_InputText.Append(string);
	}

	void OnImGui()override {
		Super::OnImGui();

		ImGui::DockspaceWindow("Dock", Window().Size());


		ImGui::Begin("Status");
		ImGui::Text("I am hydeon");
		ImGui::Text("Input: %s", m_InputText.Data());
		ImGui::End();
	}

	void OnEvent(const Event& e)override {
		Super::OnEvent(e);
	}
};


int main() {
	HydeonGUI app;

	return app.Run();
}