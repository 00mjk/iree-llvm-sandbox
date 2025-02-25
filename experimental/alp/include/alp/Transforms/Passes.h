//===- Passes.h - Alp pass entry points ----------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This header file defines prototypes that expose pass constructors.
//
//===----------------------------------------------------------------------===//

#ifndef ALP_LLVM_SANDBOX_PASSES_H
#define ALP_LLVM_SANDBOX_PASSES_H

#include "mlir/Pass/Pass.h"

namespace mlir {

/// Create a pass extract the kernel function out
std::unique_ptr<mlir::OperationPass<ModuleOp>> createExtractKernelPass();

/// Create a pass extract the kernel function out 
std::unique_ptr<mlir::OperationPass<ModuleOp>> createExtractKernelTailPass();

/// Create a pass to modulo-schedule the kernel
std::unique_ptr<mlir::OperationPass<FuncOp>> createModuloSchedulingPass();

/// Create a pass to legalize vectors in a given function
std::unique_ptr<mlir::OperationPass<FuncOp>> createLegalizePass();

/// Create a pass to transform a For-Loop to a Do-While loop
std::unique_ptr<mlir::OperationPass<FuncOp>> createForToDoWhileLoopPass();

//===----------------------------------------------------------------------===//
// Registration
//===----------------------------------------------------------------------===//

/// Generate the code for registering passes.
#define GEN_PASS_REGISTRATION
#include "alp/Transforms/Passes.h.inc"

} // namespace mlir

#endif // ALP_LLVM_SANDBOX_PASSES_H
