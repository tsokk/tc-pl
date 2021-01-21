#include <iostream>
#include <thread>
#include <chrono>
 
void hello()
{
	while (true) {
		std::cout << "Hello ";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
 
void world()
{
	while (true) {
		std::cout << "World!\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
 
int main()
{
	std::thread helper1(hello);
	std::thread helper2(world); 

	helper1.join();
	helper2.join();
 }

