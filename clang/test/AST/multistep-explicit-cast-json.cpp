// RUN: %clang_cc1 -triple x86_64-linux-gnu -fsyntax-only -ast-dump=json %s | FileCheck %s

unsigned char implicitcast_0(unsigned int x) {
  return x;
}

signed char implicitcast_1(unsigned int x) {
  return x;
}

unsigned char implicitcast_2(signed int x) {
  return x;
}

signed char implicitcast_3(signed int x) {
  return x;
}

//----------------------------------------------------------------------------//

unsigned char cstylecast_0(unsigned int x) {
  return (unsigned char)x;
}

signed char cstylecast_1(unsigned int x) {
  return (signed char)x;
}

unsigned char cstylecast_2(signed int x) {
  return (unsigned char)x;
}

signed char cstylecast_3(signed int x) {
  return (signed char)x;
}

//----------------------------------------------------------------------------//

unsigned char cxxstaticcast_0(unsigned int x) {
  return static_cast<unsigned char>(x);
}

signed char cxxstaticcast_1(unsigned int x) {
  return static_cast<signed char>(x);
}

unsigned char cxxstaticcast_2(signed int x) {
  return static_cast<unsigned char>(x);
}

signed char cxxstaticcast_3(signed int x) {
  return static_cast<signed char>(x);
}

//----------------------------------------------------------------------------//

using UnsignedChar = unsigned char;
using SignedChar = signed char;
using UnsignedInt = unsigned int;
using SignedInt = signed int;

UnsignedChar cxxfunctionalcast_0(UnsignedInt x) {
  return UnsignedChar(x);
}

SignedChar cxxfunctionalcast_1(UnsignedInt x) {
  return SignedChar(x);
}

UnsignedChar cxxfunctionalcast_2(SignedInt x) {
  return UnsignedChar(x);
}

SignedChar cxxfunctionalcast_3(SignedInt x) {
  return SignedChar(x);
}


