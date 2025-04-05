#pragma once

#include <jsi/jsi.h>
#include "external_class.h"

namespace ForTest {
	using Dispatcher = std::function<void(std::function<void()>)>;
	void Initialize(facebook::jsi::Runtime &jsiRuntime, Dispatcher jsDispatcher);
}