Project {
    QtApplication {
        name : "test-qt"
        files : [ "main.cpp" ]
        Depends { name: "test-lib" }
    }
    DynamicLibrary {
        name : "test-lib"
        Depends { name: "cpp" }
        files: [
            "lib/lib.cpp",
            "lib/lib.h",
        ]
        Export {
            Depends { name: "cpp" }
            cpp.includePaths: [product.sourceDirectory]
        }
    }
}