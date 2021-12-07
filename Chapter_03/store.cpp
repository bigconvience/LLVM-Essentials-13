#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include <vector>
using namespace llvm;

static LLVMContext TheContext;
static LLVMContext &getGlobalContext()
{
  return TheContext;
}
static LLVMContext &Context = getGlobalContext();
static Module *ModuleOb = new Module("my compiler", Context);
static std::vector<std::string> FunArgs;

Function *createFunc(IRBuilder<> &Builder, std::string Name)
{
  Type *u32Ty = Type::getInt32Ty(Context);
  Type *vecTy = VectorType::get(u32Ty, 2, false);
  Type *ptrTy = vecTy->getPointerTo(0);
  FunctionType *funcType = FunctionType::get(Builder.getInt32Ty(), ptrTy, false);
  Function *fooFunc = Function::Create(
      funcType, Function::ExternalLinkage, Name, ModuleOb);
  return fooFunc;
}

void setFuncArgs(Function *fooFunc, std::vector<std::string> FunArgs)
{
  unsigned Idx = 0;
  Function::arg_iterator AI, AE;
  for (AI = fooFunc->arg_begin(), AE = fooFunc->arg_end(); AI != AE;
       ++AI, ++Idx)
    AI->setName(FunArgs[Idx]);
}

BasicBlock *createBB(Function *fooFunc, std::string Name)
{
  return BasicBlock::Create(Context, Name, fooFunc);
}

Value *createArith(IRBuilder<> &Builder, Value *L, Value *R) {
  return Builder.CreateMul(L, R, "multmp");
}

Value *getGEP(IRBuilder<> &Builder, Value *Base, ArrayRef<Value *> Offset)
{
  return Builder.CreateGEP(Base, Offset, "a1");
}

Value *getLoad(IRBuilder<> &Builder, Value *Address)
{
  return Builder.CreateLoad(Address, "load");
}

void getStore(IRBuilder<> &Builder, Value *Address, Value *V) 
{
  Builder.CreateStore(V, Address);
}

int main(int argc, char *argv[])
{
  FunArgs.push_back("a");
  static IRBuilder<> Builder(Context);
  Function *fooFunc = createFunc(Builder, "foo");
  setFuncArgs(fooFunc, FunArgs);
  Value *Base = fooFunc->arg_begin();
  BasicBlock *entry = createBB(fooFunc, "entry");
  Builder.SetInsertPoint(entry);
  Value *gep = getGEP(Builder, Base, {Builder.getInt32(0), Builder.getInt32(1)});
  Value *load = getLoad(Builder, gep);
  Value *constant = Builder.getInt32(16);
  Value *val = createArith(Builder, load, constant);
  getStore(Builder, gep, val);
  Builder.CreateRet(val);
  verifyFunction(*fooFunc);
  ModuleOb->print(errs(), nullptr);
  return 0;
}