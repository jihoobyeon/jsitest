#include "pch.h"
#include "external_class.h"

namespace ExternalClass {
	void Test(facebook::jsi::Runtime& jsiRuntime) {
		std::wstringstream wss;
		wss << std::hex << (uintptr_t)&jsiRuntime;
		MessageBox(NULL, wss.str().c_str(), L"테스트", MB_OK);
	}
}