/*
 * @Author: your name
 * @Date: 2021-12-08 13:03:15
 * @LastEditTime: 2021-12-08 13:05:12
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \LLVM-Essentials-13\Chapter_04\FnNamePrint_newpm\FnNamePrint.h
 */
#ifndef LLVM_TRANSFORMS_FNNAMEPRINT_H
#define LLVM_TRANSFORMS_FNNAMEPRINT_H

#include "llvm/IR/PassManager.h"

namespace llvm {

class FnNamePrintPass : public PassInfoMixin<FnNamePrintPass> {
public:
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
};

} // namespace llvm

#endif // LLVM_TRANSFORMS_FNNAMEPRINT_H