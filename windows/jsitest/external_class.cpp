#include "external_class.h"

namespace ExternalClass {
	void Test(facebook::jsi::Runtime& jsiRuntime) {
		std::cout << "Memory address of JSI Runtime: " << &rt << std::endl;
	}
}