// CHECK:  "kind": "ImplicitCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 4
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 4
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "qualType": "unsigned char"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "IntegralCast",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 10,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 4
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 10,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 4
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "qualType": "unsigned int"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "LValueToRValue",
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "DeclRefExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 10,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 4
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 10,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 4
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "qualType": "unsigned int"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "lvalue",
// CHECK-NEXT:      "referencedDecl": {
// CHECK-NEXT:       "id": "0x{{.*}}",
// CHECK-NEXT:       "kind": "ParmVarDecl",
// CHECK-NEXT:       "name": "x",
// CHECK-NEXT:       "type": {
// CHECK-NEXT:        "qualType": "unsigned int"
// CHECK-NEXT:       }
// CHECK-NEXT:      }
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "ImplicitCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 8
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 8
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "qualType": "signed char"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "IntegralCast",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 10,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 8
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 10,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 8
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "qualType": "unsigned int"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "LValueToRValue",
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "DeclRefExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 10,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 8
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 10,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 8
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "qualType": "unsigned int"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "lvalue",
// CHECK-NEXT:      "referencedDecl": {
// CHECK-NEXT:       "id": "0x{{.*}}",
// CHECK-NEXT:       "kind": "ParmVarDecl",
// CHECK-NEXT:       "name": "x",
// CHECK-NEXT:       "type": {
// CHECK-NEXT:        "qualType": "unsigned int"
// CHECK-NEXT:       }
// CHECK-NEXT:      }
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "ImplicitCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 12
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 12
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "qualType": "unsigned char"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "IntegralCast",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 10,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 12
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 10,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 12
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "qualType": "int"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "LValueToRValue",
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "DeclRefExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 10,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 12
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 10,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 12
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "qualType": "int"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "lvalue",
// CHECK-NEXT:      "referencedDecl": {
// CHECK-NEXT:       "id": "0x{{.*}}",
// CHECK-NEXT:       "kind": "ParmVarDecl",
// CHECK-NEXT:       "name": "x",
// CHECK-NEXT:       "type": {
// CHECK-NEXT:        "qualType": "int"
// CHECK-NEXT:       }
// CHECK-NEXT:      }
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "ImplicitCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 16
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 16
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "qualType": "signed char"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "IntegralCast",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 10,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 16
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 10,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 16
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "qualType": "int"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "LValueToRValue",
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "DeclRefExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 10,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 16
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 10,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 16
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "qualType": "int"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "lvalue",
// CHECK-NEXT:      "referencedDecl": {
// CHECK-NEXT:       "id": "0x{{.*}}",
// CHECK-NEXT:       "kind": "ParmVarDecl",
// CHECK-NEXT:       "name": "x",
// CHECK-NEXT:       "type": {
// CHECK-NEXT:        "qualType": "int"
// CHECK-NEXT:       }
// CHECK-NEXT:      }
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "CStyleCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 22
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 25,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 22
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "qualType": "unsigned char"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "NoOp",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 25,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 22
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 25,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 22
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "qualType": "unsigned char"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "IntegralCast",
// CHECK-NEXT:    "isPartOfExplicitCast": true,
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "ImplicitCastExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 25,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 22
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 25,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 22
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "qualType": "unsigned int"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "rvalue",
// CHECK-NEXT:      "castKind": "LValueToRValue",
// CHECK-NEXT:      "isPartOfExplicitCast": true,
// CHECK-NEXT:      "inner": [
// CHECK-NEXT:       {
// CHECK-NEXT:        "id": "0x{{.*}}",
// CHECK-NEXT:        "kind": "DeclRefExpr",
// CHECK-NEXT:        "range": {
// CHECK-NEXT:         "begin": {
// CHECK-NEXT:          "col": 25,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 22
// CHECK-NEXT:         },
// CHECK-NEXT:         "end": {
// CHECK-NEXT:          "col": 25,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 22
// CHECK-NEXT:         }
// CHECK-NEXT:        },
// CHECK-NEXT:        "type": {
// CHECK-NEXT:         "qualType": "unsigned int"
// CHECK-NEXT:        },
// CHECK-NEXT:        "valueCategory": "lvalue",
// CHECK-NEXT:        "referencedDecl": {
// CHECK-NEXT:         "id": "0x{{.*}}",
// CHECK-NEXT:         "kind": "ParmVarDecl",
// CHECK-NEXT:         "name": "x",
// CHECK-NEXT:         "type": {
// CHECK-NEXT:          "qualType": "unsigned int"
// CHECK-NEXT:         }
// CHECK-NEXT:        }
// CHECK-NEXT:       }
// CHECK-NEXT:      ]
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "CStyleCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 26
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 23,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 26
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "qualType": "signed char"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "NoOp",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 23,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 26
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 23,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 26
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "qualType": "signed char"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "IntegralCast",
// CHECK-NEXT:    "isPartOfExplicitCast": true,
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "ImplicitCastExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 23,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 26
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 23,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 26
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "qualType": "unsigned int"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "rvalue",
// CHECK-NEXT:      "castKind": "LValueToRValue",
// CHECK-NEXT:      "isPartOfExplicitCast": true,
// CHECK-NEXT:      "inner": [
// CHECK-NEXT:       {
// CHECK-NEXT:        "id": "0x{{.*}}",
// CHECK-NEXT:        "kind": "DeclRefExpr",
// CHECK-NEXT:        "range": {
// CHECK-NEXT:         "begin": {
// CHECK-NEXT:          "col": 23,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 26
// CHECK-NEXT:         },
// CHECK-NEXT:         "end": {
// CHECK-NEXT:          "col": 23,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 26
// CHECK-NEXT:         }
// CHECK-NEXT:        },
// CHECK-NEXT:        "type": {
// CHECK-NEXT:         "qualType": "unsigned int"
// CHECK-NEXT:        },
// CHECK-NEXT:        "valueCategory": "lvalue",
// CHECK-NEXT:        "referencedDecl": {
// CHECK-NEXT:         "id": "0x{{.*}}",
// CHECK-NEXT:         "kind": "ParmVarDecl",
// CHECK-NEXT:         "name": "x",
// CHECK-NEXT:         "type": {
// CHECK-NEXT:          "qualType": "unsigned int"
// CHECK-NEXT:         }
// CHECK-NEXT:        }
// CHECK-NEXT:       }
// CHECK-NEXT:      ]
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "CStyleCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 30
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 25,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 30
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "qualType": "unsigned char"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "NoOp",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 25,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 30
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 25,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 30
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "qualType": "unsigned char"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "IntegralCast",
// CHECK-NEXT:    "isPartOfExplicitCast": true,
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "ImplicitCastExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 25,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 30
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 25,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 30
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "qualType": "int"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "rvalue",
// CHECK-NEXT:      "castKind": "LValueToRValue",
// CHECK-NEXT:      "isPartOfExplicitCast": true,
// CHECK-NEXT:      "inner": [
// CHECK-NEXT:       {
// CHECK-NEXT:        "id": "0x{{.*}}",
// CHECK-NEXT:        "kind": "DeclRefExpr",
// CHECK-NEXT:        "range": {
// CHECK-NEXT:         "begin": {
// CHECK-NEXT:          "col": 25,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 30
// CHECK-NEXT:         },
// CHECK-NEXT:         "end": {
// CHECK-NEXT:          "col": 25,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 30
// CHECK-NEXT:         }
// CHECK-NEXT:        },
// CHECK-NEXT:        "type": {
// CHECK-NEXT:         "qualType": "int"
// CHECK-NEXT:        },
// CHECK-NEXT:        "valueCategory": "lvalue",
// CHECK-NEXT:        "referencedDecl": {
// CHECK-NEXT:         "id": "0x{{.*}}",
// CHECK-NEXT:         "kind": "ParmVarDecl",
// CHECK-NEXT:         "name": "x",
// CHECK-NEXT:         "type": {
// CHECK-NEXT:          "qualType": "int"
// CHECK-NEXT:         }
// CHECK-NEXT:        }
// CHECK-NEXT:       }
// CHECK-NEXT:      ]
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "CStyleCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 34
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 23,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 34
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "qualType": "signed char"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "NoOp",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 23,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 34
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 23,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 34
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "qualType": "signed char"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "IntegralCast",
// CHECK-NEXT:    "isPartOfExplicitCast": true,
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "ImplicitCastExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 23,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 34
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 23,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 34
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "qualType": "int"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "rvalue",
// CHECK-NEXT:      "castKind": "LValueToRValue",
// CHECK-NEXT:      "isPartOfExplicitCast": true,
// CHECK-NEXT:      "inner": [
// CHECK-NEXT:       {
// CHECK-NEXT:        "id": "0x{{.*}}",
// CHECK-NEXT:        "kind": "DeclRefExpr",
// CHECK-NEXT:        "range": {
// CHECK-NEXT:         "begin": {
// CHECK-NEXT:          "col": 23,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 34
// CHECK-NEXT:         },
// CHECK-NEXT:         "end": {
// CHECK-NEXT:          "col": 23,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 34
// CHECK-NEXT:         }
// CHECK-NEXT:        },
// CHECK-NEXT:        "type": {
// CHECK-NEXT:         "qualType": "int"
// CHECK-NEXT:        },
// CHECK-NEXT:        "valueCategory": "lvalue",
// CHECK-NEXT:        "referencedDecl": {
// CHECK-NEXT:         "id": "0x{{.*}}",
// CHECK-NEXT:         "kind": "ParmVarDecl",
// CHECK-NEXT:         "name": "x",
// CHECK-NEXT:         "type": {
// CHECK-NEXT:          "qualType": "int"
// CHECK-NEXT:         }
// CHECK-NEXT:        }
// CHECK-NEXT:       }
// CHECK-NEXT:      ]
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "CXXStaticCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 40
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 38,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 40
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "qualType": "unsigned char"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "NoOp",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 37,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 40
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 37,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 40
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "qualType": "unsigned char"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "IntegralCast",
// CHECK-NEXT:    "isPartOfExplicitCast": true,
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "ImplicitCastExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 37,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 40
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 37,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 40
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "qualType": "unsigned int"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "rvalue",
// CHECK-NEXT:      "castKind": "LValueToRValue",
// CHECK-NEXT:      "isPartOfExplicitCast": true,
// CHECK-NEXT:      "inner": [
// CHECK-NEXT:       {
// CHECK-NEXT:        "id": "0x{{.*}}",
// CHECK-NEXT:        "kind": "DeclRefExpr",
// CHECK-NEXT:        "range": {
// CHECK-NEXT:         "begin": {
// CHECK-NEXT:          "col": 37,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 40
// CHECK-NEXT:         },
// CHECK-NEXT:         "end": {
// CHECK-NEXT:          "col": 37,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 40
// CHECK-NEXT:         }
// CHECK-NEXT:        },
// CHECK-NEXT:        "type": {
// CHECK-NEXT:         "qualType": "unsigned int"
// CHECK-NEXT:        },
// CHECK-NEXT:        "valueCategory": "lvalue",
// CHECK-NEXT:        "referencedDecl": {
// CHECK-NEXT:         "id": "0x{{.*}}",
// CHECK-NEXT:         "kind": "ParmVarDecl",
// CHECK-NEXT:         "name": "x",
// CHECK-NEXT:         "type": {
// CHECK-NEXT:          "qualType": "unsigned int"
// CHECK-NEXT:         }
// CHECK-NEXT:        }
// CHECK-NEXT:       }
// CHECK-NEXT:      ]
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "CXXStaticCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 44
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 36,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 44
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "qualType": "signed char"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "NoOp",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 35,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 44
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 35,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 44
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "qualType": "signed char"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "IntegralCast",
// CHECK-NEXT:    "isPartOfExplicitCast": true,
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "ImplicitCastExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 35,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 44
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 35,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 44
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "qualType": "unsigned int"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "rvalue",
// CHECK-NEXT:      "castKind": "LValueToRValue",
// CHECK-NEXT:      "isPartOfExplicitCast": true,
// CHECK-NEXT:      "inner": [
// CHECK-NEXT:       {
// CHECK-NEXT:        "id": "0x{{.*}}",
// CHECK-NEXT:        "kind": "DeclRefExpr",
// CHECK-NEXT:        "range": {
// CHECK-NEXT:         "begin": {
// CHECK-NEXT:          "col": 35,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 44
// CHECK-NEXT:         },
// CHECK-NEXT:         "end": {
// CHECK-NEXT:          "col": 35,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 44
// CHECK-NEXT:         }
// CHECK-NEXT:        },
// CHECK-NEXT:        "type": {
// CHECK-NEXT:         "qualType": "unsigned int"
// CHECK-NEXT:        },
// CHECK-NEXT:        "valueCategory": "lvalue",
// CHECK-NEXT:        "referencedDecl": {
// CHECK-NEXT:         "id": "0x{{.*}}",
// CHECK-NEXT:         "kind": "ParmVarDecl",
// CHECK-NEXT:         "name": "x",
// CHECK-NEXT:         "type": {
// CHECK-NEXT:          "qualType": "unsigned int"
// CHECK-NEXT:         }
// CHECK-NEXT:        }
// CHECK-NEXT:       }
// CHECK-NEXT:      ]
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "CXXStaticCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 48
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 38,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 48
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "qualType": "unsigned char"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "NoOp",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 37,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 48
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 37,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 48
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "qualType": "unsigned char"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "IntegralCast",
// CHECK-NEXT:    "isPartOfExplicitCast": true,
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "ImplicitCastExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 37,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 48
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 37,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 48
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "qualType": "int"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "rvalue",
// CHECK-NEXT:      "castKind": "LValueToRValue",
// CHECK-NEXT:      "isPartOfExplicitCast": true,
// CHECK-NEXT:      "inner": [
// CHECK-NEXT:       {
// CHECK-NEXT:        "id": "0x{{.*}}",
// CHECK-NEXT:        "kind": "DeclRefExpr",
// CHECK-NEXT:        "range": {
// CHECK-NEXT:         "begin": {
// CHECK-NEXT:          "col": 37,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 48
// CHECK-NEXT:         },
// CHECK-NEXT:         "end": {
// CHECK-NEXT:          "col": 37,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 48
// CHECK-NEXT:         }
// CHECK-NEXT:        },
// CHECK-NEXT:        "type": {
// CHECK-NEXT:         "qualType": "int"
// CHECK-NEXT:        },
// CHECK-NEXT:        "valueCategory": "lvalue",
// CHECK-NEXT:        "referencedDecl": {
// CHECK-NEXT:         "id": "0x{{.*}}",
// CHECK-NEXT:         "kind": "ParmVarDecl",
// CHECK-NEXT:         "name": "x",
// CHECK-NEXT:         "type": {
// CHECK-NEXT:          "qualType": "int"
// CHECK-NEXT:         }
// CHECK-NEXT:        }
// CHECK-NEXT:       }
// CHECK-NEXT:      ]
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "CXXStaticCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 52
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 36,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 52
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "qualType": "signed char"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "NoOp",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 35,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 52
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 35,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 52
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "qualType": "signed char"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "IntegralCast",
// CHECK-NEXT:    "isPartOfExplicitCast": true,
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "ImplicitCastExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 35,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 52
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 35,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 52
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "qualType": "int"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "rvalue",
// CHECK-NEXT:      "castKind": "LValueToRValue",
// CHECK-NEXT:      "isPartOfExplicitCast": true,
// CHECK-NEXT:      "inner": [
// CHECK-NEXT:       {
// CHECK-NEXT:        "id": "0x{{.*}}",
// CHECK-NEXT:        "kind": "DeclRefExpr",
// CHECK-NEXT:        "range": {
// CHECK-NEXT:         "begin": {
// CHECK-NEXT:          "col": 35,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 52
// CHECK-NEXT:         },
// CHECK-NEXT:         "end": {
// CHECK-NEXT:          "col": 35,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 52
// CHECK-NEXT:         }
// CHECK-NEXT:        },
// CHECK-NEXT:        "type": {
// CHECK-NEXT:         "qualType": "int"
// CHECK-NEXT:        },
// CHECK-NEXT:        "valueCategory": "lvalue",
// CHECK-NEXT:        "referencedDecl": {
// CHECK-NEXT:         "id": "0x{{.*}}",
// CHECK-NEXT:         "kind": "ParmVarDecl",
// CHECK-NEXT:         "name": "x",
// CHECK-NEXT:         "type": {
// CHECK-NEXT:          "qualType": "int"
// CHECK-NEXT:         }
// CHECK-NEXT:        }
// CHECK-NEXT:       }
// CHECK-NEXT:      ]
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "CXXFunctionalCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 63
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 24,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 63
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "desugaredQualType": "unsigned char",
// CHECK-NEXT:   "qualType": "UnsignedChar"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "NoOp",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 23,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 63
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 23,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 63
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "desugaredQualType": "unsigned char",
// CHECK-NEXT:     "qualType": "UnsignedChar"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "IntegralCast",
// CHECK-NEXT:    "isPartOfExplicitCast": true,
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "ImplicitCastExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 23,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 63
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 23,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 63
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "desugaredQualType": "unsigned int",
// CHECK-NEXT:       "qualType": "UnsignedInt"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "rvalue",
// CHECK-NEXT:      "castKind": "LValueToRValue",
// CHECK-NEXT:      "isPartOfExplicitCast": true,
// CHECK-NEXT:      "inner": [
// CHECK-NEXT:       {
// CHECK-NEXT:        "id": "0x{{.*}}",
// CHECK-NEXT:        "kind": "DeclRefExpr",
// CHECK-NEXT:        "range": {
// CHECK-NEXT:         "begin": {
// CHECK-NEXT:          "col": 23,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 63
// CHECK-NEXT:         },
// CHECK-NEXT:         "end": {
// CHECK-NEXT:          "col": 23,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 63
// CHECK-NEXT:         }
// CHECK-NEXT:        },
// CHECK-NEXT:        "type": {
// CHECK-NEXT:         "desugaredQualType": "unsigned int",
// CHECK-NEXT:         "qualType": "UnsignedInt"
// CHECK-NEXT:        },
// CHECK-NEXT:        "valueCategory": "lvalue",
// CHECK-NEXT:        "referencedDecl": {
// CHECK-NEXT:         "id": "0x{{.*}}",
// CHECK-NEXT:         "kind": "ParmVarDecl",
// CHECK-NEXT:         "name": "x",
// CHECK-NEXT:         "type": {
// CHECK-NEXT:          "desugaredQualType": "unsigned int",
// CHECK-NEXT:          "qualType": "UnsignedInt"
// CHECK-NEXT:         }
// CHECK-NEXT:        }
// CHECK-NEXT:       }
// CHECK-NEXT:      ]
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "CXXFunctionalCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 67
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 22,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 67
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "desugaredQualType": "signed char",
// CHECK-NEXT:   "qualType": "SignedChar"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "NoOp",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 21,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 67
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 21,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 67
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "desugaredQualType": "signed char",
// CHECK-NEXT:     "qualType": "SignedChar"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "IntegralCast",
// CHECK-NEXT:    "isPartOfExplicitCast": true,
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "ImplicitCastExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 21,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 67
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 21,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 67
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "desugaredQualType": "unsigned int",
// CHECK-NEXT:       "qualType": "UnsignedInt"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "rvalue",
// CHECK-NEXT:      "castKind": "LValueToRValue",
// CHECK-NEXT:      "isPartOfExplicitCast": true,
// CHECK-NEXT:      "inner": [
// CHECK-NEXT:       {
// CHECK-NEXT:        "id": "0x{{.*}}",
// CHECK-NEXT:        "kind": "DeclRefExpr",
// CHECK-NEXT:        "range": {
// CHECK-NEXT:         "begin": {
// CHECK-NEXT:          "col": 21,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 67
// CHECK-NEXT:         },
// CHECK-NEXT:         "end": {
// CHECK-NEXT:          "col": 21,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 67
// CHECK-NEXT:         }
// CHECK-NEXT:        },
// CHECK-NEXT:        "type": {
// CHECK-NEXT:         "desugaredQualType": "unsigned int",
// CHECK-NEXT:         "qualType": "UnsignedInt"
// CHECK-NEXT:        },
// CHECK-NEXT:        "valueCategory": "lvalue",
// CHECK-NEXT:        "referencedDecl": {
// CHECK-NEXT:         "id": "0x{{.*}}",
// CHECK-NEXT:         "kind": "ParmVarDecl",
// CHECK-NEXT:         "name": "x",
// CHECK-NEXT:         "type": {
// CHECK-NEXT:          "desugaredQualType": "unsigned int",
// CHECK-NEXT:          "qualType": "UnsignedInt"
// CHECK-NEXT:         }
// CHECK-NEXT:        }
// CHECK-NEXT:       }
// CHECK-NEXT:      ]
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "CXXFunctionalCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 71
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 24,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 71
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "desugaredQualType": "unsigned char",
// CHECK-NEXT:   "qualType": "UnsignedChar"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "NoOp",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 23,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 71
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 23,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 71
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "desugaredQualType": "unsigned char",
// CHECK-NEXT:     "qualType": "UnsignedChar"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "IntegralCast",
// CHECK-NEXT:    "isPartOfExplicitCast": true,
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "ImplicitCastExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 23,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 71
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 23,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 71
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "desugaredQualType": "int",
// CHECK-NEXT:       "qualType": "SignedInt"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "rvalue",
// CHECK-NEXT:      "castKind": "LValueToRValue",
// CHECK-NEXT:      "isPartOfExplicitCast": true,
// CHECK-NEXT:      "inner": [
// CHECK-NEXT:       {
// CHECK-NEXT:        "id": "0x{{.*}}",
// CHECK-NEXT:        "kind": "DeclRefExpr",
// CHECK-NEXT:        "range": {
// CHECK-NEXT:         "begin": {
// CHECK-NEXT:          "col": 23,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 71
// CHECK-NEXT:         },
// CHECK-NEXT:         "end": {
// CHECK-NEXT:          "col": 23,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 71
// CHECK-NEXT:         }
// CHECK-NEXT:        },
// CHECK-NEXT:        "type": {
// CHECK-NEXT:         "desugaredQualType": "int",
// CHECK-NEXT:         "qualType": "SignedInt"
// CHECK-NEXT:        },
// CHECK-NEXT:        "valueCategory": "lvalue",
// CHECK-NEXT:        "referencedDecl": {
// CHECK-NEXT:         "id": "0x{{.*}}",
// CHECK-NEXT:         "kind": "ParmVarDecl",
// CHECK-NEXT:         "name": "x",
// CHECK-NEXT:         "type": {
// CHECK-NEXT:          "desugaredQualType": "int",
// CHECK-NEXT:          "qualType": "SignedInt"
// CHECK-NEXT:         }
// CHECK-NEXT:        }
// CHECK-NEXT:       }
// CHECK-NEXT:      ]
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }


