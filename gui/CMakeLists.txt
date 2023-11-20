cmake_minimum_required(VERSION 3.10)

add_subdirectory(libs/straitx-graphics)
add_subdirectory(libs/straitx-imgui)

add_executable(HydeonGUI
	"./sources/main.cpp"
	"./sources/async_input_stream.cpp"
)

target_link_libraries(HydeonGUI 
	PUBLIC HydeonCore
	PUBLIC StraitXCore
	PUBLIC StraitXGraphics
	PUBLIC StraitXImGui
)