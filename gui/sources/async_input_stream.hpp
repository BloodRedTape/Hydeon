#pragma once

#include <future>
#include <istream>
#include <core/string.hpp>
#include <core/optional.hpp>

class AsyncInputStream{
	std::istream &m_Stream;
	std::future<String> m_Input;
public:
	AsyncInputStream(std::istream &stream);

	bool IsReady()const;

	String Get();

	Optional<String> Read();

private:
	void StartWaitStdIn();
};

