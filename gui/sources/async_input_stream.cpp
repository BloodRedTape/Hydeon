#include "async_input_stream.hpp"
#include <chrono>
#include <string>

AsyncInputStream::AsyncInputStream(std::istream &stream):
	m_Stream(stream)
{
	StartWaitStdIn();
}

bool AsyncInputStream::IsReady() const{
	using namespace std::chrono_literals;
	return m_Input.wait_for(0s) == std::future_status::ready;
}

String AsyncInputStream::Get(){
	return m_Input.get();
}

Optional<String> AsyncInputStream::Read() {
	Optional<String> read;

	if (IsReady()) {
		read = Get();
		StartWaitStdIn();
	}

	return read;
}

void AsyncInputStream::StartWaitStdIn() {
	m_Input = std::async(std::launch::async, [&stream = m_Stream]()->String {
		std::string answer;
		std::getline(stream, answer);
		return { answer.c_str(), answer.size() };
	});
}