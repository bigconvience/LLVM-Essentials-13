//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements two versions of the LLVM "Hello World" pass described
// in docs/WritingAnLLVMPass.html
//
//===----------------------------------------------------------------------===//

#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

#define DEBUG_TYPE "FnNamePrint"


namespace {
  struct FnNamePrint: public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    FnNamePrint() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      errs() << "Function " << F.getName() << '\n'; 
      return false;
    }
  };
}

char FnNamePrint::ID = 0;
static RegisterPass<FnNamePrint> X("funcnameprint", "Function Name Print");
static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder,
      legacy::PassManagerBase &PM) { PM.add(new FnNamePrint()); });
