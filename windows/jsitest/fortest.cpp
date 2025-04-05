#include "fortest.h"

namespace ForTest {
  class ReactNativeModule : public jsi::HostObject {
    public:
      ReactNativeModule(facebook::jsi::Runtime& jsiRuntime, Dispatcher jsDispatcher) {
        ExternalClass::Test(jsiRuntime);
      }
  };

	void Initialize(facebook::jsi::Runtime& jsiRuntime, Dispatcher jsDispatcher) {
    if (!jsiRuntime.global().hasProperty(jsiRuntime, JS_INSTANCE_NAME)) {
      auto nativeModule{ std::make_shared<ReactNativeModule>(jsiRuntime, jsDispatcher) };
      jsiRuntime.global().setProperty(jsiRuntime, JS_INSTANCE_NAME, jsi::Object::createFromHostObject(jsiRuntime, nativeModule));
      g_nativeModule = nativeModule;
    }
    if (auto nativeModule{ g_nativeModule.lock() }) {
      // nativeModule->Initialize();
    }
	}
}