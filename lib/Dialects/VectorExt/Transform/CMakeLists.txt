add_mlir_library(MLIRVectorExtTransform
  VectorMaskingUtils.cpp
  VectorWarpUtils.cpp

  DEPENDS
  mlir-headers
  MLIRVectorExt

  LINK_LIBS PUBLIC
  MLIRAffine
  MLIRGPUOps
  MLIRIR
  MLIRLinalg
  MLIRVector
  MLIRVectorExt
  MLIRVectorUtils
)
