#pragma once
#include<chrono>
class CHRONO
{
	std::chrono::system_clock::time_point Start;
	std::chrono::system_clock::time_point End;
public:
	void start();
	void end();
	void localTime();
};