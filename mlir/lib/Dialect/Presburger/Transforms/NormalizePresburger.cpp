//===- StdExpandDivs.cpp - Code to prepare Std for lowering Divs to LLVM  -===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file Std transformations to expand Divs operation to help for the
// lowering to LLVM. Currently implemented transformations are Ceil and Floor
// for Signed Integers.
//
//===----------------------------------------------------------------------===//

#include "PassDetail.h"

#include "mlir/Dialect/Arithmetic/IR/Arithmetic.h"
#include "mlir/Dialect/Arithmetic/Transforms/Passes.h"
#include "mlir/Dialect/Presburger/IR/Presburger.h"
#include "mlir/Dialect/Presburger/Transforms/Passes.h"
#include "mlir/IR/TypeUtilities.h"
#include "mlir/Transforms/DialectConversion.h"

using namespace mlir;

namespace {

struct NormalizePresburgerSetOp : public OpRewritePattern<presburger::SetOp> {
public:
  using OpRewritePattern::OpRewritePattern;

  LogicalResult matchAndRewrite(presburger::SetOp op,
                                PatternRewriter &rewriter) const final {
    op.dump();
    return success();
  }
};

struct NormalizePresburgerOps : public PresburgerOpsBase<PresbugerOpsPass> {
  void runOnOperation() override {
    MLIRContext &ctx = getContext();

    RewritePatternSet patterns(&ctx);
    memref::populateExpandOpsPatterns(patterns);
    ConversionTarget target(ctx);

    target.addLegalDialect<presburger::PresburgetDialect,
                           arith::ArithmeticDialect, memref::MemRefDialect,
                           affine::AffineDialect>();
    if (failed(applyPartialConversion(getOperation(), target,
                                      std::move(patterns))))
      signalPassFailure();
  }
};

} // namespace

void mlir::memref::populatePresburgerOpsPatterns(RewritePatternSet &patterns) {
  patterns.add<NormalizePresburgerSetOp>(
      patterns.getContext());
}

std::unique_ptr<Pass> mlir::memref::createPresburgerNormalizePass() {
  return std::make_unique<ExpandOpsPass>();
}
