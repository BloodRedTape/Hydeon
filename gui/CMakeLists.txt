cmake_minimum_required(VERSION 3.10)

add_subdirectory(libs/straitx-graphics)
add_subdirectory(libs/straitx-imgui)

add_executable(HydeonGUI
	"./sources/main.cpp"
)

target_link_libraries(HydeonGUI 
	PRIVATE HydeonCore
	PRIVATE StraitXCore
	PRIVATE StraitXGraphics
	PRIVATE StraitXImGui
)