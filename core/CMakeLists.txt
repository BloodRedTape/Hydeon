cmake_minimum_required(VERSION 3.10)

add_subdirectory(libs/straitx-core)

add_library(HydeonCore STATIC
	"./sources/object.cpp"
)

target_link_libraries(HydeonCore
	PUBLIC StraitXCore
)