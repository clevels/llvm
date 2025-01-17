// RUN: %clang_cc1 -I %S/Inputs -fsycl -fsycl-is-device -ast-dump %s | FileCheck %s

// This test checks that compiler generates correct kernel arguments for
// arrays, Accessor arrays, and structs containing Accessors.

#include <sycl.hpp>

using namespace cl::sycl;

template <typename name, typename Func>
__attribute__((sycl_kernel)) void a_kernel(Func kernelFunc) {
  kernelFunc();
}

int main() {

  using Accessor =
      accessor<int, 1, access::mode::read_write, access::target::global_buffer>;

  Accessor acc[2];
  int a[2];
  struct struct_acc_t {
    Accessor member_acc[4];
  } struct_acc;

  a_kernel<class kernel_A>(
      [=]() {
        acc[1].use();
      });

  a_kernel<class kernel_B>(
      [=]() {
        int local = a[1];
      });

  a_kernel<class kernel_C>(
      [=]() {
        struct_acc.member_acc[2].use();
      });
}

// Check kernel_A parameters
// CHECK: FunctionDecl {{.*}}kernel_A{{.*}} 'void (__global int *, cl::sycl::range<1>, cl::sycl::range<1>, cl::sycl::id<1>, __global int *, cl::sycl::range<1>, cl::sycl::range<1>, cl::sycl::id<1>)'
// CHECK-NEXT: ParmVarDecl {{.*}} used _arg_ '__global int *'
// CHECK-NEXT: ParmVarDecl {{.*}} used _arg_ 'cl::sycl::range<1>'
// CHECK-NEXT: ParmVarDecl {{.*}} used _arg_ 'cl::sycl::range<1>'
// CHECK-NEXT: ParmVarDecl {{.*}} used _arg_ 'cl::sycl::id<1>'
// CHECK-NEXT: ParmVarDecl {{.*}} used _arg_ '__global int *'
// CHECK-NEXT: ParmVarDecl {{.*}} used _arg_ 'cl::sycl::range<1>'
// CHECK-NEXT: ParmVarDecl {{.*}} used _arg_ 'cl::sycl::range<1>'
// CHECK-NEXT: ParmVarDecl {{.*}} used _arg_ 'cl::sycl::id<1>'
// CHECK: CXXMemberCallExpr {{.*}} 'void'
// CHECK-NEXT: MemberExpr {{.*}}__init
// CHECK: CXXMemberCallExpr {{.*}} 'void'
// CHECK-NEXT: MemberExpr {{.*}}__init

// Check kernel_B parameters
// CHECK: FunctionDecl {{.*}}kernel_B{{.*}} 'void (int, int)'
// CHECK-NEXT: ParmVarDecl {{.*}} used _arg_ 'int'
// CHECK-NEXT: ParmVarDecl {{.*}} used _arg_ 'int'
// Check kernel_B inits
// CHECK-NEXT: CompoundStmt
// CHECK-NEXT: DeclStmt
// CHECK-NEXT: VarDecl {{.*}} cinit
// CHECK-NEXT: InitListExpr
// CHECK-NEXT: InitListExpr {{.*}} 'int [2]'
// CHECK: ImplicitCastExpr
// CHECK: DeclRefExpr {{.*}} 'int' lvalue ParmVar {{.*}} '_arg_' 'int'
// CHECK: ImplicitCastExpr
// CHECK: DeclRefExpr {{.*}} 'int' lvalue ParmVar {{.*}} '_arg_' 'int'

// Correct and enable after struct members are extracted into separate parameters
// C HECK kernel_C parameters
// C HECK: FunctionDecl {{.*}}kernel_C{{.*}} 'void (struct {{.*}}, __global int *, cl::sycl::range<1>, cl::sycl::range<1>, cl::sycl::id<1>, __global int *, cl::sycl::range<1>, cl::sycl::range<1>, cl::sycl::id<1>, __global int *, cl::sycl::range<1>, cl::sycl::range<1>, cl::sycl::id<1>, __global int *, cl::sycl::range<1>, cl::sycl::range<1>, cl::sycl::id<1>)'
// C HECK-NEXT: ParmVarDecl {{.*}} 'struct {{.*}}'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc '__global int *'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc 'cl::sycl::range<1>'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc 'cl::sycl::range<1>'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc 'cl::sycl::id<1>'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc '__global int *'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc 'cl::sycl::range<1>'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc 'cl::sycl::range<1>'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc 'cl::sycl::id<1>'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc '__global int *'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc 'cl::sycl::range<1>'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc 'cl::sycl::range<1>'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc 'cl::sycl::id<1>'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc '__global int *'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc 'cl::sycl::range<1>'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc 'cl::sycl::range<1>'
// C HECK-NEXT: ParmVarDecl {{.*}} used _arg_member_acc 'cl::sycl::id<1>'

// C HECK that four accessor init functions are called
// C HECK: CXXMemberCallExpr {{.*}} 'void'
// C HECK-NEXT: MemberExpr {{.*}}__init
// C HECK: CXXMemberCallExpr {{.*}} 'void'
// C HECK-NEXT: MemberExpr {{.*}}__init
// C HECK: CXXMemberCallExpr {{.*}} 'void'
// C HECK-NEXT: MemberExpr {{.*}}__init
// C HECK: CXXMemberCallExpr {{.*}} 'void'
// C HECK-NEXT: MemberExpr {{.*}}__init
