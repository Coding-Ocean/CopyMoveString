#include<print>
#include"CHRONO.h"
using namespace std::chrono;

void CHRONO::start() 
{ 
	Start = system_clock::now(); 
}
void CHRONO::end() 
{
	End = system_clock::now();
	long long elapsed = duration_cast<milliseconds>(End - Start).count();
	std::println("elapsed:{}", elapsed / 1000.0f);
}
void CHRONO::localTime() 
{
	time_point now = system_clock::now();
	sys_seconds now_sec = floor<seconds>(now); // •b’PˆÊ
	zoned_seconds zoned_sec{ "Asia/Tokyo", now_sec };
	local_seconds local_sec = zoned_sec.get_local_time();
	std::println("{}", local_sec);
}