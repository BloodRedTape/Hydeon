cmake_minimum_required(VERSION 3.10)


add_executable(HydeonRuntime
	"./sources/main.cpp"
)

target_link_libraries(HydeonRuntime PRIVATE HydeonCore)