#include "pch.h"
#include "jsitest.h"
#include "JSI/JsiApiContext.h"

namespace winrt::jsitest
{

// See https://microsoft.github.io/react-native-windows/docs/native-modules for details on writing native modules

void JsiTest::Initialize(React::ReactContext const &reactContext) noexcept {
  m_context = reactContext;
}

void JsiTest::Test(React::ReactPromise<bool> const &result) noexcept {
  React::ExecuteJsi(m_context, [res, weakThis{ this->weak_from_this() }](facebook::jsi::Runtime &jsiRuntime) {
    if (auto trueThis = weakThis.lock()) {
      auto jsDispatcher = [weakThis{ trueThis->weak_from_this() }](std::function<void()> func) {
        if (auto trueThis = weakThis.lock()) {
          trueThis->m_context.JSDispatcher().Post([weakThis, func{ std::move(func) }]() {
            func();
          });
        }
      };
      ForTest::Initialize(jsiRuntime, jsDispatcher);
      result.Resolve(true);
    }
  });
}

} // namespace winrt::jsitest