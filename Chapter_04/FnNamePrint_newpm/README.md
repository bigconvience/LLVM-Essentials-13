<!--
 * @Author: your name
 * @Date: 2021-12-08 13:16:41
 * @LastEditTime: 2021-12-08 13:18:43
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \LLVM-Essentials-13\Chapter_04\FnNamePrint_newpm\README.md
-->

## New PassManager:
Ref:
https://llvm.org/docs/WritingAnLLVMNewPMPass.html
https://zhuanlan.zhihu.com/p/416754155

Note:
llvm/lib/Passes/PassRegistry.def

```
... ...

#ifndef FUNCTION_PASS
#define FUNCTION_PASS(NAME, CREATE_PASS)
#endif
... ...
FUNCTION_PASS("helloworld", HelloWorldPass())
... ...
#undef FUNCTION_PASS

... ...
```


llvm/lib/Passes/PassBuilder.cpp
```
#include "llvm/Transforms/Utils/FnNamePrint.h"

```


add follow in llvm/lib/Transforms/Utils/CMakeLists.txt

```
add_llvm_component_library(LLVMTransformUtils
  ... ...
  FnNamePrint.cpp
  ... ...
)
```
