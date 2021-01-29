//array of 7 pointers toint, pointer toan array of 7 pointers toint, and array of 8 arrays of 7 pointers toint.

int main()
	// This does compile and is thus syntactically correct. What's not clear to me is why
	// one would do this, and whether these aliases really are aliases to what was
	// intended. Perhaps this was the point of the exercise.
{
	using UC = unsigned char;
	using CUC = const unsigned char;
	using PI = int*;
	using PPC = char**;
	using PAC = char**;
	using A7PI = int* [7];
	using PA7PI = A7PI*;
	using A8A7PI = PA7PI[8];
}
