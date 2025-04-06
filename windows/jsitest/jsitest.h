#pragma once

#include "pch.h"
#include "resource.h"
#include "fortest.h"

#if __has_include("codegen/NativeJsiTestDataTypes.g.h")
  #include "codegen/NativeJsiTestDataTypes.g.h"
#endif
#include "codegen/NativeJsiTestSpec.g.h"

#include "NativeModules.h"

namespace winrt::jsitest
{
  REACT_MODULE(JsiTest)
  struct JsiTest: std::enable_shared_from_this<JsiTest> {
    using ModuleSpec = jsiTestCodegen::JsiTestSpec;

    REACT_INIT(Initialize)
    void Initialize(React::ReactContext const &reactContext) noexcept;

    REACT_METHOD(Test, L"test")
    void Test(React::ReactPromise<void> const &result) noexcept;

  private:
    React::ReactContext m_context;
};

} // namespace winrt::jsitest