// CHECK:  "kind": "CXXFunctionalCastExpr",
// CHECK-NEXT:  "range": {
// CHECK-NEXT:   "begin": {
// CHECK-NEXT:    "col": 10,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 75
// CHECK-NEXT:   },
// CHECK-NEXT:   "end": {
// CHECK-NEXT:    "col": 22,
// CHECK-NEXT:    "file": "{{.*}}",
// CHECK-NEXT:    "line": 75
// CHECK-NEXT:   }
// CHECK-NEXT:  },
// CHECK-NEXT:  "type": {
// CHECK-NEXT:   "desugaredQualType": "signed char",
// CHECK-NEXT:   "qualType": "SignedChar"
// CHECK-NEXT:  },
// CHECK-NEXT:  "valueCategory": "rvalue",
// CHECK-NEXT:  "castKind": "NoOp",
// CHECK-NEXT:  "inner": [
// CHECK-NEXT:   {
// CHECK-NEXT:    "id": "0x{{.*}}",
// CHECK-NEXT:    "kind": "ImplicitCastExpr",
// CHECK-NEXT:    "range": {
// CHECK-NEXT:     "begin": {
// CHECK-NEXT:      "col": 21,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 75
// CHECK-NEXT:     },
// CHECK-NEXT:     "end": {
// CHECK-NEXT:      "col": 21,
// CHECK-NEXT:      "file": "{{.*}}",
// CHECK-NEXT:      "line": 75
// CHECK-NEXT:     }
// CHECK-NEXT:    },
// CHECK-NEXT:    "type": {
// CHECK-NEXT:     "desugaredQualType": "signed char",
// CHECK-NEXT:     "qualType": "SignedChar"
// CHECK-NEXT:    },
// CHECK-NEXT:    "valueCategory": "rvalue",
// CHECK-NEXT:    "castKind": "IntegralCast",
// CHECK-NEXT:    "isPartOfExplicitCast": true,
// CHECK-NEXT:    "inner": [
// CHECK-NEXT:     {
// CHECK-NEXT:      "id": "0x{{.*}}",
// CHECK-NEXT:      "kind": "ImplicitCastExpr",
// CHECK-NEXT:      "range": {
// CHECK-NEXT:       "begin": {
// CHECK-NEXT:        "col": 21,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 75
// CHECK-NEXT:       },
// CHECK-NEXT:       "end": {
// CHECK-NEXT:        "col": 21,
// CHECK-NEXT:        "file": "{{.*}}",
// CHECK-NEXT:        "line": 75
// CHECK-NEXT:       }
// CHECK-NEXT:      },
// CHECK-NEXT:      "type": {
// CHECK-NEXT:       "desugaredQualType": "int",
// CHECK-NEXT:       "qualType": "SignedInt"
// CHECK-NEXT:      },
// CHECK-NEXT:      "valueCategory": "rvalue",
// CHECK-NEXT:      "castKind": "LValueToRValue",
// CHECK-NEXT:      "isPartOfExplicitCast": true,
// CHECK-NEXT:      "inner": [
// CHECK-NEXT:       {
// CHECK-NEXT:        "id": "0x{{.*}}",
// CHECK-NEXT:        "kind": "DeclRefExpr",
// CHECK-NEXT:        "range": {
// CHECK-NEXT:         "begin": {
// CHECK-NEXT:          "col": 21,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 75
// CHECK-NEXT:         },
// CHECK-NEXT:         "end": {
// CHECK-NEXT:          "col": 21,
// CHECK-NEXT:          "file": "{{.*}}",
// CHECK-NEXT:          "line": 75
// CHECK-NEXT:         }
// CHECK-NEXT:        },
// CHECK-NEXT:        "type": {
// CHECK-NEXT:         "desugaredQualType": "int",
// CHECK-NEXT:         "qualType": "SignedInt"
// CHECK-NEXT:        },
// CHECK-NEXT:        "valueCategory": "lvalue",
// CHECK-NEXT:        "referencedDecl": {
// CHECK-NEXT:         "id": "0x{{.*}}",
// CHECK-NEXT:         "kind": "ParmVarDecl",
// CHECK-NEXT:         "name": "x",
// CHECK-NEXT:         "type": {
// CHECK-NEXT:          "desugaredQualType": "int",
// CHECK-NEXT:          "qualType": "SignedInt"
// CHECK-NEXT:         }
// CHECK-NEXT:        }
// CHECK-NEXT:       }
// CHECK-NEXT:      ]
// CHECK-NEXT:     }
// CHECK-NEXT:    ]
// CHECK-NEXT:   }
// CHECK-NEXT:  ]
// CHECK-NEXT: }
