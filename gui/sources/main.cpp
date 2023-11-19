#include <core/print.hpp>
#include <imgui/basic_imgui_application.hpp>
#include <imgui/widgets.hpp>

class HydeonGUI: public BasicImguiApplication{
	using Super = BasicImguiApplication;
	using ThisClass = HydeonGUI;

public:
	HydeonGUI():
		BasicImguiApplication(1280, 720, "Hydeon")
	{}

	void Tick(float dt)override {
		Super::Tick(dt);
	}

	void OnImGuiRender()override {
		Super::OnImGuiRender();

		ImGui::DockspaceWindow("Dock", Window().Size());


		ImGui::Begin("Status");
		ImGui::Text("I am hydeon");
		ImGui::End();
	}

	void OnEvent(const Event& e)override {
		Super::OnEvent(e);
	}
};


int main() {
	HydeonGUI app;

	app.Run();

	Println("Hello GUI");
}