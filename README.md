LLVM Essentials Book Code (update to LLVM 13)

## [Getting Started](https://llvm.org/docs/GettingStarted.html#getting-the-source-code-and-building-llvm)

### get llvm

```
git clone https://github.com/llvm/llvm-project.git
```

### build llvm

```
cd llvm-project
mkdir llvm-build
cd llvm-build
cmake -G "Unix Makefiles" -DLLVM_TARGETS_TO_BUILD=X86 -DCMAKE_INSTALL_PREFIX=/usr/local/clang -DCMAKE_BUILD_TYPE=Debug ../llvm/
make
make install
```

### build clang

```
cd llvm-project/clang
mkdir clang-build
cd clang-build
cmake -G "Unix Makefiles" -DLLVM_TARGETS_TO_BUILD=X86 -DCMAKE_INSTALL_PREFIX=/usr/local/clang -DCMAKE_BUILD_TYPE=Debug ../clang/
make 
make install
```

### opt
-enable-new-pm=0
[work pass](https://zhuanlan.zhihu.com/p/392381317)
