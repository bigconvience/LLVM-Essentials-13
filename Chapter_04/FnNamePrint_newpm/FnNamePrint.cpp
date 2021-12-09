/*
 * @Author: your name
 * @Date: 2021-12-08 13:05:58
 * @LastEditTime: 2021-12-08 13:07:17
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \LLVM-Essentials-13\Chapter_04\FnNamePrint_newpm\FnNamePrint.cpp
 */
#include "llvm/Transforms/Utils/FnNamePrint.h"

using namespace llvm;

PreservedAnalyses FnNamePrintPass::run(Function &F,
                                      FunctionAnalysisManager &AM) {
  errs() << F.getName() << "\n";
  return PreservedAnalyses::all();
}
