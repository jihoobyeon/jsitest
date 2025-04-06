#include "pch.h"
#include "fortest.h"

namespace ForTest {
  class ReactNativeModule : public facebook::jsi::HostObject {
    public:
      ReactNativeModule(facebook::jsi::Runtime& jsiRuntime, Dispatcher jsDispatcher) {
        ExternalClass::Test(jsiRuntime);
      }
  };

  std::weak_ptr<ReactNativeModule> g_nativeModule{};

	void Initialize(facebook::jsi::Runtime& jsiRuntime, Dispatcher jsDispatcher) {
    if (!jsiRuntime.global().hasProperty(jsiRuntime, "JsiTest")) {
      auto nativeModule{ std::make_shared<ReactNativeModule>(jsiRuntime, jsDispatcher) };
      jsiRuntime.global().setProperty(jsiRuntime, "JsiTest", facebook::jsi::Object::createFromHostObject(jsiRuntime, nativeModule));
      g_nativeModule = nativeModule;
    }
    if (auto nativeModule{ g_nativeModule.lock() }) {
      // nativeModule->Initialize();
    }
	}